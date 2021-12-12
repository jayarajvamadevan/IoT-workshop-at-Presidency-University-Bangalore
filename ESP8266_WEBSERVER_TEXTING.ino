#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server;
const char* ssid = "JioFi3_564B6F";
const char* pass = "x6mbnn9sz7";

void setup() 
{
  Serial.begin(115200); 
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=WL_CONNECTED)
      {
      Serial.print(".");
      delay(500);
      }
  Serial.println("");
  Serial.print("Ip Address:");
  Serial.println(WiFi.localIP());
  server.on("/", message);
  server.begin();
}

void loop() 
  {
    server.handleClient();
  }

void message()
  {
    server.send(200,"text/plain","Hello Welcome to IoT Workshop ");
    }
