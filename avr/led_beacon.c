#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000UL
#include <util/delay.h>

ISR(PCINT0_vect)
{
    PORTB |= _BV(PB6);
    _delay_ms(2000);
    PORTB &= ~(_BV(PB6));
}

int main(void)
{
    DDRB = _BV(DDB6);

    PCICR = _BV(PCIE0);
    PCMSK0 = _BV(PCINT0);
    sei();

    for (;;) {
        for (int i = 0; i < 4; i++) {
            PINB |= _BV(PB6);//TOGGLE
            _delay_ms(75);
        }
        _delay_ms(2000);
    }
}
