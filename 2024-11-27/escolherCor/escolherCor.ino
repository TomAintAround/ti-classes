// Materiais: breadboard, led RGB, 3 resistores 220 ohms, 4 fios

byte leds[3] = {11, 10, 9};
size_t quantidadeLeds = sizeof(leds)/sizeof(byte);
byte ledAtivo = 0;

void setup() {
    Serial.begin(9600);
    for (byte i = 0; i < quantidadeLeds; i++) {
        pinMode(leds[i], OUTPUT);
        analogWrite(leds[i], 255);
    }
}

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('+\n');

        if ((input[0] == 'R') || (input[0] == 'r')) {
            ledAtivo = leds[0];
        } else if ((input[0] == 'G') || (input[0] == 'g')) {
            ledAtivo = leds[1];
        } else if ((input[0] == 'B') || (input[0] == 'b')) {
            ledAtivo = leds[2];
        } else if ((input.toInt() < 256) && (input.toInt() >= 0)) {
            analogWrite(ledAtivo, 255 - input.toInt());
            delay(5000);
            analogWrite(ledAtivo, 255);
        } else Serial.println("Input inválido");
    }
}