#include "Bistable.h"

#define RISING_EDGE		true
#define FALLING_EDGE	false
#define DEFAULT			true
Bistable Button;

void setup(){
	pinMode(LED_BUILTIN,OUTPUT);
	Button.begin(23,RISING_EDGE, INPUT_PULLUP, DEFAULT);	// Bouton bleue de la NUCLEO
}

void loop()
{
	if(Button.isChanged())
		digitalWrite(LED_BUILTIN,Button.getState());
}
