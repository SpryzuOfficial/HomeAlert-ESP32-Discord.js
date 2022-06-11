#include <WiFi.h>
#include <HTTPClient.h>
#include <SPI.h>

const char* ssid = "--";
const char* password = "--";

const int PIN_TO_SENSOR = 19;

int pinStateCurrent = LOW;
int pinStatePrevious = LOW;

void setup() 
{
  Serial.begin(115200);

  SPI.begin();

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");

  pinMode(PIN_TO_SENSOR, INPUT);
}

void loop() 
{
  pinStatePrevious = pinStateCurrent;
  pinStateCurrent = digitalRead(PIN_TO_SENSOR);
  
  if (pinStatePrevious == LOW && pinStateCurrent == HIGH)
  {
    Serial.println("Motion detected!");
    if(WiFi.status()== WL_CONNECTED)
    {
      WiFiClient client;
      HTTPClient http;

      String serverName = "http://192.168.100.8:8080/alert/send";
      
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      String httpRequestData = "";
      int httpResponseCode = http.POST("");

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      Serial.println(http.getString());
    }
    else 
    {
      Serial.println("WiFi Disconnected");
    }
  }
  else if (pinStatePrevious == HIGH && pinStateCurrent == LOW)
  {
    Serial.println("Motion stopped!");
  }
}
