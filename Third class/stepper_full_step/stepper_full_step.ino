int bluePhase = 8;
int pinkPhase = 9;
int yellowPhase = 10;
int orangePhase = 11;

int currentStep = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(bluePhase, OUTPUT);
  pinMode(pinkPhase, OUTPUT);
  pinMode(yellowPhase, OUTPUT);
  pinMode(orangePhase, OUTPUT);

  initPhasesToCero();
}

void loop() {
  switch(currentStep) {
    case 0:
      digitalWrite(bluePhase, HIGH);
      digitalWrite(pinkPhase, HIGH);
      digitalWrite(yellowPhase, LOW);
      digitalWrite(orangePhase, LOW);
    break;

    case 1:
      digitalWrite(bluePhase, LOW);
      digitalWrite(pinkPhase, HIGH);
      digitalWrite(yellowPhase, HIGH);
      digitalWrite(orangePhase, LOW);
    break;

    case 2:
      digitalWrite(bluePhase, LOW);
      digitalWrite(pinkPhase, LOW);
      digitalWrite(yellowPhase, HIGH);
      digitalWrite(orangePhase, HIGH);
    break;

    case 3:
      digitalWrite(bluePhase, HIGH);
      digitalWrite(pinkPhase, LOW);
      digitalWrite(yellowPhase, LOW);
      digitalWrite(orangePhase, HIGH);
    break;
  }

  currentStep++;
  currentStep = (currentStep < 4) ? currentStep : 0;

  delay(2);
}

void initPhasesToCero() {
  digitalWrite(bluePhase, LOW);
  digitalWrite(pinkPhase, LOW);
  digitalWrite(yellowPhase, LOW);
  digitalWrite(orangePhase, LOW);
}

