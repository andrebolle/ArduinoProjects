void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  for (int x=0; x<10; x++) {
    Serial.print(x);
  }
  Serial.println("");
  delay(1000);
}
