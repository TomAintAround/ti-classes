// Materiais: broadboard, botão, fios

byte leftButton = 7;
byte rightButton = 6;
long ellapsed = 0;

void setup() {
	Serial.begin(9600);
	pinMode(leftButton, INPUT_PULLUP);
	pinMode(rightButton, INPUT_PULLUP);
}

void loop() {
	if (millis() - ellapsed > 100) {
		bool left = !digitalRead(leftButton);
		bool right = !digitalRead(rightButton);

		if (left && right) Serial.println("X");
		else if (left) Serial.println("L");
		else if (right) Serial.println("R");

		ellapsed = millis();
	}
}
