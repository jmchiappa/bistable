#include "Bistable.h"

#define DEFAULT			HIGH
Bistable Button;

void setup(){
	pinMode(LED_BUILTIN,OUTPUT);
	Button.begin(USER_BTN,FALLING_EDGE, INPUT_PULLUP, DEFAULT);	// Bouton bleue de la NUCLEO
  digitalWrite(LED_BUILTIN,Button.getState());
}

void loop()
{
	if(Button.isChanged())
		digitalWrite(LED_BUILTIN,Button.getState());
}
