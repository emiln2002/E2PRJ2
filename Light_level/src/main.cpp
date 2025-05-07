#include <Arduino.h>
#include "client.h"
#include <string.h>
#include <iostream>


void setup() {
  // put your setup code here, to run once:
  client c(8082,"10.42.0.1");
 
  pinMode(35, INPUT);

  while(1){
    int sensorvalue = analogRead(35);
  //Serial.println(sensorvalue);
  sensorvalue = map(sensorvalue, 0, 4096, 0, 100);
    c.read();
  c.send(String(sensorvalue));
  

  }
}

void loop() {
  // put your main code here, to run repeatedly:

}