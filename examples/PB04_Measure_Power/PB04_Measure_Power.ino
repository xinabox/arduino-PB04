/*************************************************************
	This is an examples for the PB04
	Smart Battery Module
	
	You can buy one on our store!
	-----> https://xinabox.cc/PB04/
	
	This example requests the Battery module to measure
	the instantaneous voltage being used.
	
	Currently Supported on the following ☒CHIPs:
	- CW01
	- CC01
	- CR01
	
	The sensor communicates over the I2C Bus.
	
	------------------------TIPS--------------------------
	Change this line ----->Wire.begin(2,14);
	to this			 ----->Wire.begin();
	to allow this sensor to communicate with CC01 and CR01
	
*************************************************************/

#include <xCore.h>
#include <xPB04.h>

const int DELAY_TIME = 1000;
  
void setup(){
	Serial.begin(115200);
	Serial.println("====================================");
	Serial.println("   XINABOX PB04 Power Measurement   ");
	Serial.println("====================================");
	PB04.begin();
	Wire.begin(2,14);
	delay(DELAY_TIME);
}

void loop(){
	// Create a variable to store the data read from PB04
	float power;
	power = 0;
	
	// Poll the sensor to read all available data
	PB04.poll();
	
	// Request PB04 to get the power measurement and store in
	// the power variable
	power = PB04.getPower();
	
	// Display the recorded data over the serial monitor
	Serial.print("Power Consumption :");
	Serial.print(power);
	Serial.println(" W");
	delay(DELAY_TIME);
}


