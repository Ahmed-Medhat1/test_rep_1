/*
 * KPD_prg.c
 *
 *  Created on: Jul 17, 2022
 *      Author: lEGION
 */

#include "../../LIB/STD_TYPES.h"
#include"../../MCAL/DIO/DIO_int.h"
#include "KPD_int.h"

void KPD_vInit(void)
{

	DIO_vSetPortDir(KPD_PORT,0x0f);
	DIO_vSetPortVal(KPD_PORT,0xff);


}
u8 KPD_u8GetPressedKey(void)
{

	u8 pressed_key= 0;

	for(u8 col=0;col<4;col++)
	{
		/*activate current column*/
		DIO_vSetPinVal(KPD_PORT,col,DIO_LOW);
		for( u8 row=0;row<4;row++)
		{
			if(DIO_u8GetPinVal(KPD_PORT,row+4)==0) //a button is pressed

			{

				pressed_key= row + (col*4) +1; // key number
			}
			while(DIO_u8GetPinVal(KPD_PORT,row+4)==0){}
			_delay_ms(10);
		}
		/*deactivate column*/
		DIO_vSetPinVal(KPD_PORT,col,DIO_HIGH);
	}

	return pressed_key;
}
