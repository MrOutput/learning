#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>


ISR(TIMER0_COMPA_vect)
{
    OCR0A++;
}


int main(void)
{
    DDRD = _BV(DDD6);
    TCCR0A = _BV(WGM00);//PHASE CORRECT PWM MODE 1
    TIMSK0 = _BV(OCIE0A);
    OCR0A = 0x00;//INIT PWM TOP
    sei();

    for (;;) {
        sleep_mode();
    }
}
