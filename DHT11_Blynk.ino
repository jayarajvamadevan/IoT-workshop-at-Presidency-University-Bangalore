#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11      
#define DHT_PIN 0
char auth[] = "OaPscvkvxCsXZJr_o18UFgTLh7ZAnEBk";   // You should get Auth Token in the Blynk App.                                       
char ssid[] = "JioFi3_564B6F";// Your WiFi credentials.
char pass[] = "x6mbnn9sz7";// Set password to "" for open networks.
DHT dht(DHT_PIN, DHTTYPE); 
BlynkTimer timer;

void setup()
{
    Serial.begin(115200);// Debug console
    Blynk.begin(auth, ssid, pass);
    dht.begin();
    timer.setInterval(2000, sendUptime);
}

void sendUptime()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  Serial.print("Relative Humidity = ");
  Serial.print(h);
  Serial.print("\tTemperature = ");
  Serial.print(t); 
  Serial.println(""); 
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  delay(5000);
}
void loop()
{
  Blynk.run();
  timer.run();
}
