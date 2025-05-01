#include <Arduino.h>
#include "light_control.h"
#include "client.h"


client myClient(8081, "10.133.43.160", "smart");
light_control lightController;

void setup() {
    // Serial.begin(115200);
    lightController.init();
}

void loop() {
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