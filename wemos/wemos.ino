#include <NTPClient.h>
// change next line to use with another board/shield
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "nelprro";
const char *password = "estalibre";
String hourString;
String minuteString;

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", -21600, 60000);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    //Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  if (timeClient.getHours() < 10) {
    hourString = "0" + String(timeClient.getHours());
  } else {
    hourString = String(timeClient.getHours());
  }
  if (timeClient.getMinutes() < 10) {
    minuteString = "0" + String(timeClient.getMinutes());
  } else {
    minuteString = String(timeClient.getMinutes());
  }
  String  tiempo = hourString + minuteString;
  Serial.println(tiempo);

  delay(1000);
}
