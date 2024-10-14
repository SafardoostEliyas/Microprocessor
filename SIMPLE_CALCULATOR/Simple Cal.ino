void setup() {
  Serial.begin(9600);
  Serial.println("type the calculation:");
}

void loop() {
  while (Serial.available() > 0) {
    int num1 = Serial.parseInt();
    char a = Serial.read();
    int num2 = Serial.parseInt();
    switch (a) {
      case '+':
        Serial.println(num1 + num2);
        break;

      case '-':
        Serial.println(num1 - num2);
        break;

      case '*':
        Serial.println(num1 * num2);
        break;

      case '/':
      if(num2 != 0){
        Serial.println(num1 / num2);
        }else{
          Serial.println("err");
          }
    }
  }
}
