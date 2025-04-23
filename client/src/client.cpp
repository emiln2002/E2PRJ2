#include "client.h"

client::client(const int port, const char *host_ip, const char *ssid)
    : port(port), host_ip(host_ip), ssid(ssid)
{
    Serial.begin(9600);

    WiFi.begin(ssid);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("...");
    }

    Serial.print("WiFi connected with IP: ");

    Serial.println(WiFi.localIP());
}

String client::read()
{
    while (data_recieved == ""){
        WiFiClient client;

        while (!client.connect(host_ip, port)) {

            Serial.println("Connection to host failed");

            delay(1000);
        }
        

        Serial.println("Connected to server successful!");

        delay(1000);
        client.println("Hello from ESP32");
        delay(500);
        if (client.available()) {
            String c = client.readString();
            Serial.println(c);
            data_recieved = c;
        }
        else Serial.println("no data available");
        
        Serial.println("Disconnecting...");
        client.stop();
        
    }
        return data_recieved;
}
