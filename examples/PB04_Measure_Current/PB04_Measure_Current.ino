/*************************************************************
	This is an examples for the PB04
	Smart Battery Module
	
	You can buy one on our store!
	-----> https://xinabox.cc/PB04/
	
	This example requests the Battery module to measure
	the instantaneous current being used.
	
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
	// Start the Serial Monitor
	Serial.begin(115200);
	
	// Start the I2C Comunication
	Wire.begin(2,14);
	
	// Start the Battery Sensor
	PB04.begin();
	
	// Small delay for sensor to normalise
	delay(5000);
	
	Serial.println("====================================");
 	Serial.println("  XINABOX PB04 Current Measurement  ");
	Serial.println("====================================");
}

void loop(){
	// Create a variable to store the data read from PB04
	float current;
	current = 0;
	
	// Poll the sensor to read all available data
	PB04.poll();
	
	// Request PB04 to get the current measurement and store in
	// the current variable
	current = PB04.getCurrent();
	
	// Display the recorded data over the serial monitor
	Serial.print("Current on battery is :");
	Serial.print(current);
	Serial.println(" mA");
	
	delay(DELAY_TIME);
}
