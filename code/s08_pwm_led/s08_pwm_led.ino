/* S08 LED brightness PWM (+ joystick fun)
 * Docs: docs/scenarios/s08/setup.md
 * Wiring: docs/scenarios/s08/wiring.md
 * Tests: docs/scenarios/s08/tests.md
 * Nav: S07 <- S08 -> S09
 * Upload: scripts/upload-uno.ps1 -Sketch code/s08_pwm_led
 *
 * D9 -- 330R -- LED -- GND
 * Optional (S03 still up): pack X -> A0, 3.3V, GND
 *
 * Serial: PWM:0..255  LED:0|1  MODE:0 slider-priority  MODE:1 joy-only
 * Stick left/right moves brightness; dashboard slider still works in MODE:0
 * when stick is near center.
 */

const uint8_t PIN_LED = 9;
const uint8_t PIN_X = A0;
const int DEAD = 60;

uint8_t pwm = 64;
uint8_t mode = 0;  // 0 = joy when off-center else serial, 1 = joy always
int cx = 512;
unsigned long lastReport = 0;
unsigned long lastSerialPwm = 0;

void applyPwm() {
  analogWrite(PIN_LED, pwm);
}

void calibrateX() {
  long s = 0;
  for (int i = 0; i < 16; i++) {
    s += analogRead(PIN_X);
    delay(4);
  }
  cx = (int)(s / 16);
}

void handleSerial() {
  static char buf[24];
  static uint8_t n = 0;
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      buf[n] = 0;
      if (strncmp(buf, "PWM:", 4) == 0) {
        int v = atoi(buf + 4);
        if (v < 0) v = 0;
        if (v > 255) v = 255;
        pwm = (uint8_t)v;
        applyPwm();
        lastSerialPwm = millis();
      } else if (strncmp(buf, "LED:", 4) == 0) {
        pwm = atoi(buf + 4) ? 255 : 0;
        applyPwm();
        lastSerialPwm = millis();
      } else if (strncmp(buf, "MODE:", 5) == 0) {
        int m = atoi(buf + 5);
        if (m == 0 || m == 1) mode = (uint8_t)m;
      } else if (strcmp(buf, "CAL") == 0) {
        calibrateX();
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
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  delay(30);
  calibrateX();
  applyPwm();
}

void loop() {
  handleSerial();

  int x = analogRead(PIN_X);
  int dx = x - cx;
  bool joyActive = (mode == 1) || (abs(dx) > DEAD);
  // Don't fight a fresh slider drag
  bool serialRecent = (millis() - lastSerialPwm) < 400;

  if (joyActive && !serialRecent) {
    int v = map(constrain(x, 0, 1023), 0, 1023, 0, 255);
    if ((uint8_t)v != pwm) {
      pwm = (uint8_t)v;
      applyPwm();
    }
  }

  unsigned long now = millis();
  if (now - lastReport >= 80) {
    lastReport = now;
    Serial.print(F("{\"pwm\":"));
    Serial.print(pwm);
    Serial.print(F(",\"x\":"));
    Serial.print(x);
    Serial.print(F(",\"mode\":"));
    Serial.print(mode);
    Serial.print(F(",\"joy\":"));
    Serial.print(joyActive ? 1 : 0);
    Serial.println('}');
  }
}
