/* S09 Transistor as switch
 * Docs: docs/scenarios/s09/setup.md
 * Wiring: docs/scenarios/s09/wiring.md
 * Tests: docs/scenarios/s09/tests.md
 * Nav: S08 <- S09 -> S10
 * Upload: scripts/upload-uno.ps1 -Sketch code/s09_transistor
 *
 * D8 -- 10k -- Base
 * 5V -- 330R -- LED(+) -- LED(-) -- Collector
 * Emitter -- GND
 *
 * Onboard L (D13) blinks in sync with D8 so you can tell firmware vs wiring.
 */

const uint8_t PIN_BASE = 8;

void setup() {
  pinMode(PIN_BASE, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(PIN_BASE, HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(PIN_BASE, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
