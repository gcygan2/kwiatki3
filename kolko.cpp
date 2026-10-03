#include "kolko.h"

HTTPClient http;

void Kolko::setup() {
	Serial.begin(115200);
	WiFi.mode(WIFI_STA);
	WiFi.begin("TP-Link_3541", "Mechatronik31wxD");
	Serial.println("Łączenie z WiFi...");
	while (WiFi.status() != WL_CONNECTED) delay(1000);
	Serial.println(WiFi.localIP());
}

void Kolko::loop() {
	if (WiFi.status() == WL_CONNECTED) {
		static int i = 0;
		http.begin("http://gcygan.webd.pl/kolko/?w=" + String(i++));
		if (http.GET() == HTTP_CODE_OK) {
			Serial.println(http.getString());
		}
		http.end();
	}
	delay(10000);
}
