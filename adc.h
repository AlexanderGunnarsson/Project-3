#ifndef ADC_H_
#define ADC_H_

#include "misc.h"

uint16_t adc_read(const uint8_t pin);
void adc_get_pwm_values(const uint8_t pin, const uint16_t period_us1, uint16_t* on_time_us, uint16_t* off_time_us);

#endif /* ADC_H_ */