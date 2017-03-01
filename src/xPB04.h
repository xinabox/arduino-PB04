/*
	This is a library for the PB04 
	Smart Battery Module

	The board uses I2C for communication.
	
	The board communicates with one I2C devices:
	-	MAX11646
	
	Data Sheets:
	MAX11646 - https://datasheets.maximintegrated.com/en/ds/MAX11646-MAX11647.pdf
*/

#ifndef xPB04_h
#define xPB04_h

// System Include
#include <inttypes.h>
#include "xCore.h"

// Device I2C Address
#define MAX11646_I2C_ADDRESS	0x36

// Register Defines
#define MAX11646_REG_SETUP		0x80
#define MAX11646_REG_CONF		0x00

// System Defines
#define MAX11646_VOLTAGE		0x21
#define MAX11646_CURRENT		0x23

#define MAX11646_SEL0			0x40
#define MAX11646_SEL1			0x20
#define MAX11646_SEL2			0x10
#define MAX11646_CLK_EX			0x08
#define MAX11646_BIP_ON			0x04
#define MAX11646_RST			0x02

#define MAX11646_SCAN0			0x40
#define MAX11646_SCAN1			0x20
#define MAX11646_CH_0			0x00
#define MAX11646_CH_1			0x02
#define MAX11646_MODE_SINGLE		0x01

#define MAX11646_SETUP			0xD2

class xPB04: public xCoreClass
{
	public:
		xPB04();
		bool 	begin(void);
		void 	poll();
		float 	getVoltage(void);
		float 	getCurrent(void);
		float 	getPower(void);
	
	private:
		void 	readVoltage(void);
		void 	readCurrent(void);
		void 	readPower(void);
		
		void 	setupADC(byte data);
		
		float 	voltage;
		float 	current;
		float 	power;
		
		uint8_t a,b,c,d;
};

extern xPB04 PB04;

#endif


