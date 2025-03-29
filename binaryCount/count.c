#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
   // Set digital pins to output
   DDRD |= (1 << PD4);  // Pin 4
   DDRD |= (1 << PD6);  // Pin 6
   DDRB |= (1 << PB0);  // Pin 8
   DDRB |= (1 << PB2);  // Pin 10
   uint8_t count = 0;
   while (1)
   {
      if (count & (1))
      {
         PORTD |= (1 << PD4);
      }
      else
      {
         PORTD &= ~(1 << PD4);
      }

      if (count & (1 << 1))
      {
         PORTD |= (1 << PD6);
      }
      else
      {
         PORTD &= ~(1 << PD6);
      }

      if (count & (1 << 2))
      {
         PORTB |= (1 << PB0);
      }
      else
      {
         PORTB &= ~(1 << PB0);
      }

      if (count & (1 << 3))
      {
         PORTB |= (1 << PB2);
      }
      else
      {
         PORTB &= ~(1 << PB2);
      }

      if (count == 15)
      {
         count = 0;
      }

      _delay_ms(10000);
      count++;
   }
}