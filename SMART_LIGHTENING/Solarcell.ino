const int ldrPin = A0; // پین فوتوسل
const int ledPin = 9;  // پین LED
int ldrValue = 0;      // متغیر برای ذخیره مقدار LDR

void setup() {
  pinMode(ledPin, OUTPUT);    // تنظیم LED به عنوان خروجی
  Serial.begin(9600);         // شروع ارتباط سریال
}

void loop() {
  // خواندن مقدار آنالوگ فوتوسل
  ldrValue = analogRead(ldrPin);

  // نمایش مقدار نور در سریال مانیتور
  Serial.print("Light Intensity: ");
  Serial.println(ldrValue);

  // تنظیم روشنایی LED بر اساس مقدار فوتوسل
  int ledBrightness = map(ldrValue, 0, 1023, 0, 255); // تبدیل مقیاس 0-1023 به 0-255
  analogWrite(ledPin, ledBrightness);

  delay(100); // تاخیر 100 میلی‌ثانیه
}
