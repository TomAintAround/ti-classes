// Materiais: 4 220 ohm resistores, 4 leds, breadboard, botão
// Exercício 2.10

long numero = 213452345;
byte minLed = 2;
byte maxLed = 5;

void setup() {
  for (byte pin = minLed; pin <= maxLed; pin++) pinMode(pin, OUTPUT);
  Serial.begin(9600);

  for (byte nibble = 0); nibble < 8; nibble++) {
  }
}

void loop() {}
