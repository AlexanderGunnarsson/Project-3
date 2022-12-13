#include "adc.h"

uint16_t adc_read(const uint8_t pin)
{
	ADMUX = (1 << REFS0)|(pin);
	ADCSRA = (1 << ADEN)|(1 << ADSC)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);
	while ((ADCSRA & (1 << ADIF)) == 0);
	ADCSRA = (1 << ADIF);
	return ADC;
}

void adc_get_pwm_values(const uint8_t pin, const uint16_t period_us1, uint16_t* on_time_us, uint16_t* off_time_us)
{
	const double duty_cycle = adc_read(pin) / 1023.0;
	*on_time_us = (uint16_t)(period_us1 * duty_cycle + 0.5);
	*off_time_us = period_us1 - *on_time_us;
	return;
}