#include <CayenneMQTTESP8266.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#define LED_PIN D0
#define VC_0 0
// WiFi network info.
char ssid[] = "JioFi3_564B6F";
char Pass[] = "x6mbnn9sz7";
// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "3f0f7260-4506-11ec-ad90-75ec5e25c7a4";
char password[] = "905de30f68c8b5905259506e89f89e1ab004216e";
char clientID[] = "fba4bf70-59ba-11ec-9f5b-45181495093e";
void setup() 
{
	Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  Cayenne.begin(username, password, clientID, ssid, Pass);
  Serial.println("");
  Serial.println("WiFi connected");
  pinMode(LED_PIN,OUTPUT);
}

void loop() 
{
	Cayenne.loop();
}
CAYENNE_IN(VC_0)
{
  if (getValue.asInt())
  {
	digitalWrite(LED_PIN,LOW);
  Serial.println("LED ON");
	}
 else
 {
  digitalWrite(LED_PIN,HIGH);
  Serial.println("LED OFF");
 }
}
