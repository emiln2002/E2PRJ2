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
    client(const int port = 8080, const char * host_ip = "172.20.10.2", const char* ssid = "smart");

    void send(String data);

    String read();
    
};


