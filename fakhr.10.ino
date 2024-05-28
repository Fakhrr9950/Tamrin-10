#include"DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 8
#include<LiquidCrystal.h>//library code
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.begin(16,2);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float Temp=dht.readTemperature();
  int Humid=dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp:");//show temp
  lcd.print(Temp);//show temp
  lcd.print("*C");
  lcd.setCursor(0,1);
  lcd.print("Humid:");//shpw humidity
  lcd.print(Humid);//shpw humidity
  lcd.print("%");
  
//  lcd.setCursor(0,0);
  Serial.print("Temp:");
  Serial.print(Temp);
  Serial.print("*C");
 // lcd.setCursor(0,1);
  Serial.print("Humid:");
  Serial.print(Humid);
  Serial.print("%");
  
  
  delay(1000);//time
  lcd.clear();//clear
}
