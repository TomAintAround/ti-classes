// Exercício 2.2

int numeros[3] = {5, 8, 10};

void setup() {
  Serial.begin(9600);

  for (byte i = 0; i < 3; i++) {
	byte value = numeros[i] & (numeros[i] - 1);
	
	Serial.print(numeros[i]);
	if (value == 0) {
	  Serial.println(" é potência de base 2.");
	} else {
	  Serial.println(" não é potência de base 2.");
	}
  }
}

void loop() {}
