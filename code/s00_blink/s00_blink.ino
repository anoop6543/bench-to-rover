/* S00 Blink onboard L LED
 * Docs: docs/scenarios/s00/setup.md
 * Wiring: docs/scenarios/s00/wiring.md
 * Tests: docs/scenarios/s00/tests.md
 * Nav: — <- S00 -> S01
 * Upload: scripts/upload-uno.ps1 -Sketch code/s00_blink
 */

/* Built-in LED on Uno pin 13. No extra wiring. */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}
