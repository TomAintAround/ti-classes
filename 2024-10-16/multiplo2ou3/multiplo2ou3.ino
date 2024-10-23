// Materiais: 2 leds, fios, breadboard, 2 220 ohm resistores
// Exercício 1.10

byte ledPin1 = 12;
byte ledPin2 = 13;
int counter = 200;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  counter++;

    digitalWrite(ledPin1, (counter % 2 == 0));
    digitalWrite(ledPin2, (counter % 3 == 0));

  if (counter == 400) counter = 200;

  Serial.println(counter);

  if (counter % 2 == 0 || counter % 3 == 0) delay(1000);
}
