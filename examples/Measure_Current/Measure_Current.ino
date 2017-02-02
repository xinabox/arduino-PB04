/*************************************************************
	This is an examples for the PB04
	Smart Battery Module
	
	You can buy one on our store!
	-----> https://xinabox.cc/modules/power/PB04/
	
	This example requests the Battery module to measure
	the instantaneous current being used.
	
	The sensor communicates over the I2C Bus.
	
*************************************************************/

//#include <XiX_Core.h>
#include <XiX_PB04.h>

const int DELAY_TIME 1000
  
void setup(){
  Serial.begin(9600);
  Serial.println("====================================");
  Serial.println("= XINABOX PB04 Current Measurement =");
  Serial.println("====================================");
  PB04.begin();
  delay(DELAY_TIME)
}

void loop(){
  float current = 0;
  current = PB04.readCurrent();
  Serial.println("Current on battery is :");
  Serial.print(current,2);
  Serial.print("V");
  delay(DELAY_TIME);
}
