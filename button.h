
#ifndef BUTTON_H_
#define BUTTON_H_

#include "misc.h"

struct button
{
	uint8_t pin;
	enum io_port io_port;
};

bool button_is_pressed(const struct button* self);
void button_init (struct button* self, const uint8_t pin);


#endif