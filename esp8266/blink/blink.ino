const int led = D0;
int dt = 1000;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(dt);
  digitalWrite(led, LOW);
  delay(dt);
}
