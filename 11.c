// Ultrasonic Distance Sensor with 5 LEDs
// Sensor: HC-SR04

// HC-SR04 pins
int trigPin = 9;
int echoPin = 10;

// LED pins
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

// Variables
long duration;
long distance;

void setup() {
  // Ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  // Serial Monitor
  Serial.begin(9600);
}

void loop() {

  // Make sure Trigger is LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure Echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in centimeters
  distance = (duration / 2) / 29.154;

  // Display distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Turn OFF all LEDs first
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);

  // Distance-based LED indication

  if (distance <= 50) {
    // 0 - 50 cm
    digitalWrite(led1, HIGH);
  }

  else if (distance <= 100) {
    // 51 - 100 cm
    digitalWrite(led2, HIGH);
  }

  else if (distance <= 150) {
    // 101 - 150 cm
    digitalWrite(led3, HIGH);
  }

  else if (distance <= 200) {
    // 151 - 200 cm
    digitalWrite(led4, HIGH);
  }

  else if (distance <= 250) {
    // 201 - 250 cm
    digitalWrite(led5, HIGH);
  }

  else {
    // More than 250 cm
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  }

  // Small delay before next measurement
  delay(50);
}
