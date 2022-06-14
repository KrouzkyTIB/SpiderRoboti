//
// Created by jiri on 14.6.22.
//

#include "Arduino.h"
#include "Leg.h"
#include "Spidey.h"

Leg frontRightLeg(2, 3);
Leg rearRightLeg(4,5);
Leg rearLeftLeg(6,7);
Leg frontLeftLeg(8,9);
Spidey spidey(frontRightLeg, rearRightLeg, rearLeftLeg, frontLeftLeg);
void setup(){
    spidey.initPeripheries();
    spidey.trimStance();
}

void loop(){

}