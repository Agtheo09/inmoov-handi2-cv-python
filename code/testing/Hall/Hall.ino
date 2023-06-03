const int sensorPin = A0; // Analog input pin for the sensor
int sensorValue; // Variable to store the sensor reading

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the analog value from the sensor
  sensorValue = analogRead(sensorPin);

  // Print the raw analog value
  Serial.print("Raw Sensor Value: ");
  Serial.println(sensorValue);

  // Add any additional processing or calibration here

  delay(20); // Delay for stability, adjust as needed
}
