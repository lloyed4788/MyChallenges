// Show the accelerometer working

void appAccel() {
  ttgo->bma->begin();
  ttgo->bma->enableAccel();
  ttgo->tft->fillScreen(TFT_BLACK);
  int16_t x, y;
  int16_t xpos, ypos;
  int16_t xprev, yprev;

  Accel acc;
  RTC_Date tnow = ttgo->rtc->getDateTime();
  ss = tnow.second;

  while (!ttgo->getTouch(x, y)) { // Wait for touch to exit

    ttgo->bma->getAccel(acc);
    xpos = acc.x;
    ypos = acc.y;
    xprev = xpos;
    yprev = ypos;
    ttgo->bma->getAccel(acc);
    xpos = acc.x;
    ypos = acc.y;
    ttgo->tft->fillCircle(xpos / 10 + 119, ypos / 10 + 119, 10, TFT_RED); // draw dot
    ttgo->tft->setTextColor(TFT_YELLOW);
    ttgo->tft->drawString("x :" + String(xpos), 20, 1, 2);
    ttgo->tft->setTextColor(TFT_GREENYELLOW);
    ttgo->tft->drawString("y :" + String(-ypos), 124, 1, 2);
    ttgo->tft->drawNumber(xpos - xprev, 30, 40, 2); // x difference, x position on the display, y position on the display, font size
    ttgo->tft->drawNumber(-(ypos - yprev), 114, 40, 2); // to define upward as positive y 
    delay(100);
    ttgo->tft->fillCircle(xpos / 10 + 119, ypos / 10 + 119, 10, TFT_BLACK); // erase previous dot  
    ttgo->tft->fillScreen(TFT_BLACK);
  }

  while (ttgo->getTouch(x, y)) {}  // Wait for release to return to the clock
  
  ttgo->tft->fillScreen(TFT_BLACK); // Clear screen
}
