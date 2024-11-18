#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

 
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  Serial.print("رطوبت: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("دما: ");
  Serial.print(temperature);
  Serial.println(" *C");

  delay(2000);
}