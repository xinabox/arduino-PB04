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

xPB04 PB04;
  
void setup(){
	// Start the Serial Monitor
	Serial.begin(115200);
	
	// Set the I2C Pins for CW01
	#ifdef ESP8266
	  Wire.pins(2, 14);
	  Wire.setClockStretchLimit(15000);
	#endif
	
	// Start the I2C Comunication
	Wire.begin();
	
	// Start the Battery Sensor
	PB04.begin();
	
	// Small delay for sensor to normalise
	delay(5000);
	
	Serial.println("====================================");
	Serial.println("  XINABOX PB04 Voltage Measurement  ");
	Serial.println("====================================");
}

void loop(){
	// Create a variable to store the data read from PB04
	float voltage;
	voltage = 0;
	
	// Poll the sensor to read all available data
	PB04.poll();
	
	// Request PB04 to get the voltage measurement and store in
	// the voltage variable
	voltage = PB04.getVoltage();
	
	// Display the recorded data over the serial monitor
	Serial.print("Voltage on battery is :");
	Serial.print(voltage);
	Serial.println("V");
	
	delay(DELAY_TIME);
}



