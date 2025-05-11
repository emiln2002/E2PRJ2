#include <Arduino.h>
#include <Adafruit_MLX90640.h> 
#include <iostream>
#include <Wire.h>  // Aruduino standard library til I2C kommunikation
#include "kamera_driver.h"
#include "client.h"
#include "light_sensor.h"


void setup() {
  //client c(8083, "10.42.0.1");

  Wire.begin();
  Serial.begin(9600); //tilføjet igen for at se i terminal, ved ikke om det skal være der

  kamera_driver kamera1(26, 30, 4, 0x33); //Jeg har ændret adressen
  
  light_sensor light1(50, 1000);
  
  pinMode(35, INPUT);
  int light_level = 50;
  int threshold = 1000; // skal testes

  /*
  while (1)
  {
    if (kamera1.person_detected() == 0)
    {
      std::cout << "No person detected" << std::endl;
      //c.send(String(0));
    }
    else {
      std::cout << "PERSON DETECTEDDDDDD" << std::endl;
      //c.send(String(light1.adjust_light()));
    }
    //c.read();
  }

  */

  while (1)
  {
    if (kamera1.area_mode() == 0)
    {
      std::cout << "No person detected" << std::endl;
      //c.send(String(0));
    }
    else {
      std::cout << "PERSON DETECTEDDDDDD" << std::endl;
      //c.send(String(light1.adjust_light()));
    }
    //c.read();
  }
}

void loop() {
  
}



