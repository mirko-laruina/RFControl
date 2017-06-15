
void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);
  analogReference(INTERNAL);
}

void loop() {
  double temp = analogRead(0)*1.1/1023;
  rfWrite(temp);
  delay(1000);
}
