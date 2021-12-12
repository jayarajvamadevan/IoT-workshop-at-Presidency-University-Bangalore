#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include <WiFiClient.h>
#define led1 2
#define led2 16
ESP8266WebServer server; 
char ssid[] = "JioFi3_564B6F";// Your WiFi credentials.
char pass[] = "x6mbnn9sz7";// Set password to "" for open networks. 
void setup()
{
    Serial.begin(115200);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
     Serial.println("");
    Serial.print("IP address is: ");
 Serial.println(WiFi.localIP());
 
    server.on("/", HTTP_GET, handleweb);
    server.on("/", HTTP_POST,ledcontrol);
    server.begin();
}
 
void loop()
{
    server.handleClient();
}
// Web server object declaration
String webPage =
    "<html>\r\n" \
    "<head>\r\n" \
    "<center>\r\n" \
    "<h1>ESP8266 LED CONTROL</h1>\r\n" \
    "<body>\r\n" \
    "<center>\r\n" \
    "<h2>LED1</h2>\r\n" \
    "<form method=\"post\">\r\n" \
    "<input type=\"submit\" name=\"led1\" value=\"ON\">\r\n" \
    "<input type=\"submit\" name=\"led1\" value=\"OFF\">\r\n" \
    "</form>\r\n" \
    "</body>\r\n" \
    "<center>\r\n" \
    "<h3>LED 2</h3>\r\n" \
    "<form method=\"post\">\r\n" \
    "<input type=\"submit\" name=\"led2\" value=\"ON\">\r\n" \
    "<input type=\"submit\" name=\"led2\" value=\"OFF\">\r\n" \
    "</form>\r\n" \
    "</body>\r\n" \
    "</html>\r\n";
    
void handleweb()
{
    server.send(200, "text/html", webPage);
}
 
void ledcontrol()
{
    if (server.arg("led1") == "ON")
    {
      digitalWrite(led1, LOW);
    }  
    else if (server.arg("led1") == "OFF")
    {
      digitalWrite(led1, HIGH);
    }   
     else if (server.arg("led2") == "ON")
    {
       digitalWrite(led2, LOW);
    }
    else
    {
       digitalWrite(led2, HIGH);
    }    
 server.sendHeader("Location","/");
server.send(303);
}
