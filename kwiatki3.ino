#include <WiFi.h>
#include <WiFiMulti.h>
#define PRZYCISK 2
void setup() {
  pinMode (PRZYCISK, INPUT_PULLUP);
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);


  WiFi.begin("ssid", "haslo");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Łączenie z WiFi...");
  }
  Serial.println("Połączono z WiFi");
  Serial.print("Adres IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {

}
