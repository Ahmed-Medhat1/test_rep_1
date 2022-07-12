/*
 * main.c
 *
 *  Created on: Jul 11, 2022
 *      Author: lEGION
 */
#include <avr/io.h>
#include<util/delay.h>
#include "BIT_MATH.H"

int main(void)
{
	//DDRA =0x0f ; //0b00000001;
	SET_BIT(DDRA,0); //PA0->OUTPUT
	CLR_BIT(DDRA,1); //PA1->INPUT
	SET_BIT(PORTA,1); //ENABLE PULLUP ON PA1


	while(1)//SUPER LOOP

	{


	/*	PORTA = 0b00000001;
	_delay_ms(1000);
	PORTA = 0b00000000;
	_delay_ms(1000); */
		//PORTB=0b00000001;
   // for(int i=0;i<4;i++)
   // {

    //	_delay_ms(250);
    	//PORTB <<= 1;

    /* }*/
	if(GET_BIT(PINA,1)==0)
		{
		/*_delay_ms(10);
		if(GET_BIT(PINA,1)==0)
		{
			TOG_BIT(PORTA,0);
			}*/

			SET_BIT(PORTA,0);
		}
		else
		{
			CLR_BIT(PORTA,0);
		}
	}
}

