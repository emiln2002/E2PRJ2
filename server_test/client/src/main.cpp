#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "ThePromisedLan";
const char* password =  "12345678";

const uint16_t port = 8080;
const char * host = "192.168.8.144";

void setup(){
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }

  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());

}
int i{};
void loop()    
{
    WiFiClient client;

    if (!client.connect(host, port)) {

        Serial.println("Connection to host failed");

        delay(1000);
        return;
    }

    Serial.println("Connected to server successful!");

    String c = client.readString();

    Serial.println(c);

    client.print(i++);  
    
    Serial.println("Disconnecting...");
    client.stop();

    delay(1000);
}