#include <Arduino.h>
#include "Leg.h"
#include "Spidey.h"

Leg frontRightLeg(2, 3);
Leg rearRightLeg(4,5);
Leg rearLeftLeg(6,7);
Leg frontLeftLeg(8,9);
Spidey spidey(frontRightLeg, rearRightLeg, rearLeftLeg, frontLeftLeg);
void setup() {
// write your initialization code here
    spidey.initPeripheries();
    spidey.trimStance();
    delay(3000);
    spidey.basicStance();
    delay(1000);
}

void loop() {
// write your code here

    spidey.moveRightSide(SideMovement::FORWARD);
    delay(500);
    spidey.moveRightSide(SideMovement::BACKWARD);
    delay(500);
    spidey.moveLeftSide(SideMovement::FORWARD);
    delay(500);
    spidey.moveLeftSide(SideMovement::BACKWARD);
    delay(500);

}