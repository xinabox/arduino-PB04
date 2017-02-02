/*************************************************************
	This is an examples for the PB04
	Smart Battery Module
	
	You can buy one on our store!
	-----> https://xinabox.cc/modules/power/PB04/
	
	This example requests the Battery module to measure
	the instantaneous voltage being used.
	
	The sensor communicates over the I2C Bus.
	
*************************************************************/

//#include <XiX_Core.h>
#include <XiX_PB04.h>

const int DELAY_TIME 1000
  
void setup(){
  Serial.begin(9600);
  Serial.println("====================================");
  Serial.println("=  XINABOX PB04 Power Measurement  =");
  Serial.println("====================================");
  PB04.begin();
  delay(DELAY_TIME);
}

void loop(){
  float volts = 0;
  volts = PB04.readVoltage();
  Serial.println("Voltage on battery is :");
  Serial.print(volts,2);
  Serial.print("V");
  delay(DELAY_TIME);
}


