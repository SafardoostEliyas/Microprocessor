#include <LiquidCrystal.h>



LiquidCrystal lcd(12,11,5,4,3,2);

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.createChar(0, heart);
  
  lcd.createChar(1, smiley);
  
  lcd.createChar(2, frownie);
  
  lcd.createChar(3, armsDown);
  
  lcd.createChar(4, armsUp);

 }

void loop() {
  
  int sensorReading = analogRead(A0);
  
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  
  for(int j=0;j<16;j++)
  {
    if (j > 0) {
      lcd.setCursor(j - 1, 0);
      lcd.write(' '); 
    }
    if(j%2==0)
    {
      lcd.setCursor(j, 0);
    lcd.write(3);
    delay(delayTime);
    }else{
       lcd.setCursor(j, 0);
    lcd.write(4);
    delay(delayTime);
    }
     
   
  
  }
  
  lcd.setCursor(15, 0);
  lcd.write(' '); 


  for(int j=15;j>=0;j--)
  {
    if (j >= 0) {
      lcd.setCursor(j + 1, 1);
      lcd.write(' '); 
    }
    
   if(j%2==0)
    {
      lcd.setCursor(j, 1);
    lcd.write(3);
    delay(delayTime);
    }else{
       lcd.setCursor(j, 1);
    lcd.write(4);
    delay(delayTime);
    }
  }
   lcd.setCursor(0, 1);
  lcd.write(' '); 
}