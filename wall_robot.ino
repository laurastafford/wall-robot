#include <Stepper.h>
const int SPR = 200; //amount of steps of motor
Stepper left(SPR, 2, 3, 4, 5);
Stepper right(SPR, 6, 7, 8, 9);
int stepCount = 0; // how far the step has gone

void forwards(int steps,int rpm){
left.setSpeed(rpm);
right.setSpeed(rpm);
left.step(steps);
right.step(steps);

}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
