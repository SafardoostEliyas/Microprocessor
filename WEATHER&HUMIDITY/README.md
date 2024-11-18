
# تشخیص رطوبت و دمای محیط

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و سنسور و برد Arduino میخواهیم دما ورطوبت محیط را از یک سنسور گرفته و محاسبه کنیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- سنسور Humidity&Temperature
- سیم رابط
- مقاومت

## طریقه انجام آزمایش (اتصالات):
- کد برنامه را در نرم‌افزار Arduino IDE اجرا کرده و سنسور و مقاومت را به برد متصل کرده و پس از آپلود کد ، دمای و رطوبت محیط را اندازه گرفته و در سیستم نمایش می دهد.

## تصاویر:

![Humidity](https://github.com/user-attachments/assets/c31b43c8-767e-4b7b-8e63-95b87f2b5e8f)
![HumiditySensorArduinoSchema](https://github.com/user-attachments/assets/91e5eed8-2370-4f16-9e9f-0e00a79f02ef)
![HumidityShow](https://github.com/user-attachments/assets/05e5e86d-ca20-46d5-ba4a-ba49af50ccc5)



## کد پروژه:
```cpp
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

 
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  Serial.print("رطوبت: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("دما: ");
  Serial.print(temperature);
  Serial.println(" *C");

  delay(2000);
}
```

## طرز کار:
با نصب سنسور و مقاومت و آپلود کد میتوانیم رطوبت و دمای محیط را در Serial monitor به ترتیب بر حسب درصد و سلسیوس مشاهده کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه رطوبت و دمای محیط را محاسبه کرده و در سیستم نمایش دهیم و از آن برای ساخت انواع سنسور های گلخانه ای دمای خانه و ... استفاده کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino و مشاهده آن در Serial Monitor انجام شده است.