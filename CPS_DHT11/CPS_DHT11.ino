#include "DHT.h"

#define DHT_PIN 32
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);


void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 test!");

  dht.begin();


}

void loop() {
  
  vTaskDelay(2000/ portTICK_PERIOD_MS);
  // Read humidity as Celsius (the default)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.printf("temperature: %f \r\n", t);
  Serial.printf("humidity: %f \r\n", h);
  Serial.printf("----------------------------- \r\n", h);

}
