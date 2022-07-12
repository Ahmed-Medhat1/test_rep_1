/*
 * main.c
 *
 *  Created on: Jul 12, 2022
 *      Author: lEGION
 */

#include <avr/io.h>
#include<util/delay.h>
#include "BIT_MATH.H"

int main(void)
{
	SET_BIT(DDRA,0); //PA0->OUTPUT
		CLR_BIT(DDRA,1); //PA1->INPUT
		SET_BIT(PORTA,1); //ENABLE PULLUP ON PA1


		while(1)//SUPER LOOP
		{
			if(GET_BIT(PINA,1)==0)
			{
				while(GET_BIT(PINA,1)==0){}
				_delay_ms(10);
				TOG_BIT(PORTA,0);
	// press led on press one more led off toggling
			}
}
}
