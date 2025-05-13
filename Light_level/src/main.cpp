#include <Arduino.h>
#include "client.h"
#include "Gardin_driver.h"
#include <string.h>
#include <iostream>


void setup() {
  // put your setup code here, to run once:
    client c(8082, "10.42.0.1");
    gardin_driver curtainController;
    pinMode(35, INPUT);
    curtainController.setup();
  

  while(1){
    int sensorvalue = analogRead(35);
        sensorvalue = map(sensorvalue, 0, 4095, 0, 100);

        c.read();
        c.send(String(sensorvalue));

        if (c.read() == String(1)) {
            curtainController.shaders_up();
            curtainController.setInitilized(true);
        }

        if (c.read() == String(0)) {
            curtainController.shaders_down();
        }
}
}

void loop() {
  // put your main code here, to run repeatedly:

}