
#include <CayenneMQTTESP8266.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
// WiFi network info.
char ssid[] = "JioFi3_564B6F";
char Pass[] = "x6mbnn9sz7";

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "3f0f7260-4506-11ec-ad90-75ec5e25c7a4";
char password[] = "905de30f68c8b5905259506e89f89e1ab004216e";
char clientID[] = "d34b0780-5a61-11ec-ad90-75ec5e25c7a4";

#define RELAY_PIN 16
#define SENSOR_PIN 0 // Do not use digital pins 0 or 1 since those conflict with the use of Serial.
#define VC_1 1
#define VC_0 0
int previousState = -1;
int currentState = -1;
unsigned long previousMillis = 0;

void setup()
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  digitalWrite(RELAY_PIN,HIGH);
  Serial.begin(9600);
 Cayenne.begin(username, password, clientID, ssid, Pass);
}

void loop()
{
  Cayenne.loop();
  checkSensor();
}

void checkSensor()
{
  unsigned long currentMillis = millis();
  // Check sensor data every 250 milliseconds
  if (currentMillis - previousMillis >= 250) {
    // Check the sensor state and send data when it changes.
    currentState = digitalRead(SENSOR_PIN);
    if (currentState != previousState) {
      Cayenne.virtualWrite(VC_1, currentState, "digital_sensor", "d");
      previousState = currentState;
    }
    previousMillis = currentMillis;
  }
}
// This function is called when data is sent from Cayenne.
CAYENNE_IN(VC_0)
{
  // Write value to turn the relay switch on or off. This code assumes you wire your relay as normally open.
  int value = getValue.asInt();
  if (value) {
    digitalWrite(RELAY_PIN, LOW);
  }
  else {
    digitalWrite(RELAY_PIN,HIGH);
  }
}
