int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

void loop()
{
  int brightness = 1;
  float r = (int)random(0, 16 * brightness);
  float g = (int)random(0, 10 * brightness);
  float b = (int)random(0, 8 * brightness);
  float total = r + g + b;
  float rn = r/total * 16;
  float gn = g/total * 16;
  float bn = b/total * 16;
  setColour((int)rn, (int)gn, (int)bn);
  delay(250);
}

void setColour(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
