/*Need to call rainbowcycle() function in order to get a pulsing LED*/

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip3.numPixels(); i++) {
      //strip.Color(0, 20, 0), 50; // Green
      strip3.setPixelColor(i, Wheel(((i * 256 / strip3.numPixels()) + j) & 255));
    }
    strip3.show();
    delay(wait);
  }
}

/* Input a value 0 to 255 to get a color value.
 We make collor Green fade on and off
 We can control the color with the middle argument on strip.color()
 In order to decreae intensity of LED we fiddle with arguments here
 return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
 we we decrease 255 by increments of 85
 255 -WheelPos *3      Brightest
 170 -WheelPos *2
 85  -WheelPos *1      Less Bright
 We now divide 85 and 1 among the desired number( in this case 3)
 85/3 = 28.33     1/3 = .33
 28.3 - WheelPos*.33      Even less bright, Etc...*/

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip3.Color( 0, 21.25- WheelPos * .25, 0);

  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip3.Color( 0, 0, 0);

  } 
  else {
    WheelPos -= 170;
    return strip3.Color(0, WheelPos * .25, 0);

  }
}

