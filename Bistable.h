/*********************************************************************
	Bistable library

	Author : Jean-Marc Chiappa
	Date   : 30.10.2018
	Rev : 1
	
	*******************************************************************/

#ifndef Bistable_h
#define Bistable_h

#include "Arduino.h"

class Bistable
{
public:
	Bistable(void);
	void begin(uint8_t Pin,boolean Active_Edge, uint8_t Input_type, boolean Default_state);
	boolean isChanged();
	uint8_t getState();

private:
	uint8_t PinNumber;
	boolean Active_Edge;
	boolean Last_input_state;
	uint8_t Current_state;
};

#endif // Bistable_h