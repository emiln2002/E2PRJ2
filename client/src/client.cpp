#include "client.h"

client::client(const int port, const char *host_ip, const char *ssid): port(port), host_ip(host_ip), ssid(ssid){
    Serial.begin(9600);

    // WiFi.begin(ssid);
    WiFi.begin("ThePromisedLan", "12345678");
    
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("...");
    }

    Serial.println("WiFi connected");
}

void client::send(String data){
    data_send = data;
}

String client::read() {
    String data_received = "";

    WiFiClient client;

    while (!client.connect(host_ip, port)) {
        Serial.println("Connection failed");
        delay(100);
    }

    Serial.println("Connected to server");

    // Step 1: Send REQUEST to the server
    client.println(data_send);
    client.flush();
    Serial.println("Sent data_send to server");

    // Step 2: Wait for the response from the server
    unsigned long timeout = millis();
    while (!client.available()) {
        if (millis() - timeout > 5000) {
            Serial.println("Timeout waiting for response");
            client.stop();
            return "";
        }
        delay(10);
    }

    // Step 3: Read the response from the server
    data_received = client.readStringUntil('\n');
    data_received.trim();  // remove any trailing \r or \n
    Serial.print("Received state: ");
    Serial.println(data_received);

    // Step 4: Send 102 to the server to acknowledge receipt
    delay(100);  // short delay before 102
    client.println("102");
    client.flush();
    Serial.println("Sent 102 to server");

    // Step 5: Cleanly close the connection
    delay(100);  // give server a moment to process
    client.stop();

    return data_received;
}
