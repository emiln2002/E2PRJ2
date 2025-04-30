#include <Arduino.h>
#include "light_control.h"
#include "../../wifi_client/client.h"

client myClient(8080, "10.42.0.1", "smart");

void setup() {
    Serial.begin(115200);
    initLightControl();
}

void loop() {
    String inputStr = myClient.read();  // Hent værdi som string
    Serial.print("Modtaget data: ");
    Serial.println(inputStr);

    if (inputStr.length() > 0) {
        int value = inputStr.toInt();
        value = constrain(value, 0, 100);

        if (value == 0) {
            turn_off();
        } else if (value == 100) {
            turn_on();
        } else {
            adjust_level(value);
        }
    }

    delay(1000);  // Vent lidt inden næste opdatering
}
