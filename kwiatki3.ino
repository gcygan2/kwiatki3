#include <WiFi.h>

#define PRZYCISK 2

void setup() {
  pinMode (PRZYCISK, INPUT_PULLUP);
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin("ssid", "haslo");
  Serial.println("Łączenie z WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Połączono z WiFi");
  Serial.print("Adres IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {

}
