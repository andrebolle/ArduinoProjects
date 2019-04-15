int inputPin = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(13, OUTPUT);

}

int inputValue = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("inputValue is:");
  delay(100);
  inputValue = digitalRead(inputPin);
  if (inputValue == LOW) {
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
  Serial.print(inputValue);
}
