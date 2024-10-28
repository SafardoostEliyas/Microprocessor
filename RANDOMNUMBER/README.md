
# تولید عدد تصادفی در Serial Monitor و روشن کردن LED آن

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و برد Arduino و LED بطور تصادفی اعدادی را چاپ کرده و لامپ متناظر با ان را روشن کنیم.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- لامپ های LED
- سیم‌های رابط
- مقاومت 220 اهم
- دکمه فشاری

## طریقه انجام آزمایش (اتصالات):
- لامپ ها , مقاومت ها و دکمه را روی برد بورد قرار داده و از ان طرف نیز به برد اردوینو متصل میکنیم.(مانند شکل)
## تصاویر:
![random_num](https://github.com/user-attachments/assets/96ee101f-14ed-4f47-bba7-43826c66aaeb)
![dancing_light](https://github.com/user-attachments/assets/d9a8b311-98b2-4bb7-b6e0-60b9a0ec11eb)


## کد پروژه:
```cpp
// تعریف پایه‌ها
const int buttonPin = 2;                     // پایه دکمه
const int ledPins[] = { 3, 4, 5, 6, 7, 8 };  // پایه‌های LED ها
int buttonState = 0;                         // وضعیت دکمه

void setup() {
  // تنظیمات پایه‌های LED به عنوان خروجی
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);  // تنظیم پایه دکمه به عنوان ورودی
  Serial.begin(9600);                // آغاز ارتباط سریال
  randomSeed(analogRead(0));         // استفاده از نویز آنالوگ برای تولید عدد تصادفی
}

void loop() {
  buttonState = digitalRead(buttonPin);  // وضعیت دکمه

  if (buttonState == LOW) {
    delay(50);  // تاخیر برای جلوگیری از خواندن مجدد

    // تولید عدد تصادفی بین 1 تا 6
    int randomNumber = random(1, 7);

    // چاپ عدد تصادفی در سریال مانیتور
    Serial.print("عدد تصادفی: ");
    Serial.println(randomNumber);

    // خاموش کردن همه LED ها
    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // روشن کردن LED با عدد تصادفی
    digitalWrite(ledPins[randomNumber - 1], HIGH);
  }
}
```

## طرز کار:
بعد از متصل کردن مدار و نوشتن و اپلود برنامه ان با فشار دادن دکمه در serial monitor عدد تصادفی بین 1 تا 6 نشان داده شده و مطابق ان لامپ متناظر ان روی برد روشن میشود.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان یک تاس الکترونیکی ساخت که بطور همزمان هم به ما عدد داده و هم لامپ ان عدد نیز روشن شود. همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.