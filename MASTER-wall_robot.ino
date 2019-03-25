//servo setup
#include <Servo.h>
Servo myservo;  

//lcd setup
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 1, d6 = 10, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//pins for LCD screen are 12, 11, 5, 4, 10 & 2

 

//setup for pins
int pos = 0; 
int trigPin = 8; 
int echoPin = 7;
int motorPinL = 3;
int motorPinR = 4;
int servoPin = 9;
long duration;

//calculates the distance to nearest object (George and Laura)
long distance(){ 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  long distanceCm= duration*0.034/2;
 
  Serial.println (distanceCm);
  delay(100);
  return distanceCm;
}

//sensor servo move(Evan and Jordan) 
void servo(int angle) {
//  for (pos = 0; pos <= angle; pos += 1) { 
    myservo.write(angle);              
    delay(15);                      
  //}
//  for (pos = angle; pos >= 0; pos -= 1) { 
  //  myservo.write(pos);            
    //delay(15);                     
  //}
}

//sets both motors to go at a set speed (Laura and George)
void forwards(){
digitalWrite(motorPinL, HIGH);
digitalWrite(motorPinR, HIGH);

}

//The LCD screen will need to be cleared, 
//as it will continously print and look wrong &
//without the delay it will instantally clear
//(jack and issac)
void Lcd(int text) {
    lcd.setCursor(0, 0);
  //sets where the message will be printed
  lcd.print(text);
  //Prints a message to the LCD screen
  delay(500);
  lcd.clear();
}

// goes Left and right (Laura and George)
void left(){
digitalWrite(motorPinL,HIGH);  
digitalWrite(motorPinR,LOW); 
}

void right(){
digitalWrite(motorPinR, HIGH);
digitalWrite(motorPinL,LOW); 

}

//stops robot(Jack G, Dan Vass and Tom B)
void stop( ){

if (distance() == 10) {
  int speed = (distance() * 10);
  analogWrite(motorPinL, speed);
  analogWrite(motorPinR, speed);
}
else if (distance() == 1) {
  analogWrite(motorPinL, 0);
  analogWrite(motorPinR, 0);
}
}

//start func evan jordan
int start(){
  int d=0;
  for (int i=0; i<=180; i= i+20){
    servo(i);
     d = distance();
    if (d< distance()){
      d= distance();  
    }
  }
 return d;
}

// setting up all the pins on the arduino 
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPinL, OUTPUT);
  pinMode(motorPinR, OUTPUT);
  myservo.attach(servoPin); 
  lcd.begin(16, 2); 
  
}

void loop() {
  // put your main code here, to run repeatedly:
start();
}
