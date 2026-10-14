/* S13 Tilt accelerometer
 * Docs: docs/scenarios/s13/setup.md
 * Wiring: docs/scenarios/s13/wiring.md
 * Tests: docs/scenarios/s13/tests.md
 * Nav: S12 <- S13 -> S14
 * Upload: scripts/upload-uno.ps1 -Sketch code/s13_tilt
 *
 * Keep S03 power + (optional) joy. Add:
 *   Accel X J3.23 -> A2
 *   Accel Y J3.24 -> A3
 *   Accel Z J3.25 -> A4
 *
 * Pack accel is 3.3 V analog; Uno AREF stays 5 V → raw ~0–675.
 * CAL with pack flat on the desk. Serial: CAL
 */

const uint8_t PIN_AX = A2;
const uint8_t PIN_AY = A3;
const uint8_t PIN_AZ = A4;

int cx = 337;
int cy = 337;
int cz = 450;  // ~1g on Z when flat (rough default until CAL)

void calibrateFlat() {
  long sx = 0, sy = 0, sz = 0;
  for (int i = 0; i < 32; i++) {
    sx += analogRead(PIN_AX);
    sy += analogRead(PIN_AY);
    sz += analogRead(PIN_AZ);
    delay(5);
  }
  cx = (int)(sx / 32);
  cy = (int)(sy / 32);
  cz = (int)(sz / 32);
}

void handleSerial() {
  static char buf[16];
  static uint8_t n = 0;
  while (Serial.available()) {
    char c = (char)Serial.read();
    if (c == '\r') continue;
    if (c == '\n') {
      buf[n] = 0;
      if (strcmp(buf, "CAL") == 0) calibrateFlat();
      n = 0;
    } else if (n < sizeof(buf) - 1) {
      buf[n++] = c;
    } else {
      n = 0;
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(50);
  calibrateFlat();
}

void loop() {
  handleSerial();

  int ax = analogRead(PIN_AX);
  int ay = analogRead(PIN_AY);
  int az = analogRead(PIN_AZ);

  int nx = ax - cx;
  int ny = cy - ay;  // flip so +ny feels like tip toward top of pack UI
  int nz = az - cz;

  Serial.print(F("{\"accel\":["));
  Serial.print(ax);
  Serial.print(',');
  Serial.print(ay);
  Serial.print(',');
  Serial.print(az);
  Serial.print(F("],\"nx\":"));
  Serial.print(nx);
  Serial.print(F(",\"ny\":"));
  Serial.print(ny);
  Serial.print(F(",\"nz\":"));
  Serial.print(nz);
  Serial.print(F(",\"cx\":"));
  Serial.print(cx);
  Serial.print(F(",\"cy\":"));
  Serial.print(cy);
  Serial.print(F(",\"cz\":"));
  Serial.print(cz);
  Serial.println('}');
  delay(40);
}
