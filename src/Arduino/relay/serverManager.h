// serverManager.h
#ifndef _SERVER_MANAGER_H
#define _SERVER_MANAGER_H

#include <ESP8266WebServer.h>
#include "relayManager.h"

class ServerManager {
  public:   
    ESP8266WebServer server = {80};
    void start(IPAddress _ip);  
  private:
    IPAddress ip;
    RelayManager relayManager;
    void handleRoot();
    void readRelay(int i);
    void writeRelay(int i);
    void sendValue(int i);
    bool isNumber(String str);
    String validateArg(String strVal);
};

#endif // _SERVER_MANAGER_H
