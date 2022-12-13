#include "header.h"

int main(void)
{  
   setup();
   
   while (1)
   {
	  uint16_t on_time_us, off_time_us;
	  
	  adc_get_pwm_values(POT1, 1000, &on_time_us, &off_time_us);
	  
	  // Tänder aktiverade leds inför on-tiden ska börja:
	  if (led1_enabled) led_on(&l1);
	  if (led2_enabled) led_on(&l2);
	  if (led3_enabled) led_on(&l3);
	  if (led4_enabled) led_on(&l4);
	  if (led5_enabled) led_on(&l5);
	  delay_us(&on_time_us);
	  
	  led_vector_off(&v1);
	  delay_us(&off_time_us);
	  
   }

   return 0;
}