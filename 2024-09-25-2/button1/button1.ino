// Materiais: breadboard, butão, fios, 10k ohm resistor, led

const int buttonPin = 7;
const int ledPin = 13;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  Serial.println(buttonState);
  digitalWrite(ledPin, buttonState);
}
