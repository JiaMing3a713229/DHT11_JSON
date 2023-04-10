#include <ArduinoJson.h>

StaticJsonDocument<200> json_doc;
char json_output[100];
DeserializationError json_error;
const char* payload_tmeperature;
const char* payload_humidity;
  
void setup() {
  Serial.begin(115200);
  //字串轉JSON
  vTaskDelay(5000/ portTICK_PERIOD_MS);
  json_doc["tmeperature"] = "25.3";
  json_doc["humidity"] = "89.8";
  serializeJson(json_doc, json_output);
  Serial.println( "string to json:" ); 
  Serial.println( json_output ); 
 
  //JSON轉字串
  json_error = deserializeJson(json_doc, json_output);
  if (!json_error) {
    payload_tmeperature = json_doc["tmeperature"];
    payload_humidity = json_doc["humidity"];
    Serial.println( "json to string:" ); 
    // Serial.println( "payload_tmeperature:" ); 
    // Serial.println(payload_tmeperature);
    // Serial.println( "payload_humidity:" ); 
    // Serial.println(payload_humidity);
    Serial.printf("payload_tmeperature:%s \r\n",payload_tmeperature);
    Serial.printf("payload_humidity:%s \r\n",payload_humidity);
  }
}
  
void loop() {
    
}