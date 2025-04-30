#include <Arduino.h>
#include "light_control.h"

void light_control::init() {
    ledcSetup(pwmChannel, 1000, pwmResolution);  // 1kHz, 8-bit resolution
    ledcAttachPin(OUTPUT_PIN, pwmChannel);
}

void light_control::turn_on() {
    ledcWrite(pwmChannel, maxDuty);
    Serial.println("PWM Tændt (100%)");
}

void light_control::turn_off() {
    ledcWrite(pwmChannel, 0);
    Serial.println("PWM Slukket (0%)");
}

void light_control::adjust_level(int level) {
    level = constrain(level, 0, 100);
    int duty = map(level, 0, 100, 0, maxDuty);
    ledcWrite(pwmChannel, duty);

    Serial.print("PWM Justeret: ");
    Serial.print(level);
    Serial.print("% => Duty: ");
    Serial.println(duty);
}