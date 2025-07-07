#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include "lcd_display.h"
#include "motor_control.h"
#include "wifi_setup.h"
#include "web_server.h"

void setup() {
  Serial.begin(115200);
  lcd_init();
  motor_init();
  wifi_connect();
  webserver_init();
}

void loop() {
  webserver_handle_client();
} 