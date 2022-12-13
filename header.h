
#ifndef HEADER_H_
#define HEADER_H_

#include "led.h"
#include "button.h"
#include "led_vector.h"
#include "adc.h"

#define POT1 0

extern struct led l1, l2, l3, l4, l5;
extern struct button b1, b2, b3, b4, b5;
extern struct led_vector v1;
extern volatile bool led1_enabled;
extern volatile bool led2_enabled;
extern volatile bool led3_enabled;
extern volatile bool led4_enabled;
extern volatile bool led5_enabled;

void setup(void);

#endif /* HEADER_H_ */