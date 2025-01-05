int led = 2; // پین LED
int sensorPin = A0; // پین سنسور IR
int IR;

void setup() {
  pinMode(sensorPin, INPUT); // تنظیم پین سنسور به عنوان ورودی
  pinMode(led, OUTPUT);      // تنظیم پین LED به عنوان خروجی
  Serial.begin(9600);        // شروع ارتباط سریال
}

void loop() {
  IR = digitalRead(sensorPin); // خواندن وضعیت سنسور
  if (IR == LOW) { // اگر مانعی شناسایی شود
    Serial.print("Object detected = ");
    Serial.println(IR);
    digitalWrite(led, HIGH); // روشن کردن LED
  } else {
    Serial.print("Not detected = ");
    Serial.println(IR);
    digitalWrite(led, LOW); // خاموش کردن LED
  }
  delay(300); // تاخیر 300 میلی‌ثانیه
}