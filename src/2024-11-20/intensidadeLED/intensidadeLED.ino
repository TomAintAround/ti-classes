// Materiais: breaboard, 4 fios, 1 LED RGB, 3 resistores 220 ohms

const byte leds[3] = {9, 10, 11};
const size_t quantidadeLeds = sizeof(leds)/sizeof(byte);
byte intensidade = 0;

void setup() {
	Serial.begin(9600);
	for (byte led = 0; led < quantidadeLeds; led++) {
		pinMode(leds[led], OUTPUT);
		analogWrite(leds[led], 255);
	}
}

void loop() {
	for (int led = quantidadeLeds - 1; led >= 0; led--) {
		while (intensidade < 255) {
			analogWrite(leds[led], 255 - intensidade);
			delay(3);
			intensidade++;
		}
		while (intensidade > 0) {
			analogWrite(leds[led], 255 - intensidade);
			delay(3);
			intensidade--;
		}
	}
}
