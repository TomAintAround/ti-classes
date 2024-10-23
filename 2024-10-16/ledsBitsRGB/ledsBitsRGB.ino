// Materiais: 11 220 ohm resistores, breaboad, 8 leds, 1 led RGB, fios
// Exercício 2.5

byte contador = 0;
byte minLed = 2;
byte maxLed = 9;
byte minRGB = 11;
byte maxRGB = 13;

void ligarLED() {
  for (byte pinLed = minLed; pinLed <= maxLed; pinLed++) {
    byte algarismoOn = (contador >> (pinLed - minLed)) & 1;
    digitalWrite(pinLed, algarismoOn);
  }

  for (byte pinRGB = maxRGB; pinRGB >= minRGB; pinRGB--) {
    bool maxCor = contador <= 300 - (100 * (pinRGB - 11));
    bool minCor = contador > 0 - (100 * (pinRGB - 13));
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
