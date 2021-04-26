#include <ZACwire.h>

ZACwire<10> boilerSensor(306);    // set pin "2" to receive signal from the TSic "306"
ZACwire<11> groupHeadSensor(306);

void setup() {
  Serial.begin(500000);
  
  if (boilerSensor.begin() == true) {     //check if a sensor is connected to the pin
    Serial.println("Signal found on 10");
  }
  if (groupHeadSensor.begin() == true) {     //check if a sensor is connected to the pin
    Serial.println("Signal found on 11");
  }
  delay(300);
}

void loop() {
  
  float boilerInput = boilerSensor.getTemp();
  if (boilerInput == 222) {
    Serial.println("Reading failed on 10");
  }
  else if (boilerInput == 221) {
    Serial.println("Sensor not connected on 10");
  }

  float groupHeadInput = groupHeadSensor.getTemp();
  if (groupHeadInput == 222) {
    Serial.println("Reading failed on 11");
  }
  else if (groupHeadInput == 221) {
    Serial.println("Sensor not connected on 11");
  }
  
  else {
    
    Serial.print("bt == ");
    Serial.print(boilerInput);
    
    Serial.print("  ght == ");
    Serial.println(groupHeadInput);
    
  }
  delay(100);
  
}
