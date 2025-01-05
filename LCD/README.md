
# نمایش اشکال مختلف در LCD

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و LCD و برد Arduino میخواهیم اجسام مختلف را نشان دهیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- صفحه LCD 2*16
- سیم رابط

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و LCD را به برد متصل کرده و پس از آپلود کد ، اجسام مختلف نمایش داده خواهند شد.

## تصاویر:
![1000269542](https://github.com/user-attachments/assets/86f7380e-2f55-4d44-a4e2-533bd4591896)
![1000269550](https://github.com/user-attachments/assets/49202f80-983d-4c3d-9f08-419a4326565e)



## کد پروژه:
```cpp
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
```

## طرز کار:
با نصب LCD و آپلود کد میتوانیم اشکال مختلف را روی LCD مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان اجسام را روی LCD نمایش داده و از آن برای ساخت انواع صفحه نمایش نشان دهنده مقادیر و فرامین و ... استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.