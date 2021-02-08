bool white() {
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, 255, 255, 255);
strip.show();
  }
   
  while (true) {
     delay(10);
    if (ButtonPush() == true) {
      return true;
    }
  }
}
