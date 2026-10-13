/* S03 Joystick sketch + wiring (same 6 Duponts)
 * Docs: docs/scenarios/s03/setup.md
 * Wiring: docs/scenarios/s03/wiring.md
 * Tests: docs/scenarios/s03/tests.md
 * Nav: S02 <- S03 -> S04
 * Upload: scripts/upload-uno.ps1 -Sketch code/s03_joystick
 *
 * Sub-routines (no new wires):
 *   MODE:0  click lights L (default)
 *   MODE:1  L blink rate = stick magnitude
 *   MODE:2  click toggles latch (L follows latch)
 *   MODE:3  L on only when outside deadzone
 *   CAL     re-sample idle center for deadzone
 */

const uint8_t PIN_X = A0;
const uint8_t PIN_Y = A1;
const uint8_t PIN_SEL = 2;

const int DEAD = 80;  // ADC counts from calibrated center

int cx = 512;
int cy = 512;
uint8_t mode = 0;
uint8_t latched = 0;
uint16_t clicks = 0;
uint8_t prevSel = 0;
unsigned long lastBlink = 0;
uint8_t blinkOn = 0;

void calibrateCenter() {
  long sx = 0, sy = 0;
  for (int i = 0; i < 24; i++) {
    sx += analogRead(PIN_X);
    sy += analogRead(PIN_Y);
    delay(5);
  }
  cx = (int)(sx / 24);
  cy = (int)(sy / 24);
}

const char *octant(int nx, int ny, int mag) {
  if (mag < DEAD) return "C";
  // atan2-ish via dominant axis; Y up when stick toward top of pack
  if (abs(nx) * 2 < abs(ny)) return (ny > 0) ? "N" : "S";
  if (abs(ny) * 2 < abs(nx)) return (nx > 0) ? "E" : "W";
  if (nx > 0 && ny > 0) return "NE";
  if (nx > 0 && ny < 0) return "SE";
  if (nx < 0 && ny > 0) return "NW";
  return "SW";
}

void handleSerial() {
  static char buf[24];
  static uint8_t n = 0;
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      buf[n] = 0;
      if (strncmp(buf, "MODE:", 5) == 0) {
        int m = atoi(buf + 5);
        if (m >= 0 && m <= 3) mode = (uint8_t)m;
      } else if (strcmp(buf, "CAL") == 0) {
        calibrateCenter();
      }
      n = 0;
    } else if (n < sizeof(buf) - 1) {
      buf[n++] = c;
    } else {
      n = 0;
    }
  }
}

void setup() {
  pinMode(PIN_SEL, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(50);
  calibrateCenter();
}

void loop() {
  handleSerial();

  int x = analogRead(PIN_X);
  int y = analogRead(PIN_Y);
  uint8_t sel = digitalRead(PIN_SEL) == LOW ? 1 : 0;

  if (sel && !prevSel) {
    clicks++;
    if (mode == 2) latched ^= 1;
  }
  prevSel = sel;

  int nx = x - cx;
  int ny = cy - y;  // flip so +ny = stick toward N on pad UI
  int mag = (int)sqrt((long)nx * nx + (long)ny * ny);
  const char *dir = octant(nx, ny, mag);

  // LED behavior by mode
  unsigned long now = millis();
  switch (mode) {
    case 1: {
      int period = mag < DEAD ? 0 : map(constrain(mag, DEAD, 500), DEAD, 500, 400, 40);
      if (period == 0) {
        digitalWrite(LED_BUILTIN, LOW);
        blinkOn = 0;
      } else if (now - lastBlink >= (unsigned long)period) {
        lastBlink = now;
        blinkOn ^= 1;
        digitalWrite(LED_BUILTIN, blinkOn ? HIGH : LOW);
      }
      break;
    }
    case 2:
      digitalWrite(LED_BUILTIN, latched ? HIGH : LOW);
      break;
    case 3:
      digitalWrite(LED_BUILTIN, mag >= DEAD ? HIGH : LOW);
      break;
    default:
      digitalWrite(LED_BUILTIN, sel ? HIGH : LOW);
      break;
  }

  Serial.print(F("{\"joy\":["));
  Serial.print(x);
  Serial.print(',');
  Serial.print(y);
  Serial.print(',');
  Serial.print(sel);
  Serial.print(F("],\"nx\":"));
  Serial.print(nx);
  Serial.print(F(",\"ny\":"));
  Serial.print(ny);
  Serial.print(F(",\"mag\":"));
  Serial.print(mag);
  Serial.print(F(",\"dir\":\""));
  Serial.print(dir);
  Serial.print(F("\",\"mode\":"));
  Serial.print(mode);
  Serial.print(F(",\"latched\":"));
  Serial.print(latched);
  Serial.print(F(",\"clicks\":"));
  Serial.print(clicks);
  Serial.print(F(",\"cx\":"));
  Serial.print(cx);
  Serial.print(F(",\"cy\":"));
  Serial.print(cy);
  Serial.println('}');
  delay(40);
}
