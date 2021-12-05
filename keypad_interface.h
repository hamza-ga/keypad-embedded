/*
 * keypad_interface.h
 *
 *  Created on: Aug 31, 2021
 *      Author: hp
 */

#ifndef KEYPAD_KEYPAD_INTERFACE_H_
#define KEYPAD_KEYPAD_INTERFACE_H_
#include"../lib/STD.h"

void KeyPad_Init(void) ;
u8 KeyPad_GetPressedKey(void) ;
u8 scankey() ;

#endif /* KEYPAD_KEYPAD_INTERFACE_H_ */
