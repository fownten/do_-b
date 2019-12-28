#define pingPin  7
#define echoPin  6

void setup() {
  Serial.begin(9600);
}
 
 void loop() {
  long cm = echo();
  
  Serial.print(cm);
  Serial.println("cm");
    
  delay(100)
}
 
long echo(void) {
  long duration;
  pinMode(pingPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin,LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  return microsecondsToCentimeters(duration);
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds /29 / 2;
}
