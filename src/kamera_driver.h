#pragma once
#include <Adafruit_MLX90640.h> 
#include <Wire.h>

class kamera_driver : public Adafruit_MLX90640
{
private:
    int detecting_temp_;
    int count_min_;
    float pixel_temps[768] {};
public:
    kamera_driver(int detecting_temp, int count_min, int i2c_addr)
    : detecting_temp_(detecting_temp), count_min_(count_min), Adafruit_MLX90640() {
        begin(i2c_addr, &Wire);
        pixel_temps = float[768]{};
    }
    bool person_detected();
    int getFrame(float *framebuf);
};
