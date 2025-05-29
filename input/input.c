#define F_CPU 16000000UL
#include <avr/io.h>

int main()
{
   DDRD &= ~(1 << PD2); // Set Digital Pin 2 as input
   DDRD |= (1 << PD6);  // Set Digital Pins 6, 7, 8 to output
   DDRD |= (1 << PD7);
   DDRB |= (1 << PB0);

   while (1)
   {
      if (!(PIND & (1 << PD2)))
      {
         PORTD |= (1 << PD6);
         PORTD &= ~(1 << PD7);
         PORTB &= ~(1 << PB0);
      }
      else
      {
         PORTD &= ~(1 << PD6);
         PORTD |= (1 << PD7);
         PORTB |= (1 << PB0);
      }
   }
}