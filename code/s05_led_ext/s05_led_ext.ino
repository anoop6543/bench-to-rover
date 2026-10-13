/* S05 External LED blink
 * Docs: docs/scenarios/s05/setup.md
 * Wiring: docs/scenarios/s05/wiring.md
 * Tests: docs/scenarios/s05/tests.md
 * Nav: S04 <- S05 -> S06
 * Upload: scripts/upload-uno.ps1 -Sketch code/s05_led_ext
 *
 * Uno D8 -- 330 ohm -- LED(+) -- LED(-) -- GND
 * Same idea as S00, but the LED is on the breadboard.
 */

const uint8_t PIN_LED = 8;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_LED, LOW);
  delay(500);
}
