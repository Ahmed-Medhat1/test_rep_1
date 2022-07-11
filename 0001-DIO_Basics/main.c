/*
 * main.c
 *
 *  Created on: Jul 11, 2022
 *      Author: lEGION
 */
#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
	DDRB =0x0f ; //0b00001111;


	while(1)
	{
		//PORTA = 0b00000001;
	//_delay_ms(1000);
	//PORTA = 0b00000000;
	//_delay_ms(1000);
		PORTB=0b00000001;
    for(int i=0;i<4;i++)
    {

    	_delay_ms(250);
    	PORTB <<= 1;

    }
	}

}
