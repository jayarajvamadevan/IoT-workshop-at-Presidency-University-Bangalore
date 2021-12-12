#include <CayenneMQTTESP8266.h>
#include <DHT.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#define VC_0 0
#define VC_1 1
#define DHT_PIN 0
// WiFi network info.
char ssid[] = "JioFi3_564B6F";
char Pass[] = "x6mbnn9sz7";
// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "3f0f7260-4506-11ec-ad90-75ec5e25c7a4";
char password[] = "905de30f68c8b5905259506e89f89e1ab004216e";
char clientID[] = "c9aa9980-59bb-11ec-9f5b-45181495093e";
DHT dht(DHT_PIN,DHT11);
void setup() {
   Serial.begin(115200);
       delay(10);
       dht.begin();
       Serial.println("Connecting to ");
       Serial.println(ssid);
       Cayenne.begin(username, password, clientID, ssid, Pass);
      Serial.println("");
      Serial.println("WiFi connected");
}
void loop() {
	Cayenne.loop();
 float hum = dht.readHumidity();
 float temp = dht.readTemperature();  
Cayenne.virtualWrite(VC_0,temp, "temp ", "c");
Cayenne.virtualWrite(VC_1,hum, "rel_hum  ", "p");
Serial.print("HUMIDITY:"); //Print on Serial Monitor
Serial.print(hum); 
Serial.print("\t TEMPERATURE:"); //Print on Serial Monitor
Serial.print(temp); 
Serial.println(" ");
delay(1000);
}
