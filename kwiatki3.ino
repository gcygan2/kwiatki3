#include <WiFi.h>
#include <TM1637Display.h>
#include <HTTPClient.h>

TM1637Display display(22, 21);
HTTPClient http;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("TP-Link_3541", "Mechatronik31wxD");
  Serial.println("Łączenie z WiFi");
  while (WiFi.status() != WL_CONNECTED) delay(1000);
  Serial.println(WiFi.localIP());
  display.setBrightness(5);
}
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin("http://gcygan.webd.pl/ob/ekran.php");
    if (http.GET() == HTTP_CODE_OK) {
      display.showNumberHexEx (http.getString().toInt());
    }
    http.end();
  }
  delay (2000);
}