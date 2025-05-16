#pragma once
#include <Adafruit_MLX90640.h> 
#include <Wire.h>

class kamera_driver : public Adafruit_MLX90640
{
private:
    int detecting_temp_;
    int square_sidelength_; //sidelængde på kvadrat der tjekkes efter
    float* pixel_temps = new float[768] {};
    //int count_min_; - benyttes til person_detected_vol1()

    bool check_following_lines(int start);
    
public:
    kamera_driver(int detecting_temp, /*int count_min,*/ int square_sidelength, int i2c_addr)
    : detecting_temp_(detecting_temp), /*count_min_(count_min),*/ square_sidelength_(square_sidelength), Adafruit_MLX90640() {
        begin(i2c_addr, &Wire);
    }
    //bool person_detected_vol1();
    bool person_detected();
    void screen_mode();
};


