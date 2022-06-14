//
// Created by jiri on 14.6.22.
//

#include "Leg.h"

#define HALF_ROUND 180

int Leg::getKneeDegree() const {
    return kneeDegree;
}

int Leg::getLegDegree() const {
    return legDegree;
}

Leg::Leg(const int kneeServoPin, const int legServoPin) : kneeServoPin(kneeServoPin),
                                                          legServoPin(legServoPin) {

}

void Leg::initPeripheries() {
    legServo.attach(legServoPin);
    kneeServo.attach(kneeServoPin);
}

void Leg::standUp() {
    kneeDegree = STAND_UP_DEGREE;
    kneeServo.write(kneeDegree);
}


void Leg::moveLeg(int degree) {
    legDegree = degree % HALF_ROUND;
    legServo.write(legDegree);
}

void Leg::moveKnee(int degree) {
    kneeDegree = degree % HALF_ROUND;
    kneeServo.write(kneeDegree);
}




