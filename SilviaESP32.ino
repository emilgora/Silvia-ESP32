#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

WiFiServer server(80);

#include <MiniPID.h>

#include <Arduino.h>

#include <Adafruit_MAX31865.h>

#include <U8x8lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display

int fooBar = 0;

const int guiLeftPin = 34;
const int guiRightPin = 39;
const int guiSelectPin = 36;

void setup(void)
{
  
  pinMode(guiLeftPin, INPUT);
  pinMode(guiRightPin, INPUT);
  pinMode(guiSelectPin, INPUT);

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
// 

  
}
