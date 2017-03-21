#include <avr/io.h>
#define F_CPU 500000UL
#include <avr/sleep.h>
#include <inttypes.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(TIMER0_COMPA_vect)
{
    static uint8_t dir;
    if (OCR0A == 0 || OCR0A == 255) {
        dir = !dir;

        PINB |= _BV(PB6);
        _delay_ms(100);
        PINB |= _BV(PB6);
        _delay_ms(100);
    }
    OCR0A += dir ? 1 : -1;
}

int main(void)
{
    DDRD = _BV(DDD6);//set PD6 output
    DDRB = _BV(DDB6);//set PB6 output
        PORTB |= _BV(PORTB6);
        PORTD |= _BV(PORTD6);

    MCUCR = _BV(BODS) | _BV(BODSE);//disable BOD
    PRR = _BV(PRTWI) | _BV(PRTIM2) | _BV(PRTIM1) | _BV(PRSPI) | _BV(PRUSART0) | _BV(PRADC);//disable unused features
    CLKPR = _BV(CLKPS0);//clk prescale 2

    //TCCR0A = _BV(COM0A1) | _BV(WGM01) | _BV(WGM00);//set OC0A on compare match; Fast PWM
    //TCCR0B = _BV(CS01);
    //TIMSK0 = _BV(OCIE0A);//enable output compare int for OA; enable ov int

    //sei();

    sleep_enable();
    for (;;) {
        sleep_mode();
    }

    return 0;
}
