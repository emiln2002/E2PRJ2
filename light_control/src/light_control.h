#pragma once

struct light_control {
    static const int OUTPUT_PIN = 18;
    static const int pwmChannel = 0;
    static const int pwmResolution = 8;
    static const int maxDuty = 255;
    
    void init();
    void turn_on();
    void turn_off();
    void adjust_level(int level);
};