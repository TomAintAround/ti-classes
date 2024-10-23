// Materiais: 4 220 ohm resistores, 4 leds, breadboard
// Exercício 2.10

long numero = 456787654;
byte minLed = 2;
byte maxLed = 5;

void setup() {
  for (byte pin = minLed; pin <= maxLed; pin++) pinMode(pin, OUTPUT);
  Serial.begin(9600);

  Serial.println(numero, BIN);

  for (byte nibble = 0; nibble < 8; nibble++) {
    byte nibbleLED = (numero >> (4 * nibble)) & 0xF;
    for (byte dislocator = 0; dislocator < 4; dislocator++) {
      byte selectedLED = minLed + dislocator;
      bool algarismoON = (nibbleLED >> dislocator) & 1;
      digitalWrite(selectedLED, algarismoON);
    }
    delay(1000);
  }
}

void loop() {}
