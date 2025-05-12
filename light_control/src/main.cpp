#include <Arduino.h>
#include "light_control.h"
#include "client.h"



void setup() {
    client myClient(8081, "10.42.0.1");
    light_control lightController;
    Serial.begin(115200);
    lightController.init();
    while (true){
        String inputStr = myClient.read();  // Hent værdi som string
        Serial.print("Modtaget data: ");
        Serial.println(inputStr);
    
        if (inputStr.length() > 0) {
            int value = inputStr.toInt();
            value = constrain(value, 0, 100);
    
            if (value == 0) {
                lightController.turn_off();
            } else if (value == 100) {
                lightController.turn_on();
            } else {
                lightController.adjust_level(value);
            }
        }
    
        delay(1000);  // Vent lidt inden næste opdatering
    }
}

void loop() {
}