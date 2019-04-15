
String a;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial.println("Enter two numbers a, b then click the Send button.");
}

void loop() {
    while(Serial.available() > 0) {
      int a = Serial.parseInt();
      int b = Serial.parseInt();
      Serial.print(a);
      Serial.print(" plus ");
      Serial.print(b);
      Serial.print(" is ");
      Serial.println(a + b);
      Serial.print(a);
      Serial.print(" times ");
      Serial.print(b);
      Serial.print(" is ");
      Serial.println(a * b);
    }
}


/*
int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  // reply only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    // incomingByte = Serial.read();
    incomingByte = Serial.parseInt();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }
}
*/
