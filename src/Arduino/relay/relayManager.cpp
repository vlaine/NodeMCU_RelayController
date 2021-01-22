#include "relayManager.h"

void RelayManager::init()
{
  for(int i=0; i<sizeof(pins); i++)
  {
    pinMode(pins[i], OUTPUT);    
    digitalWrite(pins[i], LOW);
  }
}

void RelayManager::write(int i, int val)
{
  digitalWrite(pins[i], val);  
}

int RelayManager::read(int i)
{
  return digitalRead(pins[i]);  
}
