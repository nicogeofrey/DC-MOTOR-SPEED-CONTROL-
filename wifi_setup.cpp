#include <ESP8266WiFi.h>
#include "wifi_setup.h"

const char* ssid = "nicozyatzaccessories";
const char* password = "NICOZ.COM";

void wifi_connect() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());
} 