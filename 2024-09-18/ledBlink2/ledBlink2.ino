int led = 10;
int maxTime = 2000;
int time = maxTime;
int maxCount = 7;
int count = maxCount;

void setup() {
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(time);
  digitalWrite(led, LOW);
  delay(time);

  time = time - (time / 2);
  count = count - 1;

  if (count == 0) {
    time = maxTime;
    count = maxCount;
  }
}