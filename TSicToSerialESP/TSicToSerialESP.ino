#include <ZACwire.h>


ZACwire<16> boilerSensor(306);    // set pin "2" to receive signal from the TSic "306"
ZACwire<17> groupSensor(306);

const int boilerPin = 22;
const int groupPin = 23;

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
  
  float boilerTemp = boilerSensor.getTemp();
  if (boilerTemp == 222) {
    Serial.println("Reading failed on 10");
  }
  else if (boilerTemp == 221) {
    Serial.println("Sensor not connected on 10");
  }

  float groupTemp = groupSensor.getTemp();
  if (groupTemp == 222) {
    Serial.println("Reading failed on 11");
  }
  else if (groupTemp == 221) {
    Serial.println("Sensor not connected on 11");
  }
  
  else {

    // PWM @ 16 bit resolution
    // Multiplying by 10 to shift float by one decimal place
    // The main ESP will multiply by 0.1 to reverse this
    boilerTemp*10;
    groupTemp*10;
    
    //analogWrite(boilerPin,boilerTemp*10);  
    //analogWrite(groupPin,groupTemp*10);
    
    Serial.print(boilerTemp);
    Serial.print("x");
    Serial.println(groupTemp);
    
    // Writes temp as a PWM width to be read by the main ESP
  }

  delay(100);
  
}
