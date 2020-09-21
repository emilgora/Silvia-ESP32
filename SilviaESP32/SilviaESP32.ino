#include <Arduino.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
WiFiServer server(80);

#include <U8x8lib.h> //https://github.com/olikraus/u8g2/wiki
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display (change config if applicable)

#include <MiniPID.h> //https://github.com/tekdemo/MiniPID
double p = 1;
double i = 0;
double d = 0;
MiniPID pid = MiniPID(p,i,d);
//set any other PID configuration options here. 

#include <Adafruit_MAX31865.h> //https://github.com/adafruit/Adafruit_MAX31865
Adafruit_MAX31865 thermo = Adafruit_MAX31865(10, 11, 12, 13);

int fooBar = 0;

double sensor = 0; //hardware defined value (in this case from PT100 RTD Sensor attached to boiler)
double targetTemp = 0; //user defined value (in this case from web page)

double output = 0; //post processed value

void setup(void)
{
  Serial.begin(9600);
  
  u8x8.begin();
  u8x8.setPowerSave(0);

  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.drawString(4,3,"Loading");
  u8x8.drawString(2,5,"please wait.");
  delay(5000);
  u8x8.clear();

}

void loop(void)
{

// 3x6 font for set temp read + weather icon

  //get sensor value
  //set temperature target value
  double output=pid.getOutput(sensor,targetTemp);
  //do something with the output
  Serial.println(output);
  delay(50);
  

  
}
