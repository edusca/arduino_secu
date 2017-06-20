int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin11 = 11;
int pin12 = 12;

int pin3 = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);

  pinMode(pin3, INPUT);
}

/**
 * While loop and functions.
 */
void loop() {
  
  while(digitalRead(pin3) == HIGH) {
    turnLedsOneAtTime();
  }

  turnLedsAllAtTheSameTime();
  delay(200);
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
 * Turn on all leds at the same time.
 */
void turnLedsAllAtTheSameTime() {
  digitalWrite(pin8, HIGH);
  digitalWrite(pin9, HIGH);
  digitalWrite(pin10, HIGH);
  digitalWrite(pin11, HIGH);
  digitalWrite(pin12, HIGH);
  
  delay(200);

  digitalWrite(pin8, LOW);
  digitalWrite(pin9, LOW);
  digitalWrite(pin10, LOW);
  digitalWrite(pin11, LOW);
  digitalWrite(pin12, LOW);

  delay(200);
}

