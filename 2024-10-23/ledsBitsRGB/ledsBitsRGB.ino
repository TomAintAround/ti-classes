// Materiais: 11 220 ohm resistores, breaboad, 8 leds, 1 led RGB, fios
// Exercício 2.5

byte contador = 0;
byte minLed = 6;
byte maxLed = 13;
byte minRGB = 3;
byte maxRGB = 5;

void ligarLED() {
  for (byte pinLed = minLed; pinLed <= maxLed; pinLed++) {
    byte algarismoOn = (contador >> (pinLed - minLed)) & 1;
    digitalWrite(pinLed, algarismoOn);
  }

  for (byte pinRGB = minRGB; pinRGB <= maxRGB; pinRGB++) {
    bool maxCor = contador <= 300 - (100 * (maxRGB - pinRGB));
    bool minCor = contador > ~(100 * (minRGB - pinRGB)) + 1;
    bool seletorCores = minCor && maxCor;
    digitalWrite(pinRGB, seletorCores);
  }
}

void setup() {
  Serial.begin(9600);

  for (byte pinLed = minLed; pinLed <= maxLed; pinLed++) pinMode(pinLed, OUTPUT);
  for (byte pinRGB = minRGB; pinRGB <= maxRGB; pinRGB++) pinMode(pinRGB, OUTPUT);
}

void loop() {
  Serial.println(contador);
  ligarLED();
  contador++;
  delay(100);
}
