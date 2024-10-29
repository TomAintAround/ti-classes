// Exercício 2.9

byte largura = 1;
byte largura_base = 9;
byte ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  largura_base += !(largura_base % 2);
  
  for (largura; largura <= largura_base; largura += 2) {
    triangulo(largura);
    largura = (largura + 1) % (largura_base + 1);
  }

  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
}

void triangulo(byte largura) {
  for (byte row = 1; row <= largura; row += 2) {
    for (byte space = 0; space < (largura - row) / 2; space++) Serial.print(" ");
    for (byte symbol = 1; symbol <= row; symbol++) {
      Serial.print("*");
    }
    Serial.println("");
  }
}

void loop() {}
