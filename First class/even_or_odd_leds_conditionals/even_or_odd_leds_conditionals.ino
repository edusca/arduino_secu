int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin11 = 11;
int pin12 = 12;

void setup() {
  Serial.begin(9600);
  
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
}

/**
 * If is an even random number then turn on even pins numbers, else
 * turn on odd pin numbers.
 */
void loop() {
  int randomNumber = random(0, 100);
  Serial.println(randomNumber);
  
  int rest = randomNumber % 2;

  // If the rest is 0, the random number is even, odd otherwise
  if (rest == 0) {
    digitalWrite(pin8, HIGH);
    digitalWrite(pin10, HIGH);
    digitalWrite(pin12, HIGH);
    
    delay(1000);
  
    digitalWrite(pin8, LOW);
    digitalWrite(pin10, LOW);
    digitalWrite(pin12, LOW);
  } else {
    digitalWrite(pin9, HIGH);
    digitalWrite(pin11, HIGH);
    
    delay(1000);
  
    digitalWrite(pin9, LOW);
    digitalWrite(pin11, LOW);
  }

  delay(2000);
}
