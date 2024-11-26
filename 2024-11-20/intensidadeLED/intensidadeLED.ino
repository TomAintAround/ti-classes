// Exercício 3.5
// Materiais: breaboard, 4 fios, 1 LED RGB, 3 resistores 220 ohms

const byte leds[3] = {9, 10, 11};
const byte quantidadeLeds = sizeof(leds)/sizeof(byte);
byte intensidade = 255;

void setup() {
    for (byte led = 0; led < quantidadeLeds; led++) pinMode(leds[led], OUTPUT);
}

void loop() {
    for (byte led = 0; led < quantidadeLeds; led++) {
        while (intensidade >= 0) {
            analogWrite(leds[led], intensidade);
            delay(3);
            intensidade--;
        }
        while (intensidade < 256) {
            intensidade++;
            analogWrite(leds[led], intensidade);
            delay(3);
        }
    }
}