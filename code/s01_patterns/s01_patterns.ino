/* S01 15 LED patterns + dashboard
 * Docs: docs/scenarios/s01/setup.md
 * Wiring: docs/scenarios/s01/wiring.md
 * Tests: docs/scenarios/s01/tests.md
 * Nav: S00 <- S01 -> S02
 * Upload: scripts/upload-uno.ps1 -Sketch code/s01_patterns
 */

/*
 * 15 onboard-LED patterns (Uno LED_BUILTIN / pin 13). No extra I/O.
 * Serial 115200. Commands: P:<0-14>  or  P:sos
 * Status JSON about 5 Hz: {"pattern":8,"name":"sos","led":1}
 */

struct Seg {
  uint8_t level;
  uint16_t ms;
};

const Seg P0[] = {{0, 500}};
const Seg P1[] = {{1, 80}, {0, 80}, {1, 80}, {0, 640}};
const Seg P2[] = {{1, 500}, {0, 500}};
const Seg P3[] = {{1, 70}, {0, 70}};
const Seg P4[] = {{1, 850}, {0, 150}};
const Seg P5[] = {{1, 120}, {0, 120}, {1, 120}, {0, 120}, {1, 120}, {0, 800}};
const Seg P6[] = {{1, 160}, {0, 160}, {1, 160}, {0, 720}};
const Seg P7[] = {
    {1, 60}, {0, 60}, {1, 60}, {0, 60}, {1, 60}, {0, 60}, {1, 60}, {0, 60}, {1, 60}, {0, 700}};
const Seg P8[] = {
    {1, 150}, {0, 150}, {1, 150}, {0, 150}, {1, 150}, {0, 450},
    {1, 450}, {0, 150}, {1, 450}, {0, 150}, {1, 450}, {0, 450},
    {1, 150}, {0, 150}, {1, 150}, {0, 150}, {1, 150}, {0, 1050}};
const Seg P9[] = {{1, 40}, {0, 1960}};
const Seg P10[] = {{1, 200}, {0, 100}, {1, 200}, {0, 700}};
const Seg P11[] = {{1, 700}, {0, 700}};
const Seg P12[] = {{1, 80}, {0, 80}, {1, 80}, {0, 80}, {1, 220}, {0, 640}};
const Seg P13[] = {
    {1, 100}, {0, 450},
    {1, 100}, {0, 100}, {1, 100}, {0, 450},
    {1, 100}, {0, 100}, {1, 100}, {0, 100}, {1, 100}, {0, 450},
    {1, 100}, {0, 100}, {1, 100}, {0, 100}, {1, 100}, {0, 100}, {1, 100}, {0, 900}};
const Seg P14[] = {{1, 50}, {0, 50}};

const Seg *const PATS[] = {P0, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14};
const uint8_t PAT_LEN[] = {
    sizeof(P0) / sizeof(Seg),  sizeof(P1) / sizeof(Seg),  sizeof(P2) / sizeof(Seg),
    sizeof(P3) / sizeof(Seg),  sizeof(P4) / sizeof(Seg),  sizeof(P5) / sizeof(Seg),
    sizeof(P6) / sizeof(Seg),  sizeof(P7) / sizeof(Seg),  sizeof(P8) / sizeof(Seg),
    sizeof(P9) / sizeof(Seg),  sizeof(P10) / sizeof(Seg), sizeof(P11) / sizeof(Seg),
    sizeof(P12) / sizeof(Seg), sizeof(P13) / sizeof(Seg), sizeof(P14) / sizeof(Seg)};
const char *const PAT_NAME[] = {
    "off",     "heartbeat", "ready",   "working", "waiting", "success", "warning", "fault",
    "sos",     "sleep",     "linked",  "dropped", "knock",   "tally",   "alarm"};

const uint8_t PAT_COUNT = 15;

uint8_t current = 0;
uint8_t step = 0;
uint8_t led = 0;
unsigned long stepAt = 0;
String rxLine;

int nameToId(const String &n) {
  for (uint8_t i = 0; i < PAT_COUNT; i++) {
    if (n.equalsIgnoreCase(PAT_NAME[i])) {
      return i;
    }
  }
  return -1;
}

void setPattern(uint8_t id) {
  if (id >= PAT_COUNT) {
    return;
  }
  current = id;
  step = 0;
  stepAt = millis();
  led = PATS[id][0].level;
  digitalWrite(LED_BUILTIN, led ? HIGH : LOW);
}

void applyLine(String line) {
  line.trim();
  if (!line.startsWith("P:")) {
    return;
  }
  String rest = line.substring(2);
  rest.trim();
  if (rest.length() == 0) {
    return;
  }
  if (isDigit(rest.charAt(0))) {
    int id = rest.toInt();
    if (id >= 0 && id < PAT_COUNT) {
      setPattern((uint8_t)id);
    }
    return;
  }
  int id = nameToId(rest);
  if (id >= 0) {
    setPattern((uint8_t)id);
  }
}

void pollSerial() {
  while (Serial.available() > 0) {
    char ch = (char)Serial.read();
    if (ch == '\n' || ch == '\r') {
      if (rxLine.length() > 0) {
        applyLine(rxLine);
        rxLine = "";
      }
    } else if (rxLine.length() < 32) {
      rxLine += ch;
    } else {
      rxLine = "";
    }
  }
}

void runPattern() {
  const Seg *seq = PATS[current];
  uint8_t len = PAT_LEN[current];
  unsigned long now = millis();
  if (now - stepAt < seq[step].ms) {
    return;
  }
  stepAt = now;
  step++;
  if (step >= len) {
    step = 0;
  }
  led = seq[step].level;
  digitalWrite(LED_BUILTIN, led ? HIGH : LOW);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  setPattern(2);
}

void loop() {
  pollSerial();
  runPattern();

  static unsigned long lastTx = 0;
  unsigned long now = millis();
  if (now - lastTx >= 200) {
    lastTx = now;
    Serial.print(F("{\"pattern\":"));
    Serial.print(current);
    Serial.print(F(",\"name\":\""));
    Serial.print(PAT_NAME[current]);
    Serial.print(F("\",\"led\":"));
    Serial.print(led);
    Serial.println('}');
  }
}
