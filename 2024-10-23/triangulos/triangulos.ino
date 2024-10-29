// Exercício 2.9

byte largura = 1
byte largura_base = 30;
byte ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  largura_base += !(largura_base % 2);
}

void triangulos(largura) {
  for (byte row = 1; row <= largura; row += 2) {
    for (byte space = 0; space < (largura - row) / 2; space++) Serial.print(" ");
    for (byte symbol = 1; symbol <= row; symbol++) {
      Serial.print("*");
    }
    Serial.println("");
  }
}
  
void loop() {
  triangulos(largura);
  digitalWrite(ledPin13, HIGH);
  largura = (largura + 1) % (largura_base + 1);
}
