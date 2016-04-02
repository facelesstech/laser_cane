#include <NewPing.h> // Load newping library

#define TRIGGER_PIN 2 // Trigger pin
#define ECHO_PIN 3 // Echo pin
#define MAX_DISTANCE 125 // Maximum distance
int pager = 5; // Motor pin
unsigned long millisDelay; // Used for a delay inbetween reading the ultrasonic sensor
unsigned long motorLevel; // Used for the PWM of the motor

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Start serial on 9600
  pinMode(pager, OUTPUT); // Motor pin
}

void loop() {
  while (millis() >= millisDelay) // Used instead of a delay
  {
    Serial.print("Ping: "); // Print to serial
    Serial.print(sonar.ping_cm()); // Print to serial ping in CM
    Serial.println("cm"); // Print to serial

  if (sonar.ping_cm() == 0) // When out of range turn motor off
  {
    analogWrite(pager, 0); // Turn motor off
  }

  else // When in range run code
  {
    motorLevel = map(sonar.ping_cm(), 0, 125,255, 100); // Maps distance to motor PWM
    Serial.println(motorLevel); // Print to serial
    analogWrite(pager, motorLevel); // Run motor
  }
    millisDelay += 100; // Adds to the time for the delay
  }

}
