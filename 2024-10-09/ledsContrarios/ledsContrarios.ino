// Materiais: 2 leds, butão, fios, breadboard, 2 220 ohm resistores
// Exercício 1.6

int ledPin1 = 13;
int ledPin2 = 12;
int buttonPin = 7;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  digitalWrite(ledPin1, buttonState);
  digitalWrite(ledPin2, !buttonState);
}
