#include "button.h"

bool button_is_pressed(const struct button* self)
{
	if (self->io_port == IO_PORTB)
	{
		return (PINB & ( 1 << self->pin));
	}
	else if (self->io_port == IO_PORTC)
	{
		return (PINC & ( 1 << self->pin));
	}
	else if (self->io_port == IO_PORTD)
	{
		return (PIND & ( 1 << self->pin));
	}
	else 
	{
		return false;
	}
	
}

void button_init(struct button* self, const uint8_t pin)
{
	if (pin >= 0 && pin <= 7)
	{
		self->io_port = IO_PORTD;
		self->pin = pin;
		PORTD |= (1 << self->pin);
	}
	else if (pin >= 14 && pin <= 19)
	{
		self->io_port = IO_PORTC;
		self->pin = pin - 14;
		PORTC |= (1 << self->pin);
	}
	else if (pin >= 8 && pin <= 13)
	{
		self->io_port = IO_PORTB;
		self->pin = pin - 8;
		PORTB |= (1 << self->pin);
	}
	return;
}