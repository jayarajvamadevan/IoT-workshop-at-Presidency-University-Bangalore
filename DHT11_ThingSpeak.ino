
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <DHT.h>
#include <ThingSpeak.h>;
#define DHTPIN 0  //pin where the dht11 is connected
DHT dht(DHTPIN, DHT11);
WiFiClient client;
// WiFi credentials.
char ssid[] = "JioFi3_564B6F";//Set ssid to "" for open networks.
char pass[] = "x6mbnn9sz7";// Set password to "" for open networks.
unsigned long myChannelNumber = 1074972; //Your Channel Number (Without Brackets)
const char* myWriteAPIKey = "84FMQPXYGOFFY6PZ"; //Your Write API Key

void setup()
{
  Serial.begin(115200);
       delay(10);
       dht.begin();
       Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid, pass);
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
ThingSpeak.begin(client);
}

void loop()
{
float hum = dht.readHumidity();
float temp = dht.readTemperature();
Serial.print("HUMIDITY:"); //Print on Serial Monitor
Serial.print(hum); 
Serial.print("\t TEMPERATURE:"); //Print on Serial Monitor
Serial.print(temp); 
Serial.println(" ");
delay(1000);
//Sending data to ThingSpeak cloud
ThingSpeak.setField( 1,hum);
ThingSpeak.setField( 2,temp);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
delay(20000);// ThingSpeak will only accept updates every 15 seconds.
}
