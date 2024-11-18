
# توابع پایه مربوط به وقفه در آردوینو

## شرح پروژه:
### توابع وقفه (Interrupts) در آردوینو
وقفه‌ها (Interrupts) در آردوینو به شما این امکان را می‌دهند که بدون نیاز به بررسی مداوم وضعیت یک سنسور یا رویداد خاص (Polling)، به صورت خودکار به وقوع یک رویداد واکنش نشان دهید. این قابلیت، بهینه‌سازی کد و بهبود عملکرد پروژه‌ها را فراهم می‌کند.
### تعریف وقفه
وقفه یک رویداد سخت‌افزاری یا نرم‌افزاری است که پردازنده را مجبور می‌کند تا از اجرای کد فعلی متوقف شود و به یک تابع خاص (Interrupt Service Routine - ISR) بپردازد.
**تابع ()interrupts** این تابع وقفه‌ها را پس از اینکه توسط تابع ()noInterrupts غیرفعال شدند، مجدداً فعال می‌کند. **تابع ()noInterrupts** این تابع وقفه‌ها را غیرفعال می‌کند. وقفه‌ها را می‌توان با تابع ()interrupts مجدداً فعال کرد.**تابع (attachInterrupt(digitalPinToInterrupt(pin), ISR, mode**
اولین پارامتر برای attatchInteerupt، شماره پین است.باید از digitalPinToInterrupt(pin) برای مشخص کردن منبع وقفه‌ی خارجی استفاده کرد.**تابع ((detachInterrupt(digitalPinToInterrupt(pin** وقفه ای که توسط تابع (digitalPinToInterrupt(pin مشخص شده را خاموش می‌کند.

## چرا از وقفه‌ها استفاده می‌کنیم؟
- صرفه‌جویی در زمان و منابع پردازنده
- افزایش دقت و واکنش سریع به رویدادها
- کاربرد در پروژه‌هایی که نیاز به زمان‌بندی دقیق دارند
### پارامترها:
- pin: .شماره پین دیجیتالی که وقفه به آن متصل می‌شود
- ISR: .نام تابعی که باید هنگام وقوع وقفه اجرا شود
- mode: :حالت تحریک وقفه که می‌تواند یکی از موارد زیر باشد
- LOW:.فعال میشود low وقفه هنگام سیگنال
- CHANGE:.یا بالعکس فعال میشود high به low وقفه هنگام تغییر سطح سیگنال 
- RISING:.فعال میشود high به low وقفه هنگام تغییر سطح از
- FALLING:بالعکس حالت بالا
## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE

## طریقه انجام آزمایش (اتصالات):
- کد برنامه را در نرم‌افزار Arduino IDE اجرا کرده روی برد آپلود میکنیم.

## تصاویر:

![Interrupts](https://github.com/user-attachments/assets/24a99b5a-0dfb-4f7a-a5d7-821c04419e7c)
![Interruptss](https://github.com/user-attachments/assets/501b659e-7a90-45c6-9d86-6fd05da51a63)





## کد پروژه:
```cpp
volatile bool led_state = LOW;

/* Setup is run once at the start (Power-On or Reset) of sketch */
void setup()
{
  pinMode(13, OUTPUT); /* Pin 13 is defined as Output */
  pinMode(2, INPUT_PULLUP); /* Interrupt pin */
  /* Connect pin 2 to ground using a tactile switch between the pin and ground */
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING); /* Call ISR blink whenever a falling edge event is detected on pin 2 */
  /* Press switch to cause falling edge event on the pin */
}

/* Loop runs over and over after the startup function */
void loop()
{
  digitalWrite(13, led_state); /* Write state value to pin 13 which has on-board LED */
}

/* ISR */
void blink() {
  led_state = !led_state; /* Toggle state value of LED */
}
```
# توابع پایه مربوط به وقفه در آردوینو

## شرح پروژه:
### توابع وقفه (Interrupts) در آردوینو
وقفه‌ها (Interrupts) در آردوینو به شما این امکان را می‌دهند که بدون نیاز به بررسی مداوم وضعیت یک سنسور یا رویداد خاص (Polling)، به صورت خودکار به وقوع یک رویداد واکنش نشان دهید. این قابلیت، بهینه‌سازی کد و بهبود عملکرد پروژه‌ها را فراهم می‌کند.
### تعریف وقفه
وقفه یک رویداد سخت‌افزاری یا نرم‌افزاری است که پردازنده را مجبور می‌کند تا از اجرای کد فعلی متوقف شود و به یک تابع خاص (Interrupt Service Routine - ISR) بپردازد.
**تابع ()interrupts** این تابع وقفه‌ها را پس از اینکه توسط تابع ()noInterrupts غیرفعال شدند، مجدداً فعال می‌کند. **تابع ()noInterrupts** این تابع وقفه‌ها را غیرفعال می‌کند. وقفه‌ها را می‌توان با تابع ()interrupts مجدداً فعال کرد.**تابع (attachInterrupt(digitalPinToInterrupt(pin), ISR, mode**
اولین پارامتر برای attatchInteerupt، شماره پین است.باید از digitalPinToInterrupt(pin) برای مشخص کردن منبع وقفه‌ی خارجی استفاده کرد.**تابع ((detachInterrupt(digitalPinToInterrupt(pin** وقفه ای که توسط تابع (digitalPinToInterrupt(pin مشخص شده را خاموش می‌کند.

## چرا از وقفه‌ها استفاده می‌کنیم؟
- صرفه‌جویی در زمان و منابع پردازنده
- افزایش دقت و واکنش سریع به رویدادها
- کاربرد در پروژه‌هایی که نیاز به زمان‌بندی دقیق دارند
### پارامترها:
- pin: .شماره پین دیجیتالی که وقفه به آن متصل می‌شود
- ISR: .نام تابعی که باید هنگام وقوع وقفه اجرا شود
- mode: :حالت تحریک وقفه که می‌تواند یکی از موارد زیر باشد
- LOW:.فعال میشود low وقفه هنگام سیگنال
- CHANGE:.یا بالعکس فعال میشود high به low وقفه هنگام تغییر سطح سیگنال 
- RISING:.فعال میشود high به low وقفه هنگام تغییر سطح از
- FALLING:بالعکس حالت بالا
## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE

## طریقه انجام آزمایش (اتصالات):
- کد برنامه را در نرم‌افزار Arduino IDE اجرا کرده روی برد آپلود میکنیم.

## تصاویر:

![Interrupts](https://github.com/user-attachments/assets/24a99b5a-0dfb-4f7a-a5d7-821c04419e7c)
![Interruptss](https://github.com/user-attachments/assets/501b659e-7a90-45c6-9d86-6fd05da51a63)





## کد پروژه:
```cpp
volatile bool led_state = LOW;

/* Setup is run once at the start (Power-On or Reset) of sketch */
void setup()
{
  pinMode(13, OUTPUT); /* Pin 13 is defined as Output */
  pinMode(2, INPUT_PULLUP); /* Interrupt pin */
  /* Connect pin 2 to ground using a tactile switch between the pin and ground */
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING); /* Call ISR blink whenever a falling edge event is detected on pin 2 */
  /* Press switch to cause falling edge event on the pin */
}

/* Loop runs over and over after the startup function */
void loop()
{
  digitalWrite(13, led_state); /* Write state value to pin 13 which has on-board LED */
}

/* ISR */
void blink() {
  led_state = !led_state; /* Toggle state value of LED */
}
```