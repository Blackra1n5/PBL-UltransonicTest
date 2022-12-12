// defines pins numbers
const int trigPinL = 9;
const int echoPinL = 10;
const int trigPinR = 11;
const int echoPinR = 12;
// defines variables
long duration;
int distanceL;
int distanceR;
void setup() {
  pinMode(trigPinL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinL, INPUT); // Sets the echoPin as an Input
  pinMode(trigPinR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinR, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  //-----LEFT
  // Clears the trigPin
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPinL, HIGH);
  // Calculating the distance
  distanceL = duration * 0.034 / 2;
  Serial.print("DistanceL: ");
  Serial.print(distanceL);
  Serial.println(" cm");
  
  //-----RIGHT
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinR, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPinR, HIGH);
  distanceR = duration * 0.034 / 2;
  
  Serial.print("DistanceR: ");
  Serial.print(distanceR);
  Serial.println(" cm");

  if (distanceL > distanceR) {
    Serial.println("Ball is on the Left");
  }
  else if (distanceR > distanceL) {
    Serial.println("Ball is on the Right");
  }
  else if (distanceL == distanceR) {
    Serial.println("Ball is in the Middle");
  }
  else {
    Serial.println("LOGIC ERROR!");
  }

}
