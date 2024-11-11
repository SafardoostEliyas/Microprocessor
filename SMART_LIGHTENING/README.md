
# کنترل هوشمند روشنایی معابر

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و سنسور فوتوسل و برد Arduino میخواهیم لامپ LED روی برد بطور خودکار با تاریک شدن روشن و در نور خاموش شود.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- سنسور فوتوسل
- مقاومت

## طریقه انجام آزمایش (اتصالات):
- کد را در نرم‌افزار Arduino IDE اجرا کرده و روی برد آپلود میکنیم سنسور فوتوسل را به پین A0 متصل کرده مقدار سنجیده شده توسط فوتوسل را از طریق Serial Monitor مشاهده کرده و تغییرات در شرایط متفاوت را در LED میبینیم.

## تصاویر:
![schema_smart_lightening](https://github.com/user-attachments/assets/e5a742d6-472d-4540-975a-674d5009fad0)
![solarcell](https://github.com/user-attachments/assets/9d634206-94b1-469d-8e5d-178fedbadc2d)



## کد پروژه:
```cpp
#include <SevSeg.h>
SevSeg sevseg;
 
void setup()
{
      //Set to 1 for single digit display
      byte numDigits = 1;
   
      //defines common pins while using multi-digit display. Left empty as we have a single digit display
      byte digitPins[] = {};
   
      //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP
      byte segmentPins[] = {3, 2, 8, 7, 6, 4, 5, 9};
      bool resistorsOnSegments = true;
   
      //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
      sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
      //sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
   
      sevseg.setBrightness(90);
}
 
void loop()
{
     for (int i = 0; i < 10; i++)
        {
         sevseg.setNumber(i);
         sevseg.refreshDisplay();
         delay(2000);
  }
}
```

## طرز کار:
با اپلود برنامه و گرفتن یک لامپ روی فوتوسل LED خاموش و در شرایط تاریکتر روشن میشود.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان کنترل روشنایی معابر شهری را هوشمند سازی کزد. همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.