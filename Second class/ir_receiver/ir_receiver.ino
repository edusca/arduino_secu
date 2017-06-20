#include <IRremote.h>

int RECV_PIN=11;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup() {
  Serial.begin(9600);
  // Start the IR receiver
  irrecv.enableIRIn();

  //define LED pins as output
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 0x92DF9279) {
      digitalWrite(pin7, HIGH);
      enableLock();
    }

    if (results.value == 0x87CDD0EF) {
      digitalWrite(pin6, HIGH);
    }

    if (results.value == 0x37788763) {
      digitalWrite(pin5, HIGH);
    }

    if (results.value == 0x736ED82E || results.value == 0x20DF10EF) {
        digitalWrite(pin5, LOW);
        digitalWrite(pin6, LOW);
        digitalWrite(pin7, LOW);
        disableLock();
    }
    Serial.println(results.value, HEX);
    delay(100); 
    irrecv.resume();
  }
}

void enableLock() {
  digitalWrite(pin4, HIGH);
}

void disableLock() {
   digitalWrite(pin4, LOW);
}

