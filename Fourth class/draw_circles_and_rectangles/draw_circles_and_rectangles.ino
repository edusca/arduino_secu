#include <UTFT.h>

UTFT myGLCD(ILI9481,38,39,40,41);
int x = 0;
int x1 = 0;
int y = 0;
int y1 = 0;
int r = 0;
int g = 0;
int b = 0;
int radio = 0;
int counter = 0;

/*
 * If showCircles = 0 circles will be drawn, otherwise rectangles
 */
int showCircles = 0;

void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();
}

/**
 * An example to show basic shapes in LCD.
 * This will change after 5 seconds (Delay = 100, counter up to 50).
 */
void loop() {
  // Set background color to black
  myGLCD.setBackColor(0, 0, 0);
  
  // Random x,y points
  x = random(0, 480);
  x1 = random(0, 480);
  y = random(0, 320);
  y1 = random(0, 320);

  // Random colors
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);

  myGLCD.setColor(r, g, b);
  
  if (showCircles == 1) {
    myGLCD.drawRect(x, x1, y, y1);
  }
  if (showCircles == 0) {  
    radio = random(0, 50);
    myGLCD.drawCircle(x, y, radio);
  }
  delay(100);
  counter++;

  if (counter == 50 ) {
      myGLCD.clrScr();
      counter = 0;
      if (showCircles == 0) {
        showCircles = 1;
      } else {
        showCircles = 0;
      }
  }
}
