#define key1 digitalRead(A0)  //key1 اردوینو با A0 برابر قرار دادن پین//

void setup() {

  pinMode(A0, INPUT);  //را ورودی کرده ایم A0//
  pinMode(0, OUTPUT);  //از 0 تا 4 را خروجی کردیم//
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  int i, a;  //int از نوع a و i تعریف دو متغیر//
  //ترتیب روشن شدن لامپ ها//
  int dancinglight1[5][5] = {
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 1, 0 },
    { 0, 0, 1, 0, 0 },
    { 0, 1, 0, 0, 0 },
    { 1, 0, 0, 0, 0 }
  };

  for (i = 0; i <= 4; i++) {  //ها را خاموش می کندled دستور روبرو در حالتی که کلید زده نشده باشد تمام//
    digitalWrite(i, 0);
  }
  //حالت های رقص نوراجرا می شود for زیر می شویم و با توجه به حلقه های if در صورتی که کلید زده شد وارد شرط//
  if (key1 == 0) {  //
    for (a = 0; (a <= 4); a++) {
      for (i = 0; i <= 4; i++) {
        digitalWrite(i, dancinglight1[a][i]);
      }
      delay(200);
    }
  }
}