// Pin Definitions
const int leftIrPin = 2;
const int rightIrPin = 3;

const int motorL_Fwd = 9;
const int motorL_Bwd = 8;
const int motorR_Fwd = 11;
const int motorR_Bwd = 10;

void setup() {
  // Sensor Inputs
  pinMode(leftIrPin, INPUT);
  pinMode(rightIrPin, INPUT);

  // Motor Driver Outputs
  pinMode(motorL_Fwd, OUTPUT);
  pinMode(motorL_Bwd, OUTPUT);
  pinMode(motorR_Fwd, OUTPUT);
  pinMode(motorR_Bwd, OUTPUT);
  
  Serial.begin(9600); // For debugging in simulation
}

void loop() {
  int leftState = digitalRead(leftIrPin);
  int rightState = digitalRead(rightIrPin);

  // Motion Logic Implementation
  if (leftState == HIGH && rightState == HIGH) {
    moveForward();
  } 
  else if (leftState == LOW && rightState == HIGH) {
    turnLeft();
  } 
  else if (leftState == HIGH && rightState == LOW) {
    turnRight();
  } 
  else {
    stopRobot();
  }
}

// Movement Functions
void moveForward() {
  digitalWrite(motorL_Fwd, HIGH);
  digitalWrite(motorL_Bwd, LOW);
  digitalWrite(motorR_Fwd, HIGH);
  digitalWrite(motorR_Bwd, LOW);
}

void turnLeft() {
  // To turn left, stop left motor or move it backward
  digitalWrite(motorL_Fwd, LOW);
  digitalWrite(motorL_Bwd, LOW);
  digitalWrite(motorR_Fwd, HIGH);
  digitalWrite(motorR_Bwd, LOW);
}

void turnRight() {
  digitalWrite(motorL_Fwd, HIGH);
  digitalWrite(motorL_Bwd, LOW);
  digitalWrite(motorR_Fwd, LOW);
  digitalWrite(motorR_Bwd, LOW);
}

void stopRobot() {
  digitalWrite(motorL_Fwd, LOW);
  digitalWrite(motorL_Bwd, LOW);
  digitalWrite(motorR_Fwd, LOW);
  digitalWrite(motorR_Bwd, LOW);
}
