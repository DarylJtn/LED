bool TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne) {
  // setAll(0,0,0);

  for (int i = 0; i < Count; i++) {
    strip.setPixelColor(random(LED_COUNT), random(0, 255), random(0, 255), random(0, 255));
    strip.show();
    if (ButtonPush() == true) {
      return true;
    }
    if(buttonDelay(SpeedDelay) == true){
      return true;
      } 
    //delay(SpeedDelay);
    if (OnlyOne) {
      //setAll(0,0,0);
    }
  }

    if(buttonDelay(SpeedDelay) == true){
      return true;
      } 
  if (ButtonPush() == true) {
    return true;
  } else {
    return false;
  }
}
