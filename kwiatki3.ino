#include <WiFi.h>
#include <HTTPClient.h>
HTTPClient http;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("TP-Link_3541", "Mechatronik31wxD");
  Serial.println("Łączenie z WiFi...");
  while (WiFi.status() != WL_CONNECTED) delay(1000);
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin("http://gcygan.webd.pl/kolko/?w=12.5");
    if (http.GET() == HTTP_CODE_OK) {
      Serial.println(http.getString());
    }
    http.end();
  }
  delay(2000);
}
