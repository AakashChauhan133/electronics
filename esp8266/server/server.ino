#include<ESP8266WiFi.h>
#define led D5

WiFiClient client;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  WiFi.begin("wifia", "aakash7807263226");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(">");
    delay(200);
  }
  Serial.println("");
  Serial.println("Connected");
  Serial.println(WiFi.localIP());
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
      digitalWrite(led, HIGH);
    }
    if (request == "GET /ledoff HTTP/1.1")
    {

      Serial.println("LOW");
      digitalWrite(led, LOW);
    }
  }
}
