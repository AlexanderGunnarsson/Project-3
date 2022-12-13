#include "header.h"

static inline void init_interrupts(void);

struct led l1, l2, l3, l4, l5;
struct button b1, b2, b3, b4, b5;
struct led_vector v1;
volatile bool led1_enabled = false;
volatile bool led2_enabled = false;
volatile bool led3_enabled = false;
volatile bool led4_enabled = false;
volatile bool led5_enabled = false;

void setup(void)
{
	led_init(&l1, 6);
	led_init(&l2, 7);
	led_init(&l3, 8);
	led_init(&l4, 9);
	led_init(&l5, 10);
	
	button_init(&b1, 2);
	button_init(&b2, 3);
	button_init(&b3, 11);
	button_init(&b4, 12);
	button_init(&b5, 13);
	
	led_vector_init(&v1);
	
	led_vector_push(&v1, &l1);
	led_vector_push(&v1, &l2);
	led_vector_push(&v1, &l3);
	led_vector_push(&v1, &l4);
	led_vector_push(&v1, &l5);
	
	(void)adc_read(0); // Initierar analoga kretsar.
	init_interrupts();
	
	return;
}

static inline void init_interrupts(void)
{
	asm("SEI");
	EICRA = (1<< ISC01) | (1<<ISC00) | (1<<ISC11) | (1<<ISC10); // Ställer in flanker.
	EIMSK = (1<< INT1) | (1<< INT0); // Aktiverar avbrotten.
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << PCINT3) | (1 << PCINT4) | (1 << PCINT5);
	return;
}