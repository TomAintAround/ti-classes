// Exercício 2.9

byte largura_base = 30;

void setup() {
  Serial.begin(9600);
  
  if (largura_base % 2 == 0) largura_base++;
  
  for (byte row = 1; row <= largura_base; row += 2) {
    for (byte space = 0; space < (largura_base - row) / 2; space++) Serial.print(" ");
    for (byte symbol = 1; symbol <= row; symbol++) {
      Serial.print("*");
    }
    Serial.println("");
  }
}
  
void loop() {}
