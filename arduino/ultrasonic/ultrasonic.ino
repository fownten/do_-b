#define pingPin  7
#define echoPin  6

void setup() {
  Serial.begin(9600);
}
 
 void loop() {
  
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
