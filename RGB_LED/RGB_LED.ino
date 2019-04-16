int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600); 
}

void loop()
{
  float r = (int)random(0, 16);
  float g = (int)random(0, 10);
  float b = (int)random(0, 8);
  float total = r + g + b;
  float brightness = 12;
  float rn = r/total * brightness;
  float gn = g/total * brightness;
  float bn = b/total * brightness;
  setColour((int)rn, (int)gn, (int)bn);
  Serial.println(rn+gn+bn); 
  delay(250);
}

void setColour(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
