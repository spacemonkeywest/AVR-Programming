#define F_CPU 1000000UL  // 1MHz internal clock
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << PB0);  // Set PB0 as output (LED)

    while (1) {
        PORTB ^= (1 << PB0); // Toggle LED
        _delay_ms(10000);
    }
}
