// wifi.h
#ifndef _RELAYMANAGER_H
#define _RELAYMANAGER_H

#include <ESP8266WiFi.h>
#include "pins_arduino.h"

class RelayManager {  
  public :
    void init();
    int read(int i);
    void write(int ielay, int val);
    
  private :    
    int pins[9] {D0, D1, D2, D3, D4, D5, D6, D7, D8};    
};
#endif // _RELAYMANAGER_H
