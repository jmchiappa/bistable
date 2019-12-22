#include "Bistable.h"


Bistable::Bistable() {}

void Bistable::begin(uint8_t Pin,uint8_t Active_Edge, uint8_t Input_type, uint8_t Default_state, uint64_t DebouncerDelay)
{
	this->Active_Edge = Active_Edge;
	this->Current_state = Default_state;
	this->PinNumber=Pin;
	this->delay=DebouncerDelay;
	if((Input_type==INPUT)||(Input_type==INPUT_PULLUP))
	{
		pinMode(Pin, Input_type);
	}
	else
		pinMode(Pin, INPUT);

	Last_input_state = digitalRead(this->PinNumber);
	t0=0;
	Update=false;
//	Serial.begin(115200);
}

/* Return true if an expected transition occurs
*/
bool Bistable::isChanged(void)
{
	bool ret=false;
	uint8_t state = digitalRead(this->PinNumber);
//	Serial.print("1 "+String(Last_input_state)+" "+String(state)+" "+String(Active_Edge));
	if(t0==0) {
		if(state!=Last_input_state) { // transition occurs
//			Serial.print("-> 2 "+String(Last_input_state)+" "+String(state)+" "+String(Active_Edge));
			if(state==Active_Edge) {
//				Serial.print("-> 3 "+String(Last_input_state)+" "+String(state));
				t0=millis();
			}
			else {
				Last_input_state = state;
			}
		}
	}
	else if((millis()-t0)>delay) {
		if(state!=Last_input_state) { // transition occurs
//			Serial.print("-> 4");
			Current_state=(Current_state==HIGH?LOW:HIGH);	// XOR Current_state
			ret=true;	// transition occurs
		}
//		Serial.print("-> 5");
		t0=0;
		Last_input_state = state;
	}

	//Last_input_state = state;
//	Serial.println();
	Update=true;
	return ret; // no change
}

/* Return current state of bistable variable
*/
uint8_t Bistable::getState(void)
{	
	if(!Update) isChanged();
	Update=false;
	return Current_state; // no change
}

void Bistable::changeDebouncerDelay(uint64_t delay)
{
	this->delay = delay;
}
