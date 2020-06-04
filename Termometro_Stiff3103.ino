# include "DHT.h"                 //DHT libreria
# define DHTPIN 11                 //Declaracion del DHT en el pin11
# define DHTTYPE DHT11            
DHT dht(DHTPIN, DHTTYPE);
# include "LiquidCrystal.h"            //libreria para controlar el LCD
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float t;                                    // medida de temperatura
//float h;                                   // Medida de humedad(No lo usare por que en este caso solo quiero la medida de la temperatura)

void setup(){                 
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.setCursor(1, 0);
  lcd.print("TEC MOTUL ");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  PROYECTO  ");
  lcd.setCursor(0, 1);
  lcd.print("  UNIDAD 4  ");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BRIAN STIFF ");
  lcd.setCursor(0, 1);
  lcd.print("CHIM PECH  ");
  delay(1500);
  lcd.clear();
  
  lcd.setCursor(1, 0);
  lcd.print("  GASPAR  ");
  lcd.setCursor(0, 1);
  lcd.print("  POOT BASTO  ");
  delay(1500);
  lcd.clear();
  
   
}

void loop()                         
{
  
  t = dht.readTemperature();
  if(t<36.0){
  lcd.setCursor(0, 1);
  lcd.print("Temp. Baja ");
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C.");
  delay(300);
  lcd.clear();
  
}
else{
  if(t>=37){
    lcd.setCursor(0, 1);
    lcd.print("Temp. Alta ");
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("C.");
    delay(300);
    lcd.clear();
    
    }
    else{
    lcd.setCursor(0, 1);
    lcd.print("Temp. Normal ");
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print("C.");
    delay(300);
    lcd.clear();
    
    }
    }  
}
