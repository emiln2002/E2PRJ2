#ifndef GARDIN_DRIVER_H
#define GARDIN_DRIVER_H

#include <AccelStepper.h>
#include <Arduino.h>


class gardin_driver {
private:
    static const int STEPS_PER_REV = 2048;
    static const int NUM_REVOLUTIONS = 1;
    const int TOTAL_STEPS = STEPS_PER_REV * NUM_REVOLUTIONS;

    AccelStepper motor;
    bool lastLightWasBright = false;
    bool initilized_ = false;

public:
    gardin_driver();
    void setup();
    void shaders_up();    // Full CW movement
    void shaders_down();  // Full CCW movement
    void invert_direction(bool invert);
    bool getInitilized() const ;
    void setInitilized(bool initilized);
};

#endif