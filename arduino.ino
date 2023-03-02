#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 16000000L
#endif

void IO_init();
void PWM_init();

int main()
{
    IO_init();
    PWM_init();
    sei();
    while(1){}

}

void IO_init()
{
    DDRB = 0b00000110; 
    DDRD = 0b01100000; 
}

void PWM_init()
{
    SREG = 0b10000000;
    TCNT1 = 0;
    
    // Set PWM frequency to 10 kHz
    OCR1A = 220;
    OCR1B = 220;
    TCCR1A = (1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (1<<WGM10); 
    TCCR1B = (0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (0<<CS10);



    TIMSK1 = 0b00000001;
}
