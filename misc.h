#ifndef MISC_H_
#define MISC_H_


#define F_CPU 16000000UL 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define D0 0
#define D1 1
#define D2 2 
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

#define B0 8
#define B1 9
#define B2 10
#define B3 11
#define B4 12
#define B5 13

#define C0 14
#define C1 15
#define C2 16 
#define C3 17
#define C4 18
#define C5 19 

#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19


#define set(reg, bit) reg |= (1 << bit)
#define clr(reg, bit) reg &= ~(1 << bit)
#define read(reg, bit) (reg & (1 << bit))

#define delay_us(delay_time_us) ({ \
	for (uint16_t i = 0; i < *delay_time_us; ++i) { \
		_delay_us(1); \
	} \
})

enum io_port
{
   IO_PORTB, IO_PORTC, IO_PORTD, IO_PORT_NONE 
};


void delay_ms(const uint16_t delay_time_ms);

#endif 