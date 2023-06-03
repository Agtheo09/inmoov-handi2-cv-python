#include <Servo.h>//Import Servo Lib

//Declare all Finger Servos
Servo thumbFingerServo;
Servo indexFingerServo;
Servo middleFingerServo;
Servo ringFingerServo;
Servo littleFingerServo;

String valueFromSerial = "";//Variable that contains serial's value taken
int allFingPos[5] = {0, 0, 0, 0, 0};//Fingers' Position Variable

int calcServoPos(int serialCode) {
  return (serialCode == 49) ? 180 : 0;
}

void setup() {
  //Attach each Servo into Ports
  thumbFingerServo.attach(A0);
  indexFingerServo.attach(A1);
  middleFingerServo.attach(A2);
  ringFingerServo.attach(A3);
  littleFingerServo.attach(A4);

  //Setup Serial
  Serial.begin(9600);
  Serial.setTimeout(1);
}

void loop() {
  while (!Serial.available());//Wait for the send of a command
  delay(10);//Delay to avoid loop bugs
  valueFromSerial = Serial.readString();//Read value from Serial

  //Save the value to an array
  for (int i = 0; i < 5; i++) {
    allFingPos[i] = valueFromSerial[i];
  }

  //Set the position of each Servo
  thumbFingerServo.write(calcServoPos(allFingPos[0]));
  indexFingerServo.write(calcServoPos(allFingPos[1]));
  middleFingerServo.write(calcServoPos(allFingPos[2]));
  ringFingerServo.write(calcServoPos(allFingPos[3]));
  littleFingerServo.write(calcServoPos(allFingPos[4]));
}
