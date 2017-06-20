/**
 * Interrupt pins - Boards:
 * Board Digital Pins Usable For Interrupts
 * Uno, Nano, Mini, other 328-based -> 2, 3
 * Mega, Mega2560, MegaADK -> 2, 3, 18, 19, 20, 21
 * Micro, Leonardo, other 32u4-based -> 0, 1, 2, 3, 7
 * Zero -> all digital pins, except 4
 * MKR1000 Rev.1 -> 0, 1, 4, 5, 6, 7, 8, 9, A1, A2
 * Due -> all digital pins
 * 101 -> all digital pins
 */

int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin11 = 11;
int pin12 = 12;

int pin3 = 3;

void setup() {
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);

  pinMode(pin3, INPUT);

  attachInterrupt(
    digitalPinToInterrupt(pin3), 
    turnOnSimulatingMachineError, 
    RISING
  );
}

/**
 * Interrupt example.
 */
void loop() {
  turnLedsOneAtTime();
}

/**
 * Turn on one led at time
 */
void turnLedsOneAtTime() {
  digitalWrite(pin8, HIGH);
  delay(100);
  
  digitalWrite(pin8, LOW);
  digitalWrite(pin9, HIGH);

  delay(100);

  digitalWrite(pin9, LOW);
  digitalWrite(pin10, HIGH);

  delay(100);

  digitalWrite(pin10, LOW);
  digitalWrite(pin11, HIGH);

  delay(100);

  digitalWrite(pin11, LOW);
  digitalWrite(pin12, HIGH);

  delay(100);

  digitalWrite(pin12, LOW);
}

/**
 * When the interrupt occurs turn the leds on to
 * simulate a machine error.
 */
void turnOnSimulatingMachineError() {
  digitalWrite(pin8, HIGH);
  digitalWrite(pin9, HIGH);
  digitalWrite(pin10, HIGH);
  digitalWrite(pin11, HIGH);
  digitalWrite(pin12, HIGH);

  /**
   * Infinite loop, the only way to continue the
   * program is restarting the Arduino board.
   */
  while(true){}
}

