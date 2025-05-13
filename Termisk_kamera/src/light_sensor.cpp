#include "light_sensor.h"
#include <Arduino.h>
#include "client.h"
#include <iostream>

#define SPREDNING 100

light_sensor::light_sensor(int light_level, int threshold)
{
    this->light_level_ = light_level;
    this->threshold_ = threshold;
}

int light_sensor::adjust_light()
{
  int sensorvalue = analogRead(35); // 0 til 4096 
   
  std::cout << "Sensorvalue: " <<std::to_string(sensorvalue) << std::endl;
      
  if ((sensorvalue < threshold_ - SPREDNING) && (light_level_ < 96))
  {
    light_level_ += 5;
  }
  else if ((sensorvalue > threshold_ + SPREDNING) && (light_level_ > 4))
  {
    light_level_ -= 5;
  }   
  std::cout << "Light Level: " <<std::to_string(light_level_) << std::endl;

  return light_level_;
}
