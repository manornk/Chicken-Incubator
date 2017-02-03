#include <dht11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20, 4);
dht11 DHT11;
  float minTemp = 100;
  int relay = 3;
#define DHT11PIN 2

void setup()
{
  lcd.init(); 
  lcd.init();
  lcd.backlight();
  pinMode(relay, OUTPUT);
}

void loop()
{
  DHT11.read(DHT11PIN);
    lcd.backlight();

  float hum = (float)DHT11.humidity;
  float temp = (float)DHT11.temperature;
  
  if(temp <=38.00) {
   digitalWrite(relay, HIGH);
   
  } else {
    digitalWrite(relay,LOW);
  }
  
  lcd.setCursor(1,0);
  lcd.print("Temperatura:");
  lcd.setCursor(14,0);
  lcd.print(temp);
  
  lcd.setCursor(1,1);
  lcd.print("Vlaznost:");  
  lcd.setCursor(14,1);
  lcd.print(hum);
  
  
  delay(5000);
  lcd.clear();
  
}

