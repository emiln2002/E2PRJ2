#pragma once
#include <iostream>
#include <WiFi.h>
using namespace std;

class client
{
private:
    const int port;
    const char * host_ip;
    const char* ssid;

    String data_send;
    
public:
    client(const int port = 8080, const char * host_ip = "10.42.0.1", const char* ssid = "smart");

    void send(String data);

    String read();
    
};


