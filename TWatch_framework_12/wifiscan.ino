
// An advanced Time Display
// This is a drop-in replacement for the displayTime()
// In the original Instructable. s such, it redraws GUI
// every minute so you will see a little flicker.
#include <WiFi.h>

void wifiscan() {
  WiFi.mode(WIFI_STA);
  ttgo->tft->drawString("scan start", 66, 158, 1);
  WiFi.disconnect();
  delay(1000);
  ttgo->tft->fillScreen(TFT_BLACK);
  
  while (WiFi.status() != WL_CONNECTED) {
    
    int n = WiFi.scanNetworks();
    if (n == 0) {
        ttgo->tft->drawString("no networks found", 46, 100, 1);
    } else {
        ttgo->tft->drawNumber(n, 46, 50, 2);
        ttgo->tft->drawString(" networks found", 46, 80, 1);
        delay(200);
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            ttgo->tft->fillScreen(TFT_BLACK);
            delay(200);
            //ttgo->tft->drawString(": ", 22, 180, 2);
            ttgo->tft->drawNumber(i + 1, 20, 80, 1);
            ttgo->tft->drawString(WiFi.SSID(i), 22, 100, 1);
            ttgo->tft->drawNumber(WiFi.RSSI(i), 22, 120, 1);
            ttgo->tft->drawString((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*", 22, 120, 1);
            delay(400);
        }
    }

    delay(2000);

    ttgo->tft->fillScreen(TFT_BLACK);
    
    }
}
