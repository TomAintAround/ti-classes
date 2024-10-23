// Materiais: 8 220 ohm resistores, breaboad, 8 leds, fios
// Exercício 1.9

byte contador = 0;

void ligarLED() {
  for (byte pin = 6; pin <= 13; pin++) {
    byte algarismoOn = (contador >> (pin - 6)) & 1;
    digitalWrite(pin, algarismoOn);
  }
}

void setup() {
  Serial.begin(9600);

  for (byte pin = 6; pin <= 13; pin++) pinMode(pin, OUTPUT);
}

void loop() {
  ligarLED();
  Serial.println(contador);

  contador++;
  delay(500);
}
