#ifndef GARDIN_DRIVER_H
#define GARDIN_DRIVER_H

#include <AccelStepper.h>

class gardin_driver {
private:
    int up_pos;
    int down_pos;
    static const int STEPS_PER_REV = 2048;
    static const int NUM_REVOLUTIONS = 1;
    const int TOTAL_STEPS = STEPS_PER_REV * NUM_REVOLUTIONS;

    AccelStepper motor;
    bool isMotorMoving;
    bool motorDirectionCW;

    enum CurtainState { MOVING, OPEN, CLOSED };
    CurtainState curtainState;

    void moveCurtains(bool clockwise);
    void finishMovement();

public:
    gardin_driver();
    void setup();
    void shaders_up();
    void shaders_down();
    void loop(int lightLevel);
};

#endif