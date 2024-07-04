#include <Servo.h> // Include the Servo library

// Create servo objects for the two servos
Servo myservo1;
Servo myservo2;

// Define input pins for channels
#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9

// Define output pins for motor control
#define Rm1 4
#define Rm2 7
#define Lm1 8
#define Lm2 12

// Variables to store channel values
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value;

void setup() {
  // Initialize serial communication at 115200 bps
  Serial.begin(115200);
  
  // Set channel pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
  
  // Set motor control pins as outputs
  pinMode(Rm1, OUTPUT);
  pinMode(Rm2, OUTPUT);
  pinMode(Lm1, OUTPUT);
  pinMode(Lm2, OUTPUT);
  
  // Attach the servos to their respective pins
  myservo1.attach(10);
  myservo2.attach(11);
}

void loop() {
  // Read values from the channels
  ch2Value = readChannel(CH2);
  ch1Value = readChannel(CH1);
  ch4Value = readChannel(CH4);
  ch3Value = readChannel(CH3);

  // Motor control
  if (ch2Value > 30) {  // Forward
    digitalWrite(Rm1, LOW);
    digitalWrite(Rm2, HIGH);
    digitalWrite(Lm1, LOW);
    digitalWrite(Lm2, HIGH);
    Serial.println("forward");
  } else if (ch2Value < -30) {  // Backward
    digitalWrite(Rm1, HIGH);
    digitalWrite(Rm2, LOW);
    digitalWrite(Lm1, HIGH);
    digitalWrite(Lm2, LOW);
    Serial.println("backward");
  } else if (ch1Value > 30) {  // Right
    digitalWrite(Rm1, HIGH);
    digitalWrite(Rm2, LOW);
    digitalWrite(Lm1, LOW);
    digitalWrite(Lm2, HIGH);
    Serial.println("right");
  } else if (ch1Value < -30) {  // Left
    digitalWrite(Rm1, LOW);
    digitalWrite(Rm2, HIGH);
    digitalWrite(Lm1, HIGH);
    digitalWrite(Lm2, LOW);
    Serial.println("left");
  } else {  // Stop
    digitalWrite(Rm1, LOW);
    digitalWrite(Rm2, LOW);
    digitalWrite(Lm1, LOW);
    digitalWrite(Lm2, LOW);
  }

  // Servo control for the arm movement
  if (ch4Value > 10) {
    myservo1.write(180); // Move to position 180 degrees
  } else if (ch4Value < -10) {
    myservo1.write(0); // Move to position 0 degrees
  } else {
    myservo1.write(90); // Center position
  }

  // Servo control for the claw clenching
  if (ch3Value > 10) {
    myservo2.write(180); // Move to position 180 degrees
  } else if (ch3Value < -10) {
    myservo2.write(0); // Move to position 0 degrees
  } else {
    myservo2.write(90); // Center position
  }
}


