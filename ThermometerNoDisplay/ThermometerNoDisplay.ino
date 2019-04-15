int    tempPin = 0;
String spaces  = String("                                                                ");

unsigned long previousMillis = 0;

const long interval = 500;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
}


unsigned long currentMillis;

void loop()
{
  currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    int tempReading = analogRead(tempPin);

    //  Convert to Kelvin
    double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
    tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK)) * tempK); 

    // Convert Kelvin to Celcius
    float tempC = tempK - 273.15; 

    Serial.print(spaces.substring(0, (int)((tempC - 13.0) * 2.0)));
    Serial.print("*  ");
    Serial.println(tempC);
  }
}
