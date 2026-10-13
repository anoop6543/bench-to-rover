/* S02 USB self-test vitals
 * Docs: docs/scenarios/s02/setup.md
 * Wiring: docs/scenarios/s02/wiring.md
 * Tests: docs/scenarios/s02/tests.md
 * Nav: S01 <- S02 -> S03
 * Upload: scripts/upload-uno.ps1 -Sketch code/s02_selftest
 */

/*
 * No extra wiring: USB-only Uno self-test.
 * Streams Vcc (bandgap), rough die temp, free SRAM, uptime, floating A0,
 * and a short EEPROM note.
 *
 * Commands (newline-terminated):
 *   LED:0 / LED:1
 *   MSG:your text     (max 48 chars, stored in EEPROM)
 */

#include <EEPROM.h>

const uint8_t MSG_MAX = 48;
const int MSG_ADDR = 0;

uint8_t ledOn = 0;
char eepromMsg[MSG_MAX + 1];
String rxLine;

int freeSram() {
  extern int __heap_start, *__brkval;
  int v;
  return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

long readVccMv() {
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2);
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA, ADSC)) {
  }
  uint16_t adc = ADC;
  if (adc == 0) {
    return 0;
  }
  return 1125300L / adc;
}

int readDieTempC() {
  ADMUX = _BV(REFS1) | _BV(REFS0) | _BV(MUX3);
  delay(5);
  ADCSRA |= _BV(ADSC);
  while (bit_is_set(ADCSRA, ADSC)) {
  }
  int raw = ADC;
  return (int)((raw - 324.31) / 1.22);
}

void loadMsg() {
  uint8_t n = EEPROM.read(MSG_ADDR);
  if (n > MSG_MAX) {
    n = 0;
  }
  for (uint8_t i = 0; i < n; i++) {
    char ch = (char)EEPROM.read(MSG_ADDR + 1 + i);
    if (ch < 32 || ch > 126) {
      ch = '?';
    }
    eepromMsg[i] = ch;
  }
  eepromMsg[n] = 0;
}

void saveMsg(const String &text) {
  uint8_t n = (uint8_t)min((int)MSG_MAX, (int)text.length());
  EEPROM.update(MSG_ADDR, n);
  for (uint8_t i = 0; i < n; i++) {
    char ch = text.charAt(i);
    if (ch < 32 || ch > 126) {
      ch = ' ';
    }
    EEPROM.update(MSG_ADDR + 1 + i, (uint8_t)ch);
    eepromMsg[i] = ch;
  }
  eepromMsg[n] = 0;
}

void applyLine(String line) {
  line.trim();
  if (line.startsWith("LED:")) {
    ledOn = line.substring(4).toInt() ? 1 : 0;
    digitalWrite(LED_BUILTIN, ledOn ? HIGH : LOW);
    return;
  }
  if (line.startsWith("MSG:")) {
    saveMsg(line.substring(4));
  }
}

void pollSerial() {
  while (Serial.available() > 0) {
    char ch = (char)Serial.read();
    if (ch == '\n' || ch == '\r') {
      if (rxLine.length() > 0) {
        applyLine(rxLine);
        rxLine = "";
      }
    } else if (rxLine.length() < 64) {
      rxLine += ch;
    } else {
      rxLine = "";
    }
  }
}

void printJson() {
  long vcc = readVccMv();
  int tempC = readDieTempC();
  int a0 = analogRead(A0);

  Serial.print(F("{\"vcc_mv\":"));
  Serial.print(vcc);
  Serial.print(F(",\"temp_c\":"));
  Serial.print(tempC);
  Serial.print(F(",\"sram\":"));
  Serial.print(freeSram());
  Serial.print(F(",\"uptime_ms\":"));
  Serial.print(millis());
  Serial.print(F(",\"a0\":"));
  Serial.print(a0);
  Serial.print(F(",\"led\":"));
  Serial.print(ledOn);
  Serial.print(F(",\"msg\":\""));
  for (char *p = eepromMsg; *p; p++) {
    Serial.write(*p);
  }
  Serial.println(F("\"}"));
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  loadMsg();
}

void loop() {
  pollSerial();
  static unsigned long last = 0;
  unsigned long now = millis();
  if (now - last >= 250) {
    last = now;
    printJson();
  }
}
