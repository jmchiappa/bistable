#include "Bistable.h"


Bistable::Bistable() {}

void Bistable::begin(uint8_t Pin,uint8_t Active_Edge, uint8_t Input_type, uint8_t Default_state)
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
	cnt_=0;
	//Serial.begin(115200);
}

/* Return true if an expected transition occurs
*/
bool Bistable::isChanged(void)
{
	uint8_t state = digitalRead(this->PinNumber);
	//Serial.print("1 "+String(Last_input_state)+" "+String(state)+" "+String(Active_Edge));
	if(state!=Last_input_state) { // transition occurs
		//Serial.print("-> 2 "+String(Last_input_state)+" "+String(state)+" "+String(Active_Edge));
		if(state==Active_Edge) {
			//Serial.print("-> 3 "+String(Last_input_state)+" "+String(state)+String(cnt_));
			cnt_++;
			if(cnt_>Seuil) {
				//Serial.print("-> 4");
				cnt_=0;
				Last_input_state = state;
				Current_state=(Current_state==HIGH?LOW:HIGH);	// XOR Current_state
				return true;	// transition occurs
			}
		}
		else {
			Last_input_state = state;
		}
	}
	else{
		if(cnt_>0)
			cnt_--;
	}
	//Last_input_state = state;
	//Serial.println();
	return false; // no change
}

/* Return current state of bistable variable
*/
uint8_t Bistable::getState(void)
{
	return Current_state; // no change
}
