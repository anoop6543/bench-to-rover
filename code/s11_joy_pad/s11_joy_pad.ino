/* S11 Joystick as mouse pad
 * Docs: docs/scenarios/s11/setup.md
 * Wiring: docs/scenarios/s11/wiring.md (= S03 six jumpers)
 * Tests: docs/scenarios/s11/tests.md
 * Nav: S10 <- S11 -> S12
 * Upload: scripts/upload-uno.ps1 -Sketch code/s11_joy_pad
 *
 * Stick deflection = mouse velocity. Cursor walks across a virtual pad.
 * Click = select. CAL recenters ADC; HOME snaps cursor to mid-pad.
 */

const uint8_t PIN_X = A0;
const uint8_t PIN_Y = A1;
const uint8_t PIN_SEL = 2;

const int DEAD = 80;
const float GAIN = 0.045f;  // ADC offset → cursor step per sample

int adcCx = 512;
int adcCy = 512;
float cursorX = 512.0f;
float cursorY = 512.0f;
uint16_t clicks = 0;
uint8_t prevSel = 0;

void calibrateCenter() {
  long sx = 0, sy = 0;
  for (int i = 0; i < 24; i++) {
    sx += analogRead(PIN_X);
    sy += analogRead(PIN_Y);
    delay(5);
  }
  adcCx = (int)(sx / 24);
  adcCy = (int)(sy / 24);
}

void homeCursor() {
  cursorX = 512.0f;
  cursorY = 512.0f;
}

void handleSerial() {
  static char buf[24];
  static uint8_t n = 0;
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      buf[n] = 0;
      if (strcmp(buf, "CAL") == 0) calibrateCenter();
      else if (strcmp(buf, "HOME") == 0) homeCursor();
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
  homeCursor();
}

void loop() {
  handleSerial();

  int x = analogRead(PIN_X);
  int y = analogRead(PIN_Y);
  uint8_t sel = digitalRead(PIN_SEL) == LOW ? 1 : 0;

  if (sel && !prevSel) clicks++;
  prevSel = sel;
  digitalWrite(LED_BUILTIN, sel ? HIGH : LOW);

  int nx = x - adcCx;
  int ny = adcCy - y;  // +ny = stick toward top of pack
  int mag = (int)sqrt((long)nx * nx + (long)ny * ny);

  if (mag >= DEAD) {
    cursorX += (float)nx * GAIN;
    cursorY += (float)ny * GAIN;
    if (cursorX < 0) cursorX = 0;
    if (cursorX > 1023) cursorX = 1023;
    if (cursorY < 0) cursorY = 0;
    if (cursorY > 1023) cursorY = 1023;
  }

  int cx = (int)(cursorX + 0.5f);
  int cy = (int)(cursorY + 0.5f);

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
  Serial.print(F(",\"cursor\":["));
  Serial.print(cx);
  Serial.print(',');
  Serial.print(cy);
  Serial.print(F("],\"clicks\":"));
  Serial.print(clicks);
  Serial.print(F(",\"cx\":"));
  Serial.print(adcCx);
  Serial.print(F(",\"cy\":"));
  Serial.print(adcCy);
  Serial.println('}');
  delay(25);
}
