#include <Arduino.h>
#include "client.h"


void setup(){
  client gardin(8081, "192.168.8.220");
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);

  while(1){
    String read = gardin.read();
    if (read == "on") digitalWrite(2, HIGH);
    else if (read == "off") digitalWrite(2, LOW);
    // delay(1000);
    // gardin.send("55");
    // delay(1000);

  }
}

void loop(){}




/*
#include <WiFi.h>

const char* ssid = "smart";

const uint16_t port = 8080;
const char * host = "10.42.0.1";

void setup(){
  Serial.begin(9600);

  WiFi.begin(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }

  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());

  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
}
int i{};
void loop()    
{
  WiFiClient client;

  while (!client.connect(host, port)) {

      Serial.println("Connection to host failed");

      delay(1000);
      return;
  }
  

  Serial.println("Connected to server successful!");
  
  //String c = client.readString();

  // Serial.println(client.read());

  client.print(i++);  

  delay(1000);

  if (client.available()) {
    String c = client.readString();
    Serial.println(c);
    if (c == "on"){
      digitalWrite(2,HIGH);
    }
    else if(c == "off"){
      digitalWrite(2,LOW);
    }
  }
  else Serial.println("no data available");
  
  Serial.println("Disconnecting...");
  client.stop();

}
  */