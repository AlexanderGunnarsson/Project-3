#include "header.h"


ISR (INT0_vect) // PIN 2
{
	led1_enabled = !led1_enabled; // Inverterar mellan true och false.
	return;
}

ISR (INT1_vect) // PIN 3
{
	led2_enabled = !led2_enabled; // Inverterar mellan true och false.
	return;
}

ISR (PCINT0_vect) // PIN 11 - 13
{
	if (button_is_pressed(&b3))
	{
		led3_enabled = !led3_enabled; // Inverterar mellan true och false.
	}
	if (button_is_pressed(&b4))
	{
		led4_enabled = !led4_enabled; // Inverterar mellan true och false.
	}
	if (button_is_pressed(&b5))
	{
		led5_enabled = !led5_enabled; // Inverterar mellan true och false.
	}
}
