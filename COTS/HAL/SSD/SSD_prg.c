/*
 * SSD_prg.c
 *
 *  Created on: Jul 13, 2022
 *      Author: lEGION
 */

#include"../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include"SSD_int.h"

static const u8 CGS_u8SSD_Nums[]=
 {
	0b11111100,
	0b01100000,
	0b11011010,
	0b11110010,
	0b01100110,
	0b10110110,
	0b10111110,
	0b11100000,
	0b11111110,
	0b11100110,
 };

void SSD_vInit(void)
{
	DIO_vSetPortDir(SSD_PORT,0xff);
}
void SSD_vDisplayNum(u8 A_u8Num)
{
	/* input validation */
  if(A_u8Num<10)
  {
#if SSD_TYPE==COM_CATHODE
	DIO_vSetPortVal(SSD_PORT,CGS_u8SSD_Nums[A_u8Num]);
#elif 	SSD_TYPE==COM_ANODE
	DIO_vSetPortVal(SSD_PORT,~CGS_u8SSD_Nums[A_u8Num]);
#endif

  }

}
void SSD_vTurnOff(void)
{
#if SSD_TYPE==COM_CATHODE
	DIO_vSetPortVal(SSD_PORT,0);
#elif SSD_TYPE==COM_ANODE
	DIO_vSetPortVal(SSD_PORT,0xff);
#endif

}
