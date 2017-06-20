int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin11 = 11;
int pin12 = 12;

void setup() {
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
}

/**
 * Turn on one led at time
 */
void loop() {
  
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
