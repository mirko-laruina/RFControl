void setup() {
  // put your setup code here, to run once:
  Serial.begin(4800);
}

void loop() {
  // put your main code here, to run repeatedly:
  double temp;
  rfRead(temp);
  Serial.println(temp*100);
  delay(1000);
}
