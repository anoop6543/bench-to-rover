/* S07 Button toggles LED
 * Docs: docs/scenarios/s07/setup.md
 * Wiring: docs/scenarios/s07/wiring.md
 * Tests: docs/scenarios/s07/tests.md
 * Nav: S06 <- S07 -> S08
 * Upload: scripts/upload-uno.ps1 -Sketch code/s07_button_led
 *
 * D8 -- 330R -- LED -- GND
 * D7 -- button -- GND   (INPUT_PULLUP: press = LOW)
 *
 * Serial JSON for dashboard: {"btn":0|1,"led":0|1,"raw":0|1}
 */

const uint8_t PIN_LED = 8;
const uint8_t PIN_BTN = 7;
const unsigned long DEBOUNCE_MS = 40;

uint8_t ledOn = 0;
uint8_t prevStable = HIGH;
uint8_t lastRead = HIGH;
unsigned long lastChange = 0;
unsigned long lastReport = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BTN, INPUT_PULLUP);
  digitalWrite(PIN_LED, LOW);
  Serial.begin(115200);
}

void loop() {
  uint8_t reading = digitalRead(PIN_BTN);
  unsigned long now = millis();

  if (reading != lastRead) {
    lastChange = now;
    lastRead = reading;
  }

  if ((now - lastChange) > DEBOUNCE_MS && reading != prevStable) {
    prevStable = reading;
    if (prevStable == LOW) {
      ledOn ^= 1;
      digitalWrite(PIN_LED, ledOn ? HIGH : LOW);
    }
  }

  if (now - lastReport >= 50) {
    lastReport = now;
    // btn=1 means pressed (active low inverted for humans)
    Serial.print(F("{\"btn\":"));
    Serial.print(prevStable == LOW ? 1 : 0);
    Serial.print(F(",\"led\":"));
    Serial.print(ledOn);
    Serial.print(F(",\"raw\":"));
    Serial.print(reading);  // 1=open/HIGH, 0=pressed/LOW
    Serial.println('}');
  }
}
