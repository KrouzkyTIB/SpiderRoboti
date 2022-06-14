//
// Created by jiri on 14.6.22.
//

#ifndef SPIDEY_LIB_LEG_H
#define SPIDEY_LIB_LEG_H
#define STAND_UP_DEGREE 40
#define LIE_DOWN_DEGREE 130
#define LIFT_UP_DEGREE 0


#include <Arduino.h>
#include "Servo.h"



class Leg {
private:
    const int kneeServoPin;
    const int legServoPin;
    Servo kneeServo;
    Servo legServo;
    int kneeDegree;
    int legDegree;

public:
    void moveLeg(int degree);
    void standUp();
    void moveKnee(int degree);
    Leg(int kneeServoPin, int legServoPin);
    Leg() = delete;
    void initPeripheries();

    int getKneeDegree() const;

    int getLegDegree() const;
};


#endif //SPIDEY_LIB_LEG_H
