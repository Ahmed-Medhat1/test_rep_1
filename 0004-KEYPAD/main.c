/*
 * main.c
 *
 *  Created on: Jul 12, 2022
 *      Author: lEGION
 */
#include "STD_TYPES.h"
#include<avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"

void KEYPAD_Init(void)
{
	DDRB=0x0f; /* PORTB -> input/output*/
	PORTB=0xff; //pull up resistor activation on inputs

}

 u8 GetPressedKey(void)
 {

	 u8 pressed_key= 0;

	for(u8 col=0;col<4;col++)
	{
		/*activate current column*/
		CLR_BIT(PORTB,col);
		for( u8 row=0;row<4;row++)
		{
			if(GET_BIT(PINB,row+4)==0) //a button is pressed

			{

				pressed_key= row + (col*4) +1; // key number
			}
			while(GET_BIT(PINB,row+4)==0){}
			_delay_ms(10);
		}
		/*deactivate column*/
	     SET_BIT(PORTB,col);
	}

	 return pressed_key;


 }

int main(void)
{
	KEYPAD_Init();
u8 key=0;

	while(1)
	{
   key = GetPressedKey();
   if(key !=0)
{
    /*	seven segment display*/
}
	}
}
