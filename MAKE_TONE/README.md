
# ساخت ملودی با آردوینو

## شرح مختصر پروژه:
در این پروژه ما با استفاده از نرم افزار و بازر و برد Arduino میخواهیم یک ملودی تولید کرده و در بازر پخش کنیم. با آپلود برنامه بازر شروع به پخش ملودی میکند.

## لوازم مورد نیاز:
-  برد Arduino Uno
- نرم‌افزار Arduino IDE
- بازر

## طریقه انجام آزمایش (اتصالات):
- دو سیم بازر را یکی به GND و دیگری را به خانه هشت برد اردوینو متصل میکنیم.
## تصاویر:
![tone](https://github.com/user-attachments/assets/2536b1f5-dbb0-444b-8ee9-00953bb8fbe3)
![tone](https://github.com/user-attachments/assets/96921abd-af2e-402a-92fa-f665c7a9536e)



## کد پروژه:
```cpp
#include "pitches.h"
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_GS3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    //pause for the note's duration plus 30 ms:
    delay(noteDuration + 30);
  }
}

void loop() {
  // no need to repeat the melody.
}
```

## طرز کار:
با اپلود برنامه متصل کردن بازر به برد میتوانیم ملودی دلخواه خود را اجرا کنیم.
## نتیجه‌ پروژه:
در این پروژه نشان‌ میدهیم که چگونه میتوان ملودی ساخت و آن را اجرا کرد. همچنین انجام این دستورات از طریق کد نویسی در Arduino انجام شده است.