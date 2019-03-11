

//setup for distance
int trigPin = 8; 
int echoPin = 7;
int motorPinL = 3;
int motorPinR = 3;
long duration;

//calculates the distance to nearest object (George and Laura)
void distance(){ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  int distanceCm= duration*0.034/2;
 
  Serial.println (distanceCm);
  delay(100);
}
//sets both motors to go at a set speed (Laura and George)
void forwards(int speed){
analogWrite(motorPinL, speed);
analogWrite(motorPinR, speed);

}
// goes Left and right (Laura and George)
void left(int speed){
analogWrite(motorPinL, speed);  
}

void right(){
analogWrite(motorPinR, speed);  
}
// setting up all the pins on the arduino 
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPinL, OUTPUT);
  pinMode(motorPinR, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
