#include <ZACwire.h>

ZACwire<10> boilerSensor(306);    // set pin "2" to receive signal from the TSic "306"
ZACwire<11> groupSensor(306);

void setup() {
  Serial.begin(500000);
  
  if (boilerSensor.begin() == true) {     //check if a sensor is connected to pin 10
    Serial.println("Signal found on 10");
  }
  if (groupSensor.begin() == true) {     //check if a sensor is connected to pin 11
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

  float groupInput = groupSensor.getTemp();
  if (groupInput == 222) {
    Serial.println("Reading failed on 11");
  }
  else if (groupInput == 221) {
    Serial.println("Sensor not connected on 11");
  }
  
  else {
    
    Serial.print("boilerTemp == ");
    Serial.print(boilerInput);
    Serial.print(";");
    Serial.print(" groupTemp == ");
    Serial.print(groupInput);
    Serial.println(";");
    
    //Should hypothetically come out formatted like this: boilerTemp == 123; groupTemp == 123;
  }
  
  delay(100);
  
}
