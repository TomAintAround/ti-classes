// Exercício 3.4

const int BUFFER_SIZE = 100;
char string[BUFFER_SIZE];

const byte mediaSize = 10;

int converterStr(char string[], int tamanho) {
    unsigned long numero = 0;
    unsigned long base10 = 1;

    for (int i = tamanho - 1; i >= 0; i--) {
        char converterChar = string[i];
        if (converterChar >= '0' && converterChar <= '9') numero += (converterChar - 48) * base10;
        else return -1;
        base10 *= 10;
    }

    return numero;
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    byte count = 0;
    unsigned long acum = 0;
    while (count < 10) {
        if (Serial.available() == true) {
            int tamanho = Serial.readBytesUntil('\n', string, 10);
            string[tamanho] = '\0';
            unsigned long numero = converterStr(string, tamanho);
            if (numero != -1) {
                Serial.println(numero);
                acum += numero;
                count++;
            }
        }
    }
    Serial.print("A média é: ");
    Serial.println((float)acum/10);
}
