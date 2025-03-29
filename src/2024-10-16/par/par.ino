int contador = 0;

int check_even(int numero) {
  return numero % 2 == 0;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(contador);
  Serial.print(" ");
  Serial.println(check_even(contador));
  contador++;
  delay(500);
}
