/*
 *  Author: Aakash Chauhan
 *  Date: April 30, 2023
 *  Signal Strength in percentage
 */
 
#include<ESP8266WiFi.h>


WiFiClient client;
WiFiServer server(80);
float strength, dbm;

void setup() {
  Serial.begin(9600);

  //  Connection
  WiFi.begin("wifi", "aakash123");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(WiFi.status());
    delay(200);
  }
  Serial.println("");
  Serial.println("Connected");
  Serial.println(WiFi.localIP());
  server.begin();
  
}

void loop() {
  dbm = WiFi.RSSI();

  //  if Connection is lost
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Disconnnected");
  }
  
  else{
    Serial.print("Signal: ");
    if (dbm < -100)
      Serial.println("0.00%");
    else if (dbm > -50)
      Serial.println("100.00%");
    else
    {
      strength =  2 * (dbm + 100);
      Serial.print(strength);
      Serial.println("%");
    }
  }
  delay(1000);
}
