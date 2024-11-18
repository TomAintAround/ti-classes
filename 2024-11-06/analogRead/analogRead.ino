// Materiais: breadboard, joystick, fios

byte xPin = A0;
byte yPin = A1;
byte joystickPress = 7;

void setup() {
    Serial.begin(9600);
    pinMode(joystickPress, INPUT);
}

void loop() {
    int xCoord = analogRead(xPin);
    int yCoord = analogRead(yPin);
    bool pressed = digitalRead(joystickPress);
    
    Serial.print("x: ");
    Serial.print(xCoord);
    Serial.print(" | ");
    Serial.print("y: ");
    Serial.print(yCoord);
    Serial.print(" | ");
    Serial.print("PRESS: ");
    Serial.println(pressed);
}
