#include "light_sensor.h"
#include <Arduino.h>
#include "client.h"

light_sensor::light_sensor(int light_level, int threshold)
{
    this->light_level_ = light_level;
    this->threshold_ = threshold;
}

int light_sensor::adjust_light()
{
    int sensorvalue = analogRead(35); // 0 til 4096 
      if ((sensorvalue < threshold_ - 50) && (light_level_ < 96))
      {
        light_level_ += 5;
      }
      else if ((sensorvalue > threshold_ + 50) && (light_level_ > 4))
      {
        light_level_ -= 5;
      }   
    return light_level_;
}
