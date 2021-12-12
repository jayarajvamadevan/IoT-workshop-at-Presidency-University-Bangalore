#include <CayenneMQTTESP8266.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#define LED_PIN D0
#define VC_0 0
int x=0;
int y=0;
// WiFi network info.
char ssid[] = "JioFi3_564B6F";
char Pass[] = "x6mbnn9sz7";
// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "3f0f7260-4506-11ec-ad90-75ec5e25c7a4";
char password[] = "905de30f68c8b5905259506e89f89e1ab004216e";
char clientID[] = "bf3d84a0-46a9-11ec-ad90-75ec5e25c7a4";

void setup() 
{
	Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  Cayenne.begin(username, password, clientID, ssid, Pass);
  Serial.println("");3
	Cayenne.loop();
	Cayenne.virtualWrite(VC_0,0, "digital_sensor","d");
  digitalWrite(LED_PIN,HIGH);
  Serial.println("LED ON");
  delay(1000);
  Cayenne.virtualWrite(VC_0,1, "digital_sensor","d");
  digitalWrite(LED_PIN,LOW);
   Serial.println("LED OFF");
  delay(1000);
}
