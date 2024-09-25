// Materials: breadboard, button, hook-up wires, 10k ohm resistor,
 led

const int buttonPin = 10;
const int ledPin = 13;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    Serial.println("ON");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("OFF");
    digitalWrite(ledPin, LOW);
  }
}
