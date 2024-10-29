// Exercício 2.11

char number = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    number = Serial.read();

    if (number - '0' >= 0 && number - '0' <= 9) {
      Serial.print("I have received (ASCII): ");
      Serial.println(number, DEC);
      Serial.print("I have received (CHAR): ");
      Serial.println(number);
    }
  }
}
