#include "kamera_driver.h"
#include <Adafruit_MLX90640.h> 





bool kamera_driver::person_detected()
{
    // float temperaturer[768];
    int billede = getFrame(pixel_temps); 
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