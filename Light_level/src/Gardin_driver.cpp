#include "Gardin_driver.h"
#include <Arduino.h>

// Constructor
gardin_driver::gardin_driver() :
    motor(AccelStepper::FULL4WIRE, 13, 14, 12, 27),
    up_pos(0),
    down_pos(0),
    isMotorMoving(false),
    motorDirectionCW(true),
    curtainState(MOVING) {
}

void gardin_driver::setup() {
    analogReadResolution(12);
    motor.setMaxSpeed(200);
    motor.setAcceleration(400);
}

void gardin_driver::moveCurtains(bool clockwise) {
    motor.setCurrentPosition(0);
    long targetSteps = (clockwise ? TOTAL_STEPS : -TOTAL_STEPS);
    motor.moveTo(targetSteps);
    isMotorMoving = true;
}

void gardin_driver::finishMovement() {
    curtainState = (motorDirectionCW ? OPEN : CLOSED);
}

void gardin_driver::shaders_up() {
    if (curtainState != OPEN) {
        motorDirectionCW = true;
        moveCurtains(motorDirectionCW);
        curtainState = MOVING;
    }
}

void gardin_driver::shaders_down() {
    if (curtainState != CLOSED) {
        motorDirectionCW = false;
        moveCurtains(motorDirectionCW);
        curtainState = MOVING;
    }
}

void gardin_driver::loop(int lightLevel) {
    static bool lastWasBright = false;
    const int LIGHT_THRESHOLD = 3300;
    const int HYSTERESIS = 500;

    if (lightLevel > (LIGHT_THRESHOLD + HYSTERESIS) && !lastWasBright && !isMotorMoving) {
        shaders_up();
        lastWasBright = true;
    }
    else if (lightLevel < (LIGHT_THRESHOLD - HYSTERESIS * 6) && lastWasBright && !isMotorMoving) {
        shaders_down();
        lastWasBright = false;
    }

    if (isMotorMoving) {
        motor.run();
        if (motor.distanceToGo() == 0) {
            finishMovement();
            isMotorMoving = false;
        }
    }
}