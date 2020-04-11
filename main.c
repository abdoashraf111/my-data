/*
 * File:   main.c
 * Author: 20115
 *
 * Created on April 11, 2020, 3:23 AM
 */


#include <xc.h>
#define BUTTON2 2
#define LED2 3

#define BUTTON1 4
#define LED1 7

#define BUTTON0 0
#define LED0 2

int main(void) {
    DDRD &= ~(1 << BUTTON2);
    DDRD |= (1 << LED2);

    DDRB &= ~(1 << BUTTON1);
    DDRC |= (1 << LED1);

    DDRB &= ~(1 << BUTTON0);
    DDRC |= (1 << LED0);

    DDRA |= (1 << 3);

    while (1) {
        if (PIND & (1 << BUTTON2)) {
            PORTD |= (1 << LED2);
            PORTA |= (1 << 3);

        } else {
            PORTD &= ~(1 << LED2);

        }

        if (PINB & (1 << BUTTON1)) {
            PORTC |= (1 << LED1);
            PORTA |= (1 << 3);
        } else {
            PORTC &= ~(1 << LED1);
        }

        if (PINB & (1 << BUTTON0)) {
            PORTC |= (1 << LED0);
            PORTA |= (1 << 3);
        } else {
            PORTC &= ~(1 << LED0);
        }
        
        
        if(!(PIND & (1 << BUTTON2))&&!(PINB & (1 << BUTTON1))&&!(PINB & (1 << BUTTON0))){
             PORTA &= ~(1<<3);
        }
    }
    return 0;
}
