bool sparkle(uint8_t wait) {
  // Setup the pixel array
  int pixel[60];
  for (int p = 0; p < 60; p++) {
    pixel[p] = random(0, 255);
  }

  // Run some snowflake cycles
  for (int j = 0; j < 200; j++) {

    // Every five cycles, light a new pixel
    if ((j % 5) == 0) {
      strip.setPixelColor(random(0, 60), 255, 255, 255);
    }

    // Dim all pixels by 10
    for (int p = 0; p < 60; p++) {
      strip.setPixelColor(p, pixel[p], pixel[p], pixel[p] );
      pixel[p] =  pixel[p] - 10;
    }
    strip.show();

    if(buttonDelay(wait) == true){
      return true;
      } 
  }
return false;
}
