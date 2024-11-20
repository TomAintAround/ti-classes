// Exercício 3.1

const int nums[] = { 180, 22, 45, 55, 65, 70, 80, 85, 90, 95, 100, 105, 110, 115, 120, 130, 135, 140, 150, 10 };
int min = 0;
int max = 0;
float media = 0;

void estatistica() {
    for (byte i = 0; i < sizeof(nums)/sizeof(int); i++) {
        media += nums[i];
        if (nums[i] < min) min = nums[i];
        if (nums[i] > max) max = nums[i];
    }
    media = media / (sizeof(nums)/sizeof(int));

    Serial.print("Media: ");
    Serial.println(media);
    Serial.print("Minimo: ");
    Serial.println(min);
    Serial.print("Máximo: ");
    Serial.println(max);
}

void setup() {
    Serial.begin(9600);
    estatistica();
}

void loop() {}