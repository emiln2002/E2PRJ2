#include "kamera_driver.h"
#include <Adafruit_MLX90640.h> 
#include <iostream>





bool kamera_driver::person_detected()
{
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


bool kamera_driver::area_mode(){
  getFrame(pixel_temps); //tager billede
  int current_pixel_chain = 0;
  for (size_t i = 1; i <= 768-(32*(square_sidelength_-1)); i++) 
  {
    if(pixel_temps[i]> detecting_temp_){
      current_pixel_chain++;
    }
    else{
      current_pixel_chain = 0;
    }
    
    if(current_pixel_chain == square_sidelength_){
      if(check_following_lines(i + 33 - square_sidelength_)==true){
        return true;
      }
    }
    
    if(i%32==0){
      current_pixel_chain = 0;
    }

  }
  return false;
}

bool kamera_driver::check_following_lines(int start){
  
  for(auto k = 0; k < square_sidelength_-1; k++) { //Ydre loop - styrer antallet af linjer under
    for(auto i = start; i < start + square_sidelength_; i++){ //gennemløber pixels på en linje
      if(pixel_temps[i]<detecting_temp_){
        return false;
      }
    }
    start += 32; //Går til næste linje
  }
  return true;
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