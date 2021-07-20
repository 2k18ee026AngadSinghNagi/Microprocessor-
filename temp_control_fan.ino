/* ProjectsDunia
   http://projectsdunia.blogspot.in
   Arduino Digital Thermometer */
#include<LiquidCrystal.h>
int A=0;
int B;
int sensorpin=A0;
int fan= 13; 
int min_temp=28;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2);
  pinMode(fan,OUTPUT);
 }
void loop()
{
  A= analogRead(sensorpin); // get the temprature
  B= (A/2);
  if(A < min_temp )   // if temprature is lower than minimum temp
  {
    digitalWrite(fan, LOW);
    lcd.setCursor(0,0);
    lcd.print("FAN IS OFF");
  }
  if(A > min_temp)
  {
    digitalWrite(fan, HIGH);
    lcd.setCursor(0,0);
    lcd.print("FAN IS ON");
  }
}


