#include <Stepper.h>
int spr = 2048;
int motspeed = 10;
int dt = 500;
Stepper myStepper(spr, 8, 10, 9, 6);


void setup() {

Serial.begin(9600);
myStepper.setSpeed(motspeed);

}

void loop() {

myStepper.step(spr/2);
//delay(dt);

}
