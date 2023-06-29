/*
 * knight-rider.c
 *
 * Created: 29/06/2023 03:49:30
 * Author : kamil
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 100

int main(void)
{
	DDRB = 0b00011111; // DDR = data direction register, port B. ddb1 to ddb5 set as output.
	PORTB = 0b00010000;	// PORTB = port B data register. start off with ddb1 high, and rest low
	unsigned char direction;
	
	while (1) {
		if(direction) {
			PORTB = (PORTB << 1); // shift bits left in PORTB left
			if(PORTB == 0b00010000) {
				direction = 0;
			}
		} else {
			PORTB = (PORTB >> 1); // shift bits in PORTB right
			if(PORTB == 0b00000001) {
				direction = 1;
			}
		}
		_delay_ms(BLINK_DELAY_MS);
	}
}

