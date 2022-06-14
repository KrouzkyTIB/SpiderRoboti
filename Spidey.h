//
// Created by jiri on 14.6.22.
//

#ifndef SPIDEY_LIB_SPIDEY_H
#define SPIDEY_LIB_SPIDEY_H
#define BASIC_STANCE_NORMAL 120
#define BASIC_STANCE_INVERTED 60
#define TRIM_STANCE 90




#include "Leg.h"
enum SideMovement{
    FORWARD,
    MID,
    BACKWARD
};


class Spidey {
private:
    Leg frontRightLeg;
    Leg rearRightLeg;
    Leg rearLeftLeg;
    Leg frontLeftLeg;
public:
    void basicStance();
    void trimStance();
    void initPeripheries();
    void lieDown();
    void standUp();
    void moveLeftSide(int movementType);
    void moveRightSide(int movementType);
    Spidey(const Leg &frontRightLeg, const Leg &rearRightLeg, const Leg &rearLeftLeg, const Leg &frontLeftLeg);
    Spidey() = delete;
    Leg &getFrontRightLeg();
    Leg &getRearRightLeg();
    Leg &getRearLeftLeg();
    Leg &getFrontLeftLeg();

};


#endif //SPIDEY_LIB_SPIDEY_H
