#include "led.h"

void led_init(struct led* self, const uint8_t pin)
{
	if (pin >= 0 && pin <= 7)
	{
		self->io_port = IO_PORTD;
		self->pin = pin;
		DDRD |= (1 << self->pin);
	}
	else if (pin >= 8 && pin <= 13)
	{
		self->io_port = IO_PORTB;
		self->pin = pin - 8;
		DDRB |= (1 << self->pin);
	}
	
	self->enabled = false;
	return;
}

void led_clear(struct led* self)
{
	led_off(self);
	
	if (self->io_port == IO_PORTB)
	{
		DDRB &= ~(1 << self->pin);
	}
	else if (self->io_port == IO_PORTD)
	{
		DDRD &= ~(1 << self->pin);
	}
}

void led_on(struct led* self)
{
	if (self->io_port == IO_PORTB)
	{
		PORTB |= (1 << self->pin);
	}
	else if (self->io_port == IO_PORTD)
	{
		PORTD |= (1 << self->pin);
	}
	
	self->enabled = true; 
	return;
}

void led_off(struct led* self)
{
	if (self->io_port == IO_PORTB)
	{
		PORTB &= ~(1 << self->pin);
	}
	else if (self->io_port == IO_PORTD)
	{
		PORTD &= ~(1 << self->pin);
	}
	
	self->enabled = false;
	return;
}

void led_toggle(struct led* self)
{
	if (self->enabled)
	{
		led_off(self);
	}
	else 
	{
		led_on(self);
	}
	return;
}

void led_blink(struct led* self, const uint16_t blink_speed_ms)
{
	led_toggle(self);
	delay_ms(blink_speed_ms);
	return;
}