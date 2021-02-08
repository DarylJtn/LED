bool meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) {  
 
 
  for(int i = 0; i < LED_COUNT+LED_COUNT; i++) {
   
   
    // fade brightness all LEDs one step
    for(int j=0; j<LED_COUNT; j++) {
      if( (!meteorRandomDecay) || (random(10)>5) ) {
        fadeToBlack(j, meteorTrailDecay );        
      }
    }
   
    // draw meteor
    for(int j = 0; j < meteorSize; j++) {
      if( ( i-j <LED_COUNT) && (i-j>=0) ) {
        strip.setPixelColor(i-j, red, green, blue);
      }
    }
      if (ButtonPush() == true) {
      return true;
    }
    strip.show();
    delay(SpeedDelay);
  }
  return false;
}

void fadeToBlack(int ledNo, byte fadeValue) {
 #ifdef ADAFRUIT_NEOPIXEL_H
    // NeoPixel
    uint32_t oldColor;
    uint8_t r, g, b;
    int value;
   
    oldColor = strip.getPixelColor(ledNo);
    r = (oldColor & 0x00ff0000UL) >> 16;
    g = (oldColor & 0x0000ff00UL) >> 8;
    b = (oldColor & 0x000000ffUL);

    r=(r<=10)? 0 : (int) r-(r*fadeValue/256);
    g=(g<=10)? 0 : (int) g-(g*fadeValue/256);
    b=(b<=10)? 0 : (int) b-(b*fadeValue/256);
   
    strip.setPixelColor(ledNo, r,g,b);
 #endif
 #ifndef ADAFRUIT_NEOPIXEL_H
   // FastLED
   leds[ledNo].fadeToBlackBy( fadeValue );
 #endif  
}
