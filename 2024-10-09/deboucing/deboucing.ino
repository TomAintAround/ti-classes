// Materiais: 2 leds, butão, fios, breadboard, 2 220 ohm resistores
// Exercício 1.7

int ledPin = 13;
int buttonPin = 7;
int counter = 0;
int reading = HIGH;
int lastButtonState = HIGH;
int debounceDelay = 50;
long lastDebounceTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      reading = buttonState;
      if (reading == LOW) {
        counter++;
        Serial.println(counter);
      }

      if (counter % 3 == 0 && reading == LOW) {
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
      }
    }
  }

  lastButtonState = buttonState;
}
