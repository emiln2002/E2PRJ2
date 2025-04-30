#include <Arduino.h>
#include "light_control.h"
#include "../../wifi_client/client.h"

client myClient(8080, "10.42.0.1", "smart");
light_control lightController;

void setup() {
    Serial.begin(115200);
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