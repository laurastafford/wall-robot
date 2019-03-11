  int trigPin = 8;
  int echoPin = 7;

  #include <LiquidCrystal.h>
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  //pins for LCD screen are 12, 11, 5, 4, 3 & 2

  long duration;

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

void Lcd(int text) {
    lcd.setCursor(0, 0);
  //sets where the message will be printed
  lcd.print(text);
  //Prints a message to the LCD screen
  delay(500);
  lcd.clear();
}
//The LCD screen will need to be cleared, 
//as it will continously print and look wrong &
//without the delay it will instantally clear

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2); 
  //Allows the LCD screen to function
}

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);)
}

void stop(int ){
  d = distance()
while d == 10 
  speed = (distance * 10)
  motorSpin (motorPinL, speed);
  motorSpin (motorPinR, speed);
elif d == 1 
  motorspin (motorPinL, 0);
  motorspin (motorPinR, 0);
}

void left(int speed){
analogWrite(motorPinL, speed);  
}

void right(){
analogWrite(motorPinR, speed);  
}
