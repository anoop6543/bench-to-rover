/*
 * USB JSON bridge for Arduino Uno R3 + BOOSTXL-EDUMKII analog subset.
 *
 * Upload from Windows with the Uno on COM4, 115200 baud.
 * Same sketch works later on the Pi at /dev/ttyACM0.
 *
 * Unwired analog pins read as noise/0 — that is expected for Phase 1.
 * Do not enable EXTERNAL AREF until AREF is jumpered to 3.3V.
 *
 * Incoming lines (newline-terminated):
 *   RGB:r,g,b          0-255 each
 *   BEEP:freq,ms       e.g. BEEP:880,150
 */

const uint8_t PIN_JOY_X = A0;
const uint8_t PIN_JOY_Y = A1;
const uint8_t PIN_JOY_SEL = 2;
const uint8_t PIN_ACCEL_X = A2;
const uint8_t PIN_ACCEL_Y = A3;
const uint8_t PIN_ACCEL_Z = A4;
const uint8_t PIN_MIC = A5;
const uint8_t PIN_BTN_S1 = 3;
const uint8_t PIN_BTN_S2 = 4;
const uint8_t PIN_BUZZ = 5;
const uint8_t PIN_LED_R = 9;
const uint8_t PIN_LED_G = 10;
const uint8_t PIN_LED_B = 11;

const unsigned long SAMPLE_MS = 100;

uint8_t ledR = 0;
uint8_t ledG = 0;
uint8_t ledB = 0;

String rxLine;

void applyRgb() {
  analogWrite(PIN_LED_R, ledR);
  analogWrite(PIN_LED_G, ledG);
  analogWrite(PIN_LED_B, ledB);
}

void setup() {
  Serial.begin(115200);

  pinMode(PIN_JOY_SEL, INPUT_PULLUP);
  pinMode(PIN_BTN_S1, INPUT_PULLUP);
  pinMode(PIN_BTN_S2, INPUT_PULLUP);
  pinMode(PIN_BUZZ, OUTPUT);
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  applyRgb();
}

void handleLine(String line) {
  line.trim();
  if (line.length() == 0) {
    return;
  }

  if (line.startsWith("RGB:")) {
    int c1 = line.indexOf(',', 4);
    int c2 = line.indexOf(',', c1 + 1);
    if (c1 < 0 || c2 < 0) {
      return;
    }
    ledR = (uint8_t)constrain(line.substring(4, c1).toInt(), 0, 255);
    ledG = (uint8_t)constrain(line.substring(c1 + 1, c2).toInt(), 0, 255);
    ledB = (uint8_t)constrain(line.substring(c2 + 1).toInt(), 0, 255);
    applyRgb();
    return;
  }

  if (line.startsWith("BEEP:")) {
    int c1 = line.indexOf(',', 5);
    if (c1 < 0) {
      return;
    }
    unsigned int freq = (unsigned int)constrain(line.substring(5, c1).toInt(), 50, 4000);
    unsigned long ms = (unsigned long)constrain(line.substring(c1 + 1).toInt(), 10, 1000);
    /* tone() uses Timer2, which also drives PWM on D11 (blue). Restore RGB after. */
    tone(PIN_BUZZ, freq, ms);
    delay(ms);
    noTone(PIN_BUZZ);
    applyRgb();
  }
}

void pollSerial() {
  while (Serial.available() > 0) {
    char ch = (char)Serial.read();
    if (ch == '\n' || ch == '\r') {
      if (rxLine.length() > 0) {
        handleLine(rxLine);
        rxLine = "";
      }
    } else if (rxLine.length() < 64) {
      rxLine += ch;
    } else {
      rxLine = "";
    }
  }
}

void loop() {
  pollSerial();

  static unsigned long lastSample = 0;
  unsigned long now = millis();
  if (now - lastSample < SAMPLE_MS) {
    return;
  }
  lastSample = now;

  int joyX = analogRead(PIN_JOY_X);
  int joyY = analogRead(PIN_JOY_Y);
  int sel = digitalRead(PIN_JOY_SEL) == LOW ? 1 : 0;
  int ax = analogRead(PIN_ACCEL_X);
  int ay = analogRead(PIN_ACCEL_Y);
  int az = analogRead(PIN_ACCEL_Z);
  int mic = analogRead(PIN_MIC);
  int s1 = digitalRead(PIN_BTN_S1) == LOW ? 1 : 0;
  int s2 = digitalRead(PIN_BTN_S2) == LOW ? 1 : 0;

  Serial.print(F("{\"joy\":["));
  Serial.print(joyX);
  Serial.print(',');
  Serial.print(joyY);
  Serial.print(',');
  Serial.print(sel);
  Serial.print(F("],\"accel\":["));
  Serial.print(ax);
  Serial.print(',');
  Serial.print(ay);
  Serial.print(',');
  Serial.print(az);
  Serial.print(F("],\"btn\":["));
  Serial.print(s1);
  Serial.print(',');
  Serial.print(s2);
  Serial.print(F("],\"mic\":"));
  Serial.print(mic);
  Serial.println('}');
}
