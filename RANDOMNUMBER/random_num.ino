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