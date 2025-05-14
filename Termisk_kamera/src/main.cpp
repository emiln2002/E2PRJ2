#include <Arduino.h>
#include <Adafruit_MLX90640.h> 
#include <iostream>
#include <Wire.h>  // Aruduino standard library til I2C kommunikation
#include "kamera_driver.h"
#include "client.h"
#include "light_sensor.h"


void setup() {
  client c(8083, "10.42.0.1");

  Wire.begin();
  Serial.begin(9600); //tilføjet for at se i terminal

  kamera_driver kamera1(28, 30, 3, 0x33); 

  int threshold = 500;

  light_sensor light1(50, threshold);
  
  
  pinMode(35, INPUT);
  
  analogReadResolution(12);


  while (1)
  {
    if (kamera1.area_mode() == 0)
    {
      std::cout << "No person detected" << std::endl;
      c.send(String(0));
    }
    else {
      std::cout << "PERSON DETECTEDDDDDD" << std::endl;
      c.send(String(light1.adjust_light()));
    }
    c.read();
  }

}

void loop() {

}




