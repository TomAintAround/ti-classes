void setup() {
	Serial.begin(9600);
}

void loop() {
	if (Serial.available() > 0) {
		String input = Serial.readStringUntil('\n');
		paridade(input);
	}
}

void paridade(String input) {
	for (byte i = 0; i < input.length(); i++) {
		if (!(isdigit(input[i]))) {
			Serial.println("Insire um número");
			return;
		}
	}

	byte numero = input.toInt();
	if (numero > 0b1111111 || numero < 0) Serial.print("Input inválido: ");
	else if (numero & 1) Serial.print("É ímpar: ");
	else Serial.print("É par: ");
	Serial.println(numero, BIN);
}
