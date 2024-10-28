int potPin = A0;    // پین آنالوگ پتانسیومتر
int potValue = 0;   // متغیر برای نگهداری مقدار پتانسیومتر
float voltage = 0;  // متغیر برای نگهداری ولتاژ محاسبه شده

void setup() {
  Serial.begin(9600);  // سرعت شروع ارتباط سریال
}

void loop() {
  potValue = analogRead(potPin);        // خواندن مقدار پتانسیومتر
  voltage = potValue * (5.0 / 1023.0);  // تبدیل مقدار به ولتاژ

  // نمایش ولتاژ در Serial Monitor
  Serial.print("Voltage: ");
  Serial.println(voltage);

  delay(500);  // تاخیر خواندن مجدد
}