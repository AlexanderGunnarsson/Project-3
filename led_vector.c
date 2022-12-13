#include "led_vector.h"

int led_vector_push(struct led_vector* self, const struct led* new_led)
{
	struct led* copy = (struct led*)realloc(self->leds, sizeof(struct led) * (self->size + 1));
	if (!copy) return 1;
	copy[self->size++] = *new_led;
	self->leds = copy;
	return 0;
}

int led_vector_pop(struct led_vector* self)
{
	if (self->size <= 1)
	{
		led_vector_clear(self);
		return 0;
	}
	else
	{
		struct led* copy = (struct led*)realloc(self->leds, sizeof(struct led) * (self->size - 1));
		if (!copy) return 1;
		self->leds = copy;
		self->size--;
		return 0;
	}
}

void led_vector_on(struct led_vector* self)
{
	for (size_t i = 0; i < self->size; ++i)
	{
		led_on(&self->leds[i]);
	}
}

void led_vector_off(struct led_vector* self)
{
	for (size_t i = 0; i < self->size; ++i)
	{
		led_off(&self->leds[i]);
	}
}

void led_vector_toggle(struct led_vector* self)
{
	for (size_t i = 0; i < self->size; ++i)
	{
		led_toggle(&self->leds[i]);
	}
}

void led_vector_blink_collectively(struct led_vector* self,const uint16_t blink_speed_ms)
{
	led_vector_on(self);
	delay_ms(blink_speed_ms);
	led_vector_off(self);
	delay_ms(blink_speed_ms);
}

void led_vector_blink_sequentially(struct led_vector* self, const uint16_t blink_speed_ms)
{
   led_vector_off(self);
   	
	for(size_t i = 0; i < self->size; ++i)
	{
		led_on(&self->leds[i]);
		delay_ms(blink_speed_ms);
		led_off(&self->leds[i]);
	}
}

void led_vector_blink_sequentially_reverse(struct led_vector* self, const uint16_t blink_speed_ms)
{
	 led_vector_off(self);
	 
	for (int i = self->size - 1; i >= 0; --i)
	{
		led_on(&self->leds[i]);
		delay_ms(blink_speed_ms);
		led_off(&self->leds[i]);
	}
}