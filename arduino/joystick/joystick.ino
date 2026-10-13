/*
 * BOOSTXL-EDUMKII joystick only. No Raspberry Pi required.
 *
 * Jumpers:
 *   Pack GND  -> Uno GND
 *   Pack 3.3V -> Uno 3.3V
 *   Pack 5V   -> Uno 5V
 *   J1.2  X   -> A0
 *   J3.26 Y   -> A1
 *   J1.5  SEL -> D2 (press = LOW)
 *
 * Do not plug the pack onto the Uno or the Vilros cobbler.
 */

const uint8_t PIN_X = A0;
const uint8_t PIN_Y = A1;
const uint8_t PIN_SEL = 2;

void setup() {
  pinMode(PIN_SEL, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int x = analogRead(PIN_X);
  int y = analogRead(PIN_Y);
  int sel = digitalRead(PIN_SEL) == LOW ? 1 : 0;
  digitalWrite(LED_BUILTIN, sel ? HIGH : LOW);

  Serial.print(F("{\"joy\":["));
  Serial.print(x);
  Serial.print(',');
  Serial.print(y);
  Serial.print(',');
  Serial.print(sel);
  Serial.println(F("]}"));
  delay(50);
}
