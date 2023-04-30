#include<ESP8266WiFi.h>

int led = 2;

WiFiClient client;
WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  WiFi.softAP("CONTROL_UNIT", "aakash123");
  Serial.println();
  Serial.println("Control Unit Started");
  Serial.println(WiFi.softAPIP());
  server.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  client = server.available();
  if (client == 1)
  {
    String request = client.readStringUntil('\n');
    request.trim();
    Serial.println(request);
    if (request == "GET /ledon HTTP/1.1")
    {
      Serial.println("HIGH");
      digitalWrite(led, LOW);
    }
    if (request == "GET /ledoff HTTP/1.1")
    {
      
      Serial.println("LOW");
      digitalWrite(led, HIGH);
    }
  }
}
