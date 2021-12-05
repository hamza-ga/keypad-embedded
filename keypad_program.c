/*
 * keypad_program.c
 *
 *  Created on: Aug 31, 2021
 *      Author: hp
 */

//#include "keypad_private.h"
//#include "keypad_config.h"

#include "../DIO/DIO_interface.h"
#include<avr/eeprom.h>
#include<util/delay.h>
#include"../lib/STD.h"

u8 KeyPad_GetPressedKey()
{
	PORTD=0b11101111;

	_delay_ms(10);

	if((PIND&0b00000001)==0)
	{
		return '7';
	}

	if((PIND&0b00000010)==0)
	{
		return '8';
	}

	if((PIND&0b00000100)==0)
	{
		return '9';
	}

	if((PIND&0b00001000)==0)
	{
			return 'A';
	}

	PORTD=0b11011111;

	_delay_ms(10);

	if((PIND&0b00000001)==0)
	{
		return '4';
	}

	if((PIND&0b00000010)==0)
	{
		return '5';
	}

	if((PIND&0b00000100)==0)
	{
		return '6';
	}

	if((PIND&0b00001000)==0)
	{
		return 'B';
	}

	PORTD=0b10111111;

	_delay_ms(10);

	if((PIND&0b00000001)==0)
	{
		return '1';
	}

	if((PIND&0b00000010)==0)
	{
		return '2';
	}

	if((PIND&0b00000100)==0)
	{
		return '3';
	}

	if((PIND&0b00001000)==0)
	{
		return'C';
	}

	PORTD=0b01111111;

	_delay_ms(10);

	if((PIND&0b00000001)==0)
	{
		return '*';
	}

	if((PIND&0b00000010)==0)
	{
		return '0';
	}

	if((PIND&0b00000100)==0)
	{
		return '#';
	}

	if((PIND&0b00001000)==0)
	{
		return'D';
	}

	return 'a';
}


u8 scankey()
{
	char key='a';

	while(key=='a')
	{
		key=KeyPad_GetPressedKey();
	}

	return key;

}

/*
void KeyPad_Init(void)
{

    DIO_SetPortDirection(DIO_PORTD , 0x0f) ;     //DDR : 0x0f(R C)   or   0xf0(C R)
    DIO_SetPortValue(DIO_PORTD , 0xff) ;         //Value : 0xff  (R C) and (C R)

}


u8 KeyPad_GetPressedKey(void)
{

   u8 pressedkey = 0 ;  // No key is pressed

   for(int c = 0 ; c < n_colums ; c++)
   {
	   DIO_SetPinValue(DIO_PORTD , c , DIO_LOW) ;

	   for(int r = 0 ; r < n_rows ; r++)
	   {

		   if(DIO_GetPinValue(DIO_PORTD , r + n_colums) == 0)
		   {

			   pressedkey = (c + r * n_colums) + 1 ;

		   }

		   while(DIO_GetPinValue(DIO_PORTD , r + n_colums) == 0) {}

		   _delay_ms(10) ;

	   }

	   DIO_SetPinValue(DIO_PORTD , c , DIO_HIGH) ;

   }

   return pressedkey ;

}
*/
