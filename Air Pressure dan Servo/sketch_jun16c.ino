#include <M5Stack.h>
#include <Wire.h>
#include "Adafruit_Sensor.h"
#include <Adafruit_BMP280.h>
const int servo_pin = 15;
int freq = 50;
int ledChannel = 0;
int resolution = 8;
void setup() 
{
  M5.begin();
  Wire.begin();
  M5.Lcd.setCursor(80, 0, 4);
  M5.Lcd.print("PRESSURE");
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(servo_pin, ledChannel);
}

void loop() 
{
 float pressure = bme.readPressure();
M5.Lcd.setCursor(50, 100, 4);
M5.Lcd.printf("Pressure:%2.0fPa\r\n",pressure);
delay(100);
  {
    ledcWrite(ledChannel, 18);//90°
    delay(1000);
  }
}
