
//Distance LED uses strip2 
void DistanceColorSwitch(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<40; i++) {
      strip2.setPixelColor(i, c);
      strip2.show();
      delay(wait);
  }
}

//Temp LED uses strip 
void TempColorSwitch(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<40; i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

//Notice we reduced the for loop so that it takes less
//time to pulse and therefore better for use with ultrasonic sensro.
