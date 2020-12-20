#include <Arduino.h>
#include <ESP8266WiFi.h>

#define SSID = "wifi_name"
#define PASSWORD = "wifi_pass"

#define HOST =  //host ip
#define PORT = 5050 //server port

void setup() {
    Serial1.begin(115200); //setting baudrate

    //Connecting to the wifi
    Serial.println();
    Serial.println(); //clearing the serial monitor
    Serial.printf("Connecting to %s \r\n", SSID);

    WiFi.mode(WIFI_STA); //set mode to station i.e connecting
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.println(".");
    }

    Serial.println();
    Serial.println("WIFI connected");

}

void loop() {
    Serial.printf("Connecting to %s on port %d\r\n", HOST, PORT);

    //creating TCP client
    WiFiClient client;
    if( !client.connect(HOST, PORT)){
      Serial.printf("Unable to connect to %s\r\n", HOST);
      delay(500); //retry after 5 seconds
      return;
    }

    //receive data from server char by char
    Serial.println("receiving data from server...");
    while (client.available()){
      char c = static_cast<char>(client.read());
      Serial.printf("%c\r\n", c);
    }

Serial.println();

//closing socket
client.stop();

delay(5000); //wait 5 seconds
return;

}