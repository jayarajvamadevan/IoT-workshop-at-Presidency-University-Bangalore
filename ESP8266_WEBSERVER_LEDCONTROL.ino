#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#define ledpin 2
ESP8266WebServer server; 
const char* ssid = "JioFi3_564B6F";
const char* pass = "x6mbnn9sz7";
int i,j,k,l;
void setup() {
  pinMode(ledpin,OUTPUT);
  WiFi.begin(ssid,pass);
  Serial.begin(115200);
  while(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
}
Serial.println("");
Serial.print(" The address is:");
Serial.print(WiFi.localIP());
server.on("/blink",a1);
server.on("/fade",a2);
server.on("/candle",a3);
server.begin();
}
void loop() 
{
 server.handleClient(); 
}
void a1()
{
  server.send(200,"text/plain","LED blinking Started");
  for(i=0;i<10;i++)
  {
  digitalWrite(ledpin,HIGH);
  delay(1000);
  digitalWrite(ledpin,LOW);
  delay(1000);
  }
}
void a2() 
{ 
   server.send(200,"text/plain","LED Fade Started");
   for(i=0;i<10;i++)
   {
      for(j = 0 ; j <= 255; j+=5) // fade in (from min to max) 
      { 
        analogWrite(ledpin, j);           // sets the value (range from 0 to 255) 
        delay(30);                            // waits for 30 milli seconds to see the dimming effect 
      } 
      for(j = 255; j >=0; j-=5)  // fade out (from max to min) 
      { 
        analogWrite(ledpin, j); 
        delay(30); 
      } 
   }
}
void a3()
{
   server.send(200,"text/plain","Candle Effect Started");
   for(i=0;i<100;i++)
   {
      k = random(0,255);       // pick a random number between 50 and 255
      analogWrite(ledpin, k);    // set the LED brightness
      l = random(30,100);   // pick a random number between 30 and 100
      delay(l);             // delay that many milliseconds
   }
    
}
