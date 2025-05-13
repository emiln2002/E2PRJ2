#include "Gardin_driver.h"
#include <Arduino.h>

gardin_driver::gardin_driver() :
    motor(AccelStepper::FULL4WIRE, 13, 14, 12, 27) {
}

void gardin_driver::setup() {
    motor.setMaxSpeed(400);
    motor.setAcceleration(400);
    motor.setCurrentPosition(0);
}

void gardin_driver::invert_direction(bool invert) {
    motor.setPinsInverted(invert, false, invert);
}

bool gardin_driver::getInitilized() const
{
    return initilized_;
}

void gardin_driver::setInitilized(bool initilized)
{
    initilized_ = initilized;
}

void gardin_driver::shaders_up() {
    if (!lastLightWasBright) {
        invert_direction(false);
        motor.move(TOTAL_STEPS);

        // Move until complete
        while (motor.run()) {
        }

        lastLightWasBright = true;
    }
}

void gardin_driver::shaders_down() {
    if (lastLightWasBright && initilized_ == true) {
        invert_direction(true);
        motor.move(-TOTAL_STEPS);

        // Move until complete
        while (motor.run()) {
        }

        lastLightWasBright = false;
    }
}