#include <SoftwareSerial.h>

#define ledPin 7
#define rxPin  2
#define txPin  3

int state = 0;
SoftwareSerial bluetooth(rxPin,txPin);

void setup() {
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin, LOW);
  
  // Initialize Serial USB for debugging
  Serial.begin(9600);
  Serial.println("Serial ready");
  
  // Initialize the bluetooth
  bluetooth.begin(9600);
  bluetooth.println("Bluetooth ready");
}

void loop() {
  if(bluetooth.available() > 0) {
    state = bluetooth.read();
    Serial.println(state, BIN);
  }

  if (state == '0') {
    digitalWrite(ledPin,LOW);
  }
  else if (state == '1') {
    digitalWrite(ledPin,HIGH); 
  }

  delay(10);
}
