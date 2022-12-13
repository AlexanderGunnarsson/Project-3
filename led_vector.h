#ifndef LED_VECTOR_H_
#define LED_VECTOR_H_

#include "misc.h"
#include "led.h"

struct led_vector
{
	struct led* leds; 
	size_t size;
};

static inline void led_vector_init(struct led_vector* self)
{
	self->leds = 0;
	self->size = 0;
	return;
}

static inline void led_vector_clear(struct led_vector* self)
{
	free(self->leds);
	led_vector_init(self);
	return;
}

static inline struct led* led_vector_begin(const struct led_vector* self)
{
	return self->leds;
}

static inline struct led* led_vector_end(const struct led_vector* self)
{
	return self->leds + self->size;
}

static inline struct led* led_vector_last(const struct led_vector* self)
{
	return self->size > 0 ? led_vector_end(self) - 1 : 0;
}

int led_vector_push(struct led_vector* self, const struct led* new_led);
int led_vector_pop(struct led_vector* self);
void led_vector_on(struct led_vector* self);
void led_vector_off(struct led_vector* self);
void led_vector_toggle(struct led_vector* self);
void led_vector_blink_collectively(struct led_vector* self,const uint16_t blink_speed_ms);
void led_vector_blink_sequentially(struct led_vector* self, const uint16_t blink_speed_ms);
void led_vector_blink_sequentially_reverse(struct led_vector* self, const uint16_t blink_speed_ms);

#endif /* LED_VECTOR_H_ */