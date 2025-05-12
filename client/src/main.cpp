#include <Arduino.h>
#include "client.h"


void setup(){
  client gardin(8082);

  gardin.send("En lille besked om udelys");

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  

  while(1){
    String read = gardin.read();
    
    if (read == "100") digitalWrite(2, HIGH);
    else if (read == "0") digitalWrite(2, LOW);
 
  }
}

void loop(){}
