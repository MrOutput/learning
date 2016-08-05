/*
PWD: Mode 5 (phase correct)
CLKt0: CLKio / 8
Duty Cycle: 50%

Toggle OC0A on match
*/
#include <avr/io.h>

int main(void)
{
    TCCR0A = _BV(WGM00) | _BV(COM0A0);
    TCCR0B = _BV(CS01) | _BV(WGM02);
    OCR0A = 0xFF >> 1;

    DDRD = _BV(DDD6);

    while (1);
}
