#include <Arduino.h>
#include "light_control.h"

#define OUTPUT_PIN 18

const int pwmChannel = 0;
const int pwmResolution = 8;
const int maxDuty = 255;

void initLightControl() {
    ledcSetup(pwmChannel, 1000, pwmResolution);  // 1kHz, 8-bit opløsning
    ledcAttachPin(OUTPUT_PIN, pwmChannel);
}

void turn_on() {
    ledcWrite(pwmChannel, maxDuty);
    Serial.println("PWM Tændt (100%)");
}

void turn_off() {
    ledcWrite(pwmChannel, 0);
    Serial.println("PWM Slukket (0%)");
}

void adjust_level(int level) {
    level = constrain(level, 0, 100);
    int duty = map(level, 0, 100, 0, maxDuty);
    ledcWrite(pwmChannel, duty);

    Serial.print("PWM Justeret: ");
    Serial.print(level);
    Serial.print("% => Duty: ");
    Serial.println(duty);
}
