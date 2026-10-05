#include "kolko.h"

HTTPClient http;

void Kolko::setup() {
	Serial.begin(115200);
	WiFi.mode(WIFI_STA);
	WiFi.begin("TP-Link_3541", "Mechatronik31wxD");
	//Serial.println("Łączenie z WiFi...");
	while (WiFi.status() != WL_CONNECTED) delay(1000);
	//Serial.println(WiFi.localIP());
}

int Kolko::send (int i) {
  int ret;
	if (WiFi.status() == WL_CONNECTED) {		
		http.begin("http://gcygan.webd.pl/kolko/?w=" + String(i));
		if (http.GET() == HTTP_CODE_OK) {
			ret = 0;
		} else {
			ret = 1;
    }
		http.end();
	} else {
    ret = 2;
  }
  return ret;
}
