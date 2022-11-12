/*
 * CAL_DIO_interface.h
 *
 *  Created on: Oct 12, 2022
 *      Author: moham
 */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/*****PINs_id*****/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
/*****************/

/****BITS_ID******/
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7
/*****************/

/********PIN_VALUE*****/
#define HIGH	1
#define	LOW		0
/*********************/


/******DIRECTION******/
#define OUTPUT 	1
#define INPUT  	0
/*********************/


/****register_ID*****/
#define PORTA 0
#define PORTB 1
#define	PORTC 2
#define	PORTD 3
/*******************/



/*********************DIO_SetPort_Dir********************************************
 **INPUTS:-->port_id for example [PORTA,PORTB,PORTC,PORTD]
 **       |
 **       -->dir for example [ ANY VALUE FROM 0 TO 255]
 **OUTPUT: return nothing
 **
 **DESCRIPTION:set the direction of the selected ddr_reg
 *********************************************************************************/
void DIO_vSetPort_Dir(u8 port_id,u8 port_dir);

/*********************DIO_SetPort_Val********************************************
 **INPUTS:-->port_id for example [PORTA,PORTB,PORTC,PORTD]
 **       |
 **       -->val for example [ ANY VALUE FROM 0 TO 255]
 **OUTPUT: return nothing
 **
 **DESCRIPTION:set the value of the selected port_reg
 *********************************************************************************/
void DIO_vSetPort_Val(u8 port_id,u8 port_val);

/*********************DIO_SetPort_Val********************************************
 **INPUTS:-->port_id for example [PORTA,PORTB,PORTC,PORTD]
 **OUTPUT: return the value in thee selected port register as u8
 **
 **DESCRIPTION:return the value in thee selected port register as u8
 *********************************************************************************/
u8 DIO_u8GetPORT_Val(u8 port_id);

/*********************DIO_SetPin_Dir********************************************
 **INPUTS:-->port_id  for example [PORTA,PORTB,PORTC,PORTD]
 **       |
 **       -->pins_id for example [PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7]
 **       |
 **       -->dir for example [INPUT,OUTPUT]
 **OUTPUT: return nothing
 **
 **DESCRIPTION:set the direction of a certain pin in the selected ddr_register
 *********************************************************************************/
void DIO_vSetPin_Dir(u8 port_id,u8 pin_id,u8 pin_dir);

/*********************DIO_SetPin_Val********************************************
 **INPUTS:-->port_id  for example [PORTA,PORTB,PORTC,PORTD]
 **       |
 **       -->pins_id for example [PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7]
 **       |
 **       -->val for example [HIGH,LOW]
 **OUTPUT: return nothing
 **
 **DESCRIPTION:set the value of a certain pin of the selected port_reg
 *********************************************************************************/
void DIO_vSetPin_Val(u8 port_id,u8 pin_id,u8 pin_val);

/*********************DIO_GetPin_Val********************************************
 **INPUTS:-->pins_id  for example [PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7]
 **       |
 **       -->port_id for example [PORTA,PORTB,PORTC,PORTD]
 **
 **OUTPUT: return the value inside a certain pin of the selected pin_register as unsigned char
 **
 **DESCRIPTION:get the value inside a certain pin of the selected pin_register
 *********************************************************************************/
u8 DIO_u8GetPins_Val(u8 port_id,u8 pin_id);

/*********************DIO_TogglePin_Val********************************************
 **INPUTS:-->port_id  for example [PORTA,PORTB,PORTC,PORTD]
 **       |
 **       -->pins_id for example [PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7]
 **
 **OUTPUT: return nothing
 **
 **DESCRIPTION:toggle the value of a certain pin of the selected port_reg
 *********************************************************************************/

void DIO_vTogglePin_Val(u8 port_id,u8 pin_id,u8 pin_val);//toggle bit of any port

#endif
