#include <UTFT.h>

UTFT myGLCD(ILI9481,38,39,40,41);
int displayXSize = 0;
int displayYSize = 0;
int displayXHalfSize = 0;
int displayYHalfSize = 0;
int displayXQuartSize = 0;

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

const int margin = 2;
const int dashboardRectHeight = 30;
const int boxesHeight = 142;
const int textPadding = 2;
const int headerHeight = 34;
const int headerHeightMinusMargin = 32;

void setup() {
  myGLCD.InitLCD();
  myGLCD.clrScr();

  displayXSize = myGLCD.getDisplayXSize() - margin;
  displayYSize = myGLCD.getDisplayYSize() - margin;

  displayXHalfSize = displayXSize / 2;
  displayYHalfSize = displayYSize / 2;

  displayXQuartSize = displayYSize / 4;
}

/**
 * Show a control panel example.
 */
void loop() {
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);

  // Draw control panel
  myGLCD.drawRect(
    margin, 
    margin, 
    displayXSize, 
    dashboardRectHeight
  );
  myGLCD.setFont(BigFont);
  myGLCD.print("Panel de control", CENTER, margin + 5);

  // Draw first left panel
  myGLCD.drawRect(
    margin, 
    headerHeight, 
    displayXHalfSize, 
    headerHeightMinusMargin + boxesHeight
  );
  myGLCD.setFont(BigFont);
  myGLCD.print(
    "Temperatura:", 
    margin + textPadding, 
    headerHeight + textPadding
  );
  myGLCD.setFont(SevenSegNumFont);
  int temp = random(40, 50);
  myGLCD.printNumI(
    temp, 
    displayXQuartSize, 
    headerHeight + textPadding + 50
  );

  // Draw second left panel
  myGLCD.drawRect(
    margin, 
    headerHeight + boxesHeight, 
    displayXHalfSize, 
    headerHeightMinusMargin + boxesHeight + boxesHeight
  );
  myGLCD.setFont(BigFont);
  myGLCD.print(
    "Voltaje-Fase 1", 
    margin + textPadding, 
    headerHeight + boxesHeight + textPadding
  );
  myGLCD.setFont(SevenSegNumFont);
  int voltagePhase1 = random(190, 250);
  myGLCD.printNumI(
    voltagePhase1, 
    displayXQuartSize, 
    headerHeight + boxesHeight + textPadding + 50
  );

  // Draw first right panel
  myGLCD.drawRect(
    displayXHalfSize + margin, 
    headerHeight, 
    displayXSize, 
    headerHeightMinusMargin + boxesHeight
  );
  myGLCD.setFont(BigFont);
  myGLCD.print(
    "Voltaje-Fase 2", 
    displayXHalfSize + margin + textPadding, 
    headerHeight + textPadding
  );
  myGLCD.setFont(SevenSegNumFont);
  int voltagePhase2 = random(190, 250);
  myGLCD.printNumI(
    voltagePhase2, 
    displayXHalfSize + displayXQuartSize, 
    headerHeight + textPadding + 50
  );

  // Draw second right panel
  myGLCD.drawRect(
    displayXHalfSize + margin, 
    headerHeightMinusMargin + boxesHeight + margin,
    displayXSize, 
    headerHeightMinusMargin + boxesHeight + boxesHeight
  );
  myGLCD.setFont(BigFont);
  myGLCD.print(
    "Voltaje-Fase 3",
    displayXHalfSize + margin + textPadding,
    headerHeightMinusMargin + boxesHeight + margin + textPadding
  );
  myGLCD.setFont(SevenSegNumFont);
  int voltagePhase3 = random(190, 250);
  myGLCD.printNumI(
    voltagePhase3, 
    displayXHalfSize + displayXQuartSize, 
    headerHeight + textPadding + 50 + boxesHeight
  );
  
  delay(1000);
}
