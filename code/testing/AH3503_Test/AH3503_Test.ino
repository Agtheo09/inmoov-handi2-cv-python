void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(3);
  Serial.println(value);
}
