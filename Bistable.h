/*********************************************************************
	Bistable library

	Author : Jean-Marc Chiappa
	Date   : 30.10.2018
	Rev : 1
	
	*******************************************************************/

#ifndef Bistable_h
#define Bistable_h

#include "Arduino.h"

#define RISING_EDGE		HIGH
#define FALLING_EDGE	LOW

class Bistable
{
public:
	Bistable(void);
	void begin(uint8_t Pin,uint8_t Active_Edge, uint8_t Input_type, uint8_t Default_state);
	bool isChanged();
	uint8_t getState();

private:
	uint8_t PinNumber;
	uint8_t Active_Edge;
	uint8_t Last_input_state;
	uint8_t Current_state;
	uint8_t cnt_;
	uint8_t Seuil=50;
};

#endif // Bistable_h