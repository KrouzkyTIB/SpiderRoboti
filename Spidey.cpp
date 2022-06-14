//
// Created by jiri on 14.6.22.
//

#include <assert.h>
#include "Spidey.h"

enum Movements {
    FRONT = 120,
    MIDDLE = 90,
    BACK = 60
};

enum KneeMovements{
    STAND = 40,
    LIFT = 0,
    LIFT_INVERTED = 80
};



Spidey::Spidey(const Leg &frontRightLeg, const Leg &rearRightLeg, const Leg &rearLeftLeg, const Leg &frontLeftLeg)
        : frontRightLeg(frontRightLeg), rearRightLeg(rearRightLeg), rearLeftLeg(rearLeftLeg),
          frontLeftLeg(frontLeftLeg) {}

Leg &Spidey::getFrontRightLeg() {
    return frontRightLeg;
}

Leg &Spidey::getRearRightLeg() {
    return rearRightLeg;
}

Leg &Spidey::getRearLeftLeg() {
    return rearLeftLeg;
}

Leg &Spidey::getFrontLeftLeg() {
    return frontLeftLeg;
}

void Spidey::initPeripheries() {
    frontLeftLeg.initPeripheries();
    frontRightLeg.initPeripheries();
    rearLeftLeg.initPeripheries();
    rearRightLeg.initPeripheries();
}

void Spidey::basicStance() {
    frontRightLeg.standUp();
    frontLeftLeg.standUp();
    rearLeftLeg.standUp();
    frontLeftLeg.standUp();
    frontLeftLeg.moveLeg(BASIC_STANCE_INVERTED);
    frontRightLeg.moveLeg(BASIC_STANCE_NORMAL);
    rearLeftLeg.moveLeg(BASIC_STANCE_NORMAL);
    rearRightLeg.moveLeg(BASIC_STANCE_INVERTED);
}

void Spidey::trimStance() {
    frontRightLeg.standUp();
    frontLeftLeg.standUp();
    rearLeftLeg.standUp();
    frontLeftLeg.standUp();
    frontLeftLeg.moveLeg(TRIM_STANCE);
    frontRightLeg.moveLeg(TRIM_STANCE);
    rearLeftLeg.moveLeg(TRIM_STANCE);
    rearRightLeg.moveLeg(TRIM_STANCE);
}

void Spidey::moveLeftSide(int movementType) {
    switch (movementType) {
        case SideMovement::FORWARD:
            frontLeftLeg.moveLeg(FRONT);
            rearLeftLeg.moveLeg(FRONT);
            break;
        case SideMovement::MID:
            frontLeftLeg.moveLeg(MIDDLE);
            rearLeftLeg.moveLeg(MIDDLE);
            break;
        case SideMovement::BACKWARD:
            frontLeftLeg.moveLeg(BACK);
            rearLeftLeg.moveLeg(BACK);
            break;
        default:
            assert(false);
            break;
    }
}

void Spidey::moveRightSide(int movementType) {
    switch (movementType) {
        case SideMovement::FORWARD:
            rearRightLeg.moveLeg(FRONT);
            frontRightLeg.moveLeg(FRONT);
            break;
        case SideMovement::MID:
            rearRightLeg.moveLeg(MIDDLE);
            frontRightLeg.moveLeg(MIDDLE);
            break;
        case SideMovement::BACKWARD:
            rearRightLeg.moveLeg(BACK);
            frontRightLeg.moveLeg(BACK);
            break;
        default:
            assert(false);
            break;
    }
}

void Spidey::standUp() {
    frontLeftLeg.standUp();
    frontRightLeg.standUp();
    rearLeftLeg.standUp();
    rearRightLeg.standUp();
}

void Spidey::lieDown() {
    frontLeftLeg.moveKnee(LIFT);
    frontRightLeg.moveKnee(LIFT_INVERTED);
    rearLeftLeg.moveKnee(LIFT_INVERTED);
    rearRightLeg.moveKnee(LIFT);
}
