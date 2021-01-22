// wifi.h
#ifndef _WIFI_H
#define _WIFI_H

#include <ESP8266WiFi.h>

class Wifi {
  public:
    static IPAddress connect(const char* ssid, const char* password);      
};

#endif // _WIFI_H
