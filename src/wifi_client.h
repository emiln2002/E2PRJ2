#pragma once
#include <string>


class wifi_client
{
private:
    int client_id;
    int server_ip;
public:
    void send(std::string data);
    std::string recieve();
};