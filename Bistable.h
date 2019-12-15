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
	void begin(uint8_t Pin,uint8_t Active_Edge, uint8_t Input_type=INPUT, uint8_t Default_state=LOW, uint64_t DebouncerDelay=50);
	bool isChanged();
	uint8_t getState();
	void changeDebouncerDelay(uint64_t delay);
private:
	uint8_t PinNumber;
	uint8_t Active_Edge;
	uint8_t Last_input_state;
	uint8_t Current_state;
	uint64_t t0;
	uint64_t delay=50; //ms
};

#endif // Bistable_h