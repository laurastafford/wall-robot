

//setup for distance
int trigPin = 8; 
int echoPin = 7;
int motorPinL = 3;
int motorPinR = 3;
long duration;

//calculates the distance to nearest object 
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

void forwards(int speed){
analogWrite(motorPinL, speed);
analogWrite(motorPinR, speed);

}

void left(int speed){
analogWrite(motorPinL, speed);  
}

void right(){
analogWrite(motorPinR, speed);  
}

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
