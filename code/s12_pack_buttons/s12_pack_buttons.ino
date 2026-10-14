/* S12 Pack buttons S1 / S2
 * Docs: docs/scenarios/s12/setup.md
 * Wiring: docs/scenarios/s12/wiring.md
 * Tests: docs/scenarios/s12/tests.md
 * Nav: S11 <- S12 -> S13
 * Upload: scripts/upload-uno.ps1 -Sketch code/s12_pack_buttons
 *
 * Keep S03 six jumpers. Add:
 *   S1 J4.33 -> D3
 *   S2 J4.32 -> D4
 * Active LOW (INPUT_PULLUP). Onboard L follows S1.
 */

const uint8_t PIN_S1 = 3;
const uint8_t PIN_S2 = 4;
const uint8_t PIN_JOY_SEL = 2;

uint16_t countS1 = 0;
uint16_t countS2 = 0;
uint8_t prevS1 = 0;
uint8_t prevS2 = 0;

void setup() {
  pinMode(PIN_S1, INPUT_PULLUP);
  pinMode(PIN_S2, INPUT_PULLUP);
  pinMode(PIN_JOY_SEL, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  delay(50);
}

void loop() {
  uint8_t s1 = digitalRead(PIN_S1) == LOW ? 1 : 0;
  uint8_t s2 = digitalRead(PIN_S2) == LOW ? 1 : 0;
  uint8_t sel = digitalRead(PIN_JOY_SEL) == LOW ? 1 : 0;

  if (s1 && !prevS1) countS1++;
  if (s2 && !prevS2) countS2++;
  prevS1 = s1;
  prevS2 = s2;

  digitalWrite(LED_BUILTIN, s1 ? HIGH : LOW);

  Serial.print(F("{\"btn\":["));
  Serial.print(s1);
  Serial.print(',');
  Serial.print(s2);
  Serial.print(F("],\"counts\":["));
  Serial.print(countS1);
  Serial.print(',');
  Serial.print(countS2);
  Serial.print(F("],\"sel\":"));
  Serial.print(sel);
  Serial.println('}');
  delay(40);
}
