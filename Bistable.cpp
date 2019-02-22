#include "Bistable.h"

#define RISING_EDGE		true
#define FALLING_EDGE	false

Bistable::Bistable() {}

void Bistable::begin(uint8_t Pin,boolean Active_Edge, uint8_t Input_type, boolean Default_state)
{
	this->Active_Edge = Active_Edge;
	this->Current_state = Default_state;
	this->PinNumber=Pin;
	if((Input_type==INPUT)||(Input_type==INPUT_PULLUP))
	{
		pinMode(Pin, Input_type);
	}
	else
		pinMode(Pin, INPUT);

	Last_input_state = digitalRead(this->PinNumber);
}

/* Return true if an expected transition occurs
*/
boolean Bistable::isChanged(void)
{
	boolean state = digitalRead(this->PinNumber);
	if(state!=Last_input_state) // transition occurs
	{
		if(state==Active_Edge)
		{
			Last_input_state = state;
			Current_state=(Current_state==HIGH?LOW:HIGH);	// XOR Current_state
			return true;	// transition occurs
		}
	}
	Last_input_state = state;
	return false; // no change
}

/* Return current state of bistable variable
*/
uint8_t Bistable::getState(void)
{
	return Current_state; // no change
}
