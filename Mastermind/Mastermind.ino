#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

String numero_azar;
char cifra_jugador[4]; //Stores the player's number
String numero_jugador = String();

String a1 = String();
String b1 = String();
String c1 = String();
String d1 = String();
String k = String();
String l = String();
String m = String();
String n = String();

int count=0;
int aleatorio[4];
int i,j,x;
int cows,bulls=0;
int tries=0;
int maximo_tries=5;

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};
byte rowPins[ROWS] = {13,6,5,4}; //Filas(pines del 9 al 6)
byte colPins[COLS] = {3,2,1,0}; //Columnas (pines del 5 al 2)
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Checks there are not duplicate
boolean check_duplicate(String palabra)
{
  for(i=0;i<=3;i++)
  {
      for(j=0;j<=3;j++)
      {
        if(i !=j)
        {
          if(palabra[i]==palabra[j])
          {
            return false;
            break;
          }
        }

      }
  }
        return true;  
}
//**************************************************************************************************
void start()
{
  lcd.clear();
  
  do
  {
    set_random();
    
  } while(check_duplicate(numero_azar)!=true);
  
    lcd.setCursor(0,0);
    lcd.print("Press 4 digits");
    tries=0;
    cows=0;
    bulls=0;
}

//************************************************************************************************
void set_random()
{
  
  for(x=0;x<=3;x++)
  {
    randomSeed(analogRead(analogRead(x)));
    
    aleatorio[x]=random(9);  //genera un número aleatorio entre 0 y 9
  }
   
   numero_azar = String(aleatorio[0])+String(aleatorio[1])+String(aleatorio[2]+String(aleatorio[3])); 
   
}
//************************************************************************************************
void enter()
{
  if(count==4)  //Si tiene 4 dígitos
  {
     k=String(cifra_jugador[0]);
     l=String(cifra_jugador[1]);
     m=String(cifra_jugador[2]);
     n=String(cifra_jugador[3]);
      
    numero_jugador = k+l+m+n;
    
    if(check_duplicate(numero_jugador))  //Si no contiene duplicados llamo al procedimiento que compara los dígitos
    {
      check();
    }
  
  }
  
  else
  
  {
    lcd.setCursor(0,0);
    lcd.print("Cifras incompletas");
    
  }
    
  count=0;  
  
}
//********************************************************************
void check()
 {
   a1=String(aleatorio[0]);
   b1=String(aleatorio[1]);
   c1=String(aleatorio[2]);
   d1=String(aleatorio[3]);
    
    if(a1==k)   {bulls++;}
     
    if(b1==l)   {bulls++;}
    
    if(c1==m)   {bulls++;}
    
    if(d1==n)   {bulls++;}
    
    if(a1==l || a1==m || a1==n) { cows++;}
    if(b1==k || b1==m || b1==n) { cows++;}
    if(c1==k || c1==l || c1==n) { cows++;}
    if(d1==k || d1==l || d1==m) { cows++;}
    
    
    tries++;
    
        
    if(bulls==4)
    {
      
      lcd.clear();
      lcd.print("You won in: ");
      lcd.print(tries);
      lcd.setCursor(0,1);
      lcd.print( "tries");
      delay(2000);
      start();
      
    }
    
    update_display();  //Muestra la información en pantalla
    
    if(tries==maximo_tries)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.write("You lost, the");
      lcd.setCursor(0,1);
      lcd.print("number was: ");
      lcd.print(a1);
      lcd.print(b1);
      lcd.print(c1);     
      lcd.print(d1);    
    }
    
    count=0;
    cows=0;
    bulls=0;
    
  }

//*******************************************
void update_display()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cows:");
    lcd.print(cows);
    
    lcd.setCursor(8,0);
    lcd.print(" Bulls:");
    lcd.print(bulls);
    
    lcd.setCursor(9,1);
    lcd.print("Try:");
    lcd.print(tries);
    lcd.print("/5");
    
    lcd.setCursor(0,1);
    lcd.blink();
}
//*******************************************
void setup() 
{
  lcd.begin(16, 2);
  start();
}

//*******************************************
void loop()
{
char key = keypad.getKey();

  if(key) 
  {
    switch (key)
    {
      case 'A':
      start();  //Starts a new game
      break;
      
      case 'B':
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Bye, then number ");
      lcd.setCursor(0,1);
      lcd.print("was the: ");
      lcd.print(numero_azar);
      break;
      
      case 'D':
      enter();  //Enter
      break;
      
    }
  }

  if(key) 
  {
    cifra_jugador[count] = key;
    
    //Si la tecla presionada es un número (ignore las letras) 
    if(key!='A' && key!='B' && key!='C' && key!='D')
    {
      lcd.setCursor(0+count,1);
      lcd.print(cifra_jugador[count]);
     
      count++;
    }
       
     
  }

}
