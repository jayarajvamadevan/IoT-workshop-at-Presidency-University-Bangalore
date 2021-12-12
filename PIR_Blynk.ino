#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define PIR_Pin D3
#define LED_Pin 2
char auth[] = "_crdwPGWh_w2zeT5pqpiaF2IrXRLEdpa"; //Enter your Blynk application auth token
char ssid[] = "JioFi3_564B6F"; //Enter your WIFI name
char pass[] = "x6mbnn9sz7"; //Enter your WIFI passowrd
BlynkTimer timer;
int pinValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_Pin,OUTPUT);
  pinMode(PIR_Pin,INPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, motion_detect);
}

BLYNK_WRITE(V1) {
  pinValue = param.asInt();
}

void motion_detect()
{
  int sensor = digitalRead(PIR_Pin);
  Serial.println(sensor);
  if (pinValue) 
  {
    Serial.println("System is ON");
    if (sensor)
    {
      Blynk.notify("Motion detected...");
      digitalWrite(LED_Pin,LOW);
    } 
    else 
    {
      digitalWrite(LED_Pin,HIGH);
    }
  } 
  else 
  {
    Serial.println("System is OFF");
  }
}

void loop() 
{
  Blynk.run();
  timer.run();
}
