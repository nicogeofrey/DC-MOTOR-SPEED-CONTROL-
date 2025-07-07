#include <ESP8266WebServer.h>
#include "web_server.h"
#include "html_page.h"
#include "motor_control.h"
#include "lcd_display.h"

ESP8266WebServer server(80);

void webserver_init() {
  server.on("/", HTTP_GET, []() {
    server.send_P(200, "text/html", htmlPage);
  });

  server.on("/setSpeed", HTTP_GET, []() {
    if (server.hasArg("value")) {
      int speed = server.arg("value").toInt();
      motor_set_speed(speed);
      lcd_update(motor_get_speed(), motor_get_pwm());
      Serial.printf("Speed: %d%% -> PWM: %d\n", motor_get_speed(), motor_get_pwm());
    }
    server.send(200, "text/plain", "OK");
  });

  server.on("/getSpeed", HTTP_GET, []() {
    server.send(200, "text/plain", String(motor_get_speed()));
  });

  server.begin();
}

void webserver_handle_client() {
  server.handleClient();
} 