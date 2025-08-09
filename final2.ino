#include <Servo.h>

// Pins
const int mq135Pin = A0;     // Air quality sensor
const int trigPin = 2;       // Ultrasonic trigger
const int echoPin = 3;       // Ultrasonic echo
const int redLED = 5;        // Red LED
const int greenLED = 6;      // Green LED
const int servoPin = 9;      // Servo

// Thresholds
const int airBadThreshold = 300;   // Higher = worse air
const int personNearThreshold = 30; // cm

Servo monkArm;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  monkArm.attach(servoPin);
  monkArm.write(90); // Neutral

  Serial.println("Passive Aggressive Monk starting...");
}

void loop() {
  int airValue = analogRead(mq135Pin);
  int distance = getDistance();

  Serial.print("Air Quality: ");
  Serial.print(airValue);
  Serial.print(" | Distance: ");
  Serial.println(distance);

  if (airValue < airBadThreshold && distance > personNearThreshold) {
    // Peaceful
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    monkArm.write(90); // still
    Serial.println("Peace surrounds me.");
  }
  else if (airValue >= airBadThreshold && distance > personNearThreshold) {
    // Bad air
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    slowWave();
    Serial.println("Toxic thoughts... and air.");
  }
  else if (distance <= personNearThreshold && airValue < airBadThreshold) {
    // Close person, good air
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    bow();
    Serial.println("Namaste, stinky soul.");
  }
  else {
    // Bad air + person close
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    fastWave();
    Serial.println("You must leave this place. 💀");
  }

  delay(2000);
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void slowWave() {
  monkArm.write(60);
  delay(500);
  monkArm.write(120);
  delay(500);
  monkArm.write(90);
}

void fastWave() {
  monkArm.write(60);
  delay(200);
  monkArm.write(120);
  delay(200);
  monkArm.write(90);
}

void bow() {
  monkArm.write(70);
  delay(300);
  monkArm.write(110);
  delay(300);
  monkArm.write(90);
}
