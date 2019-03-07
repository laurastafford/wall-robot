//setup for dyepper
#include <Stepper.h>
const int SPR = 200; //amount of steps of motor
Stepper left(SPR, 2, 3, 4, 5);
Stepper right(SPR, 6, 7, 8, 9);
int stepCount = 0; // how far the step has gone

//setup for distance
int trigPin = 8; 
int echoPin = 7;
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

void forwards(int steps,int rpm){
left.setSpeed(rpm);
right.setSpeed(rpm);
left.step(steps);
right.step(steps);

}
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
