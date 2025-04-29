#include <Arduino.h>
#include <Adafruit_MLX90640.h> 
#include <iostream>
#include <Wire.h>  // Aruduino standard library til I2C kommunikation
#include "kamera_driver.h"


/*
#include <MLX90640_I2C_Driver.h> // header file containing the definitions of the I2C related functions
#include <MLX90640_I2C_Driver.cpp> // file containing the I2C related functions
#include <MLX90640_API.h> // header file containing the definitions of the MLX90640 specific functions
#include <MLX90640_API.h> // file containing the MLX90640 specific functions
*/

// #include "kamera_driver.h"
// #include "light_sensor.h"
// #include "wifi_client.h"


// #define LOW 0;                // low level on the line (default ‘0’), could be ‘1’ if the line is inverted
// #define HIGH 1;               // high level on the line (default ‘1’), could be ‘0’ if the line is inverted
// #define SCL_HIGH scl = HIGH;  // I2C clock high level definition
// #define SCL_LOW scl = LOW;    // I2C clock low level definition
// #define SDA_HIGH sda.input(); // I2C data high level definition
// #define SDA_LOW sda.output(); // I2C data low level definition

// TwoWire wire;    // er allerede instantieret som Wire
Adafruit_MLX90640 MLX90640;

// This code will scan the I2C bus for connected devices and display their addresses in the serial monitor.
void scanI2CDevices() {
  byte error, address;
  int deviceCount = 0;
  Serial.println("Scanning for I2C devices…");
  for (address = 1; address < 127; address++) {
  // The i2c_scanner uses the return value of
  // the Write.endTransmisstion to see if
  // a device did acknowledge to the address.
  Wire.beginTransmission(address);
  error = Wire.endTransmission();
  if (error == 0) {
  Serial.print("I2C device found at address 0x");
  if (address < 16) {
  Serial.print("0");
  }
  Serial.println(address, HEX);
  deviceCount++;
  }
  else if (error == 4) {
  Serial.print("Unknown error at address 0x");
  if (address < 16) {
  Serial.print("0");
  }
  Serial.println(address, HEX);
  }
  }
  if (deviceCount == 0) {
  Serial.println("No I2C devices found.");
  }
  else {
  Serial.println("Scan complete.");
  }
}
  
void setup() {
  Wire.begin();
  Serial.begin(9600);
  scanI2CDevices();

  /*
  MLX90640.begin(0x37, &Wire); // GPIO21 = SDA, GPIO22 = SCL (det er standard, ellers skriv pin navne i parantesen)
  int res = MLX90640.getResolution();
  std::cout << "resolution: " << res << std::endl; 

  float temperaturer[768];
  int billede = MLX90640.getFrame(temperaturer);

  for (size_t i = 0; i < 768; i++)
  {
    std::cout << temperaturer[i] << std::endl;
  }
    */
  
    kamera_driver kamera1(26, 30, 0x37);
  
  while (1)
  {
    if (kamera1.person_detected() == 0)
    {
      std::cout << "No person detected" << std::endl;
    
    }
    else {
      std::cout << "PERSON DETECTEDDDDDD" << std::endl;
    }
    delay(1000);
  }  
  

}

void loop() {
  
}

