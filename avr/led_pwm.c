#include <avr/io.h>
#include <avr/interrupt.h>


ISR(TIMER0_COMPA_vect)
{
    OCR0A += 1;
}


int main(void)
{
    DDRD = _BV(DDD6);
    TCCR0A = _BV(WGM00);//PHASE CORRECT PWM MODE 1
    //TIMSK0 = _BV(OCIE0A);
    TIMSK0 = 0x02;
    OCR0A = 0x00;//INIT PWM TOP
    sei();

    for (;;) {
    }
}
