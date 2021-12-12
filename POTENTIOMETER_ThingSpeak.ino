#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#define POT_PIN  A0 //Potntiometer  Connected at A0 Pin
char ssid[] = "JioFi3_564B6F";// Your WiFi credentials.
char pass[] = "x6mbnn9sz7";// Set password to "" for open networks.
WiFiClient client;
unsigned long myChannelNumber = 1604374; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "MUD3RH5J14A8UBFI"; //Your Write API Key

void setup()
{
Serial.begin(115200);
       delay(10);
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
int val = analogRead(POT_PIN); //Read Analog values and Store in val variable
Serial.println(val); //Print on Serial Monitor
delay(1000);
ThingSpeak.setField( 1,val);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey); //Update in ThingSpeak
delay(15000);//Update in ThingSpeak every 15 seconds
}
