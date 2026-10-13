/* S06 Two-LED heartbeat (funny edition)
 * Docs: docs/scenarios/s06/setup.md
 * Wiring: docs/scenarios/s06/wiring.md
 * Tests: docs/scenarios/s06/tests.md
 * Nav: S05 <- S06 -> S07
 * Upload: scripts/upload-uno.ps1 -Sketch code/s06_two_led
 *
 * D8 -- 330R -- LED A -- GND
 * D9 -- 330R -- LED B -- GND
 */

const uint8_t PIN_A = 8;
const uint8_t PIN_B = 9;

void both(uint8_t a, uint8_t b) {
  digitalWrite(PIN_A, a);
  digitalWrite(PIN_B, b);
}

void lubDub(uint8_t pin) {
  digitalWrite(pin, HIGH);
  delay(70);
  digitalWrite(pin, LOW);
  delay(70);
  digitalWrite(pin, HIGH);
  delay(70);
  digitalWrite(pin, LOW);
  delay(350);
}

void setup() {
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
}

void loop() {
  // 1) polite alternate
  for (int i = 0; i < 4; i++) {
    both(HIGH, LOW);
    delay(180);
    both(LOW, HIGH);
    delay(180);
  }

  // 2) medical-ish lub-dub, one LED then the other
  lubDub(PIN_A);
  lubDub(PIN_B);

  // 3) panic disco (speed ramp)
  for (int d = 200; d >= 40; d -= 20) {
    both(HIGH, LOW);
    delay(d);
    both(LOW, HIGH);
    delay(d);
  }

  // 4) high-five: both on, both off
  both(HIGH, HIGH);
  delay(250);
  both(LOW, LOW);
  delay(400);
}
