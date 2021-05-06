#include <analogWrite.h>

#include <ZACwire.h>


ZACwire<26> boilerSensor(306);

// disabling grouphead sensor for stability at the moment
//ZACwire<27> groupSensor(306);

const int boilerPWMPin = 12;
//const int groupPWMPin = 14;

void setup() {
  Serial.begin(500000);

  if (boilerSensor.begin() == true) {     //check if a sensor is connected to pin 10
    Serial.println("Signal found on bS");
  }
  /*
  if (groupSensor.begin() == true) {     //check if a sensor is connected to pin 11
    Serial.println("Signal found on gS");
  }
  */
  analogWriteFrequency(boilerPWMPin, 10);
  analogWriteResolution(boilerPWMPin, 10);

  delay(300);
}

void loop() {
  
  float boilerTemp = boilerSensor.getTemp();
  if (boilerTemp == 222) {
    Serial.println("Reading failed on bS");
  }
  else if (boilerTemp == 221) {
    Serial.println("Sensor not connected on bS");
  }

  /*
  float groupTemp = groupSensor.getTemp();
  if (groupTemp == 222) {
    Serial.println("Reading failed on gS");
  }
  else if (groupTemp == 221) {
    Serial.println("Sensor not connected on gS");
  }
  */
  
  else {

    // Multiplying by 10 will shift the float by one decimal place. An ESPHome filter shifts it back one place.
    int boilerTempE10 = boilerTemp*10;
    
    analogWrite(boilerPWMPin,boilerTempE10);  
    //analogWrite(groupPin,groupTemp);

    Serial.print(boilerTemp);
    Serial.print("x");
    Serial.println(boilerTempE10);
    //Serial.print(groupTemp);
    
    // Writes temp as a PWM width to be read by the main ESP
  }

  delay(100);
  
}
