#include "kamera_driver.h"
#include <Adafruit_MLX90640.h> 
#include <iostream>





bool kamera_driver::person_detected()
{
    // float temperaturer[768];
    getFrame(pixel_temps); 
    int count = 0;
    for (size_t i = 0; i < 768; i++)
    {
        if(pixel_temps[i] > detecting_temp_)
        {
        count++;
        }
    }
    if (count > count_min_) {return true;}
    else {return false;}
}

/*
void kamera_driver::screen_mode()
{
    getFrame(pixel_temps);

    int a = 0;   // række start
    int b = 32;  // række slut
    while (1) {
      for (size_t i = a; i < b; i++)
      {
        if (pixel_temps[i] > detecting_temp_)
        {
          std::cout << "X";
        }
        else {std::cout << "O";}
      }
      a += b;
      b += b;
      std::cout << std::endl;
      if (b == 768)
      {
        a = 0;
        b = 32;
        delay(500);
        std::cout << "\033[2J\033[H";
      }
    }
    
}
    */