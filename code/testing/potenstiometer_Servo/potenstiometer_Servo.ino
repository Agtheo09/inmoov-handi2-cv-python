#include <Servo.h>

Servo myservo;

int value;
double servoValue;
int threshold = 2;

void setup() {
  myservo.attach(3);
  Serial.begin(9600);
}

boolean inRange(double a, int b, int c) {
  return a <= c && a >= b;
}

void loop() {
  value = analogRead(A0);
  Serial.println(value);
  servoValue = map(value, 0, 675, 0, 180);
  myservo.write(servoValue);
//  while(!inRange(myservo.read(), servoValue-threshold, servoValue+threshold)) delay(40);
  delay(50);
}
