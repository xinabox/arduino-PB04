/*
	This is a library for the PB04 
	Smart Battery Module

	The board uses I2C for communication.
	
	The board communicates with two I2C devices:
	* 	
	
	Data Sheet:
	MAX11646 - 
*/

#include <XiX_PB04.h>
//#include <XiX_Core.h>
#include <inttypes.h>

PB04Class::PB04Class(){
	
}

bool PB04Class::begin(){
	//core.write8(MAX11646_I2C_ADDRESS, MAX11646_WRITE_SETUP , MAX11646_SETUP);
	Wire.beginTransmission(MAX11646_I2C_ADDRESS);
	Wire.write(MAX11646_WRITE_SETUP);
	Wire.write(MAX11646_SETUP);
	Wire.endTransmission();
}

float PB04Class::readVoltage(){
	voltage = 0;
	setupADC(0x21);
	Wire.requestFrom(MAX11646_I2C_ADDRESS, 2);
	if(Wire.available()){
		Wire.beginTransmission(MAX11646_I2C_ADDRESS);
		a = Wire.read();
		b = Wire.read();
		Wire.endTransmission();
	}
	Wire.endTransmission();
	voltage = ((((((float)a - 252)*256) + (float)b)*2.048)/1024)*2;
	
	return voltage;
}

float PB04Class::readCurrent(){
	current = 0;
	setupADC(0x23);
	Wire.requestFrom(MAX11646_I2C_ADDRESS, 2);
	if(Wire.available()){
		Wire.beginTransmission(MAX11646_I2C_ADDRESS);
		c = Wire.read();
		d = Wire.read();
		Wire.endTransmission();
	}
	Wire.endTransmission();
	current = ((((((((float)c - 252)*256) + (float)d)*2.048)/1024)/100)/0.02)*1000;
	return current;
}

float PB04Class::readPower(){
	power = voltage * current;
	
	return power;
}

PB04Class::setupADC(uint8_t data){
	//core.write8(MAX11646_I2C_ADDRESS, MAX11646_WRITE_SETUP , MAX11646_SETUP);
	//core.write8(MAX11646_I2C_ADDRESS, MAX11646_WRITE_SETUP , (uint8_t)data);
	Wire.beginTransmission(MAX11646_I2C_ADDRESS);
	Wire.write(MAX11646_WRITE_SETUP|MAX11646_SETUP);
	Wire.write(data);
	Wire.endTransmission();
}

int PB04Class::readADC(){
	//core.read16(MAX11646_I2C_ADDRESS);
}

PB04Class PB04 = PB04Class();