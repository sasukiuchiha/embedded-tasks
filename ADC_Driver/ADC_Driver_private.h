/*
 * ADC_Driver_private.h
 *
 *  Created on: Nov 4, 2022
 *      Author: moham
 */

#ifndef ADC_DRIVER_PRIVATE_H_
#define ADC_DRIVER_PRIVATE_H_

/***********ADMUX_REG***********************/

#define ADMUX_REG  *((volatile u8 *)0X27)    //reg to set vref and channels
/*******************************************/

/*******ADCSRA_REG*************************/
#define ADCSRA_REG  *((volatile u8 *)0X26)   //reg to control the working process of adc
/*****************************************/

/*************ADCL_REG+ADCH_REG************/
#define ADCL_ADCH_REG  *((volatile u16 *)0X24)  //case you want to read 10 bits

/*************ADCH_REG*********************/
#define ADCH_REG   *((volatile u8 *)0X25)      //case you want to read 8 bits
/*****************************************/

/**************ADCL_REG*********************/
#define ADCL_REG  *((volatile u8 *)0X24)      //case you want to read 8 bits
/********************************************/

/*************SFIOR_REG************************/
#define SFIOR_REG  *((volatile u8 *)0X50)     //SELECT THE TRIGER SOURCE
/**********************************************/
#endif /* ADC_DRIVER_PRIVATE_H_ */
