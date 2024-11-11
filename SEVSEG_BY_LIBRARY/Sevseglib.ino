#define key1 digitalRead(A0);
void setup() {
  pinMode(A0, OUTPUT);
  for (int i = 0; i <= 5; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int dancinglight[6][5] = {
    { 1, 0, 0, 0, 0 },
    { 1, 1, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 0 },
    { 0, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 1 },
  }; 
  if (key == 1) {
    for (int a = 0; a <= 5; a++) {
      for (int i = 0; i < 6; i++) {
        digitalWrite(i, dancinglight[a][i]);
        delay(50);
      }
    }
  }
  //Display numbers one by one with 2 seconds delay
}