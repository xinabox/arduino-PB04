/*
	This is a library for the PB04 
	Smart Battery Module

	The board uses I2C for communication.
	
	The board communicates with two I2C devices:
	* 	
	
	Data Sheet:
	MAX11646 - 
*/

#ifndef XiX_PB04_h
#define XiX_PB04_h

// System Include
//#include <XiX_CORE.h>
#include <Wire.h>
#include <inttypes.h>

// Device I2C Address
#define MAX11646_I2C_ADDRESS 	0x36

// MAX11646 Registers
#define MAX11646_WRITE_SETUP	0x80	
#define MAX11646_WRITE_CONF	0x00

// MAX11646 Defines
#define MAX11646_SETUP 		0x52
#define MAX11646_CONF_MSB	0x23
#define MAX11646_CONF_LSB	0x21


class PB04Class{
	public:
		PB04Class();
		bool begin();
		float readVoltage();
		float readCurrent();
		float readPower();
		
		readADC();
		setupADC(uint8_t data);
	
	private:
		int value;
		float voltage, current, power;
		int a,b,c,d;
};


extern PB04Class PB04;

#endif	

