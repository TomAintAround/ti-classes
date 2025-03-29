// Materiais: 11 220 ohm resistores, breaboad, 8 leds, 1 led RGB, fios
// Exercício 2.5

byte contador = 0;
byte minLed = 2;
byte maxLed = 4;
byte buttonPin = 7;
bool reading = LOW;
bool lastButtonState = LOW;
byte debounceDelay = 50;
long lastDebounceTime = 0;

void ligarLED() {
  Serial.println(contador);
  for (byte pinLed = minLed; pinLed <= maxLed; pinLed++) {
	byte algarismoOn = (contador >> (pinLed - minLed)) & 1;
	digitalWrite(pinLed, algarismoOn);
  }
}

void setup() {
  Serial.begin(9600);

  for (byte pin = minLed; pin <= maxLed; pin++) pinMode(pin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool buttonState = !digitalRead(buttonPin);

  if (buttonState != lastButtonState) lastDebounceTime = millis();

  if (millis() - lastDebounceTime > debounceDelay) {
	if (reading != buttonState) {
	  reading = buttonState;
	  if (reading == HIGH) {
		ligarLED();
		contador = (contador + 1) % 8;
	  }
	}
  }

  if (millis() - lastDebounceTime > 2000) {
	contador = 0;
	ligarLED();
  }

  lastButtonState = buttonState;
}
