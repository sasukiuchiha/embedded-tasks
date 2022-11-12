/*
 * DIO_register.h
 *
 *  Created on: Sep 27, 2022
 *      Author: moham
 */


//any thing related with the configuration of registers we put it here

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
/* first * to access the value inside the register
 * volatile to prevent the compiler to optimize the value of the address of the registers
 * u8 because the size of the register is 8 bit so i will use char
 * unsigned because i will never put negative value inside a register
 * second * means that this value is address not a normal number
 *  */
/*************PORTA_REGISTER**************/
#define DDRA_REG  *((volatile u8 *) 0x3A)
#define PORTA_REG *((volatile u8 *) 0x3B)
#define PINA_REG  *((volatile u8 *) 0x39)
/*****************************************/

/*************PORTB_REGISTER**************/
#define DDRB_REG  *((volatile u8 *) 0x37)
#define PORTB_REG *((volatile u8 *) 0x38)
#define PINB_REG  *((volatile u8 *) 0x36)
/*****************************************/


/*************PORTC_REGISTER**************/
#define DDRC_REG  *((volatile u8 *) 0x34)
#define PORTC_REG *((volatile u8 *) 0x35)
#define PINC_REG  *((volatile u8 *) 0x33)
/*****************************************/

/*************PORTD_REGISTER**************/
#define DDRD_REG  *((volatile u8 *) 0x31)
#define PORTD_REG *((volatile u8 *) 0x32)
#define PIND_REG  *((volatile u8 *) 0x30)
/*****************************************/

#endif /* DIO_REGISTER_H_ */
