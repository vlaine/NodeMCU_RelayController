#include "wifi.h"
#include "serverManager.h"

// Replace these with your WiFi network settings
const char* ssid = "{YOUR_SSID}";
const char* password = "{YOUR_PASSWORD}";

ServerManager serverManager;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("");
  Serial.println("Starting...");
  
  IPAddress ip = Wifi::connect(ssid, password);
  serverManager.start(ip);
}

void loop() {
  serverManager.server.handleClient();
}
