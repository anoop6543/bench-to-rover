/* S10 Serial Morse
 * Docs: docs/scenarios/s10/setup.md
 * Wiring: docs/scenarios/s10/wiring.md
 * Tests: docs/scenarios/s10/tests.md
 * Nav: S09 <- S10 -> S11
 * Upload: scripts/upload-uno.ps1 -Sketch code/s10_morse
 *
 * Reuses S09 bench: D8 -- 10k -- Base; 5V -- 330R -- LED -- C; E -- GND.
 * Onboard L (D13) mirrors D8.
 *
 * Serial Monitor 115200: type a line (e.g. SOS) and press Enter.
 */

const uint8_t PIN_LED = 8;
const uint16_t UNIT_MS = 120;

// '.' = dit, '-' = dah. Index 0='A' … 25='Z'; then '0'…'9' at 26…35.
const char *const MORSE[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..",
  "-----", ".----", "..---", "...--", "....-", ".....",
  "-....", "--...", "---..", "----."
};

void ledWrite(uint8_t level) {
  digitalWrite(PIN_LED, level);
  digitalWrite(LED_BUILTIN, level);
}

void flash(uint16_t onMs) {
  ledWrite(HIGH);
  delay(onMs);
  ledWrite(LOW);
}

void sendElement(char el) {
  if (el == '.') {
    flash(UNIT_MS);
  } else if (el == '-') {
    flash(3 * UNIT_MS);
  }
  delay(UNIT_MS);  // gap between elements
}

void sendLetter(char c) {
  int idx = -1;
  if (c >= 'a' && c <= 'z') c = c - 'a' + 'A';
  if (c >= 'A' && c <= 'Z') idx = c - 'A';
  else if (c >= '0' && c <= '9') idx = 26 + (c - '0');
  else if (c == ' ') {
    delay(4 * UNIT_MS);  // word gap is 7 units; letter gap already 3 → add 4
    return;
  } else {
    return;  // skip punctuation
  }

  const char *code = MORSE[idx];
  for (const char *p = code; *p; p++) {
    sendElement(*p);
  }
  delay(2 * UNIT_MS);  // letter gap: already 1 after last element → +2 = 3
}

void sendMessage(const char *msg) {
  Serial.print(F("TX: "));
  Serial.println(msg);
  for (const char *p = msg; *p; p++) {
    sendLetter(*p);
  }
  Serial.println(F("done"));
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  ledWrite(LOW);
  Serial.begin(115200);
  while (!Serial) { /* USB CDC wait; Uno returns immediately */ }
  Serial.println(F("S10 Morse — type text, Enter to send (A-Z 0-9 space)"));
}

void loop() {
  static char buf[64];
  static uint8_t len = 0;

  while (Serial.available() > 0) {
    char c = (char)Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      buf[len] = '\0';
      if (len > 0) sendMessage(buf);
      len = 0;
      continue;
    }
    if (len + 1 < sizeof(buf)) {
      buf[len++] = c;
    }
  }
}
