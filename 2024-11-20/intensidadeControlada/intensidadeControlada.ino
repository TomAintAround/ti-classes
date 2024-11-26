// Exercício 4.1
// Materiais: breaboard, 8 fios, 1 potenciómetro, 1 led, 1 resistor 220 ohms

const byte ledPin = 3;
const byte pinPotenciometro = A0;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    int leituraPotenciometro = analogRead(pinPotenciometro);
    float potencia = (255.0 / 1023.0) * leituraPotenciometro;
    Serial.println(potencia);
    analogWrite(ledPin, potencia);
}
