#include "wifi.h"

IPAddress Wifi::connect(const char* ssid, const char* password) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  ESP.wdtFeed();  
  Serial.println();
  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Successfully connected to ");
  Serial.println(ssid);

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address is: ");
  Serial.println(ip);
  return ip;
}
