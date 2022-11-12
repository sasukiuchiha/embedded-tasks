/*
 * ADC_Driver_config.h
 *
 *  Created on: Nov 4, 2022
 *      Author: moham
 */

#ifndef ADC_DRIVER_CONFIG_H_
#define ADC_DRIVER_CONFIG_H_

/********ADMUX_REG_BITS**********/
#define ADMUX_MUX0     BIT0
#define ADMUX_MUX1     BIT1
#define ADMUX_MUX2     BIT2
#define ADMUX_MUX3     BIT3
#define ADMUX_MUX4     BIT4
#define ADMUX_ADLAR	   BIT5
#define ADMUX_REFS0    BIT6
#define ADMUX_REFS1	   BIT7
/********************************/

/**********VOLT_REF_SELECTION***************/
#define AREF    	           0
#define EXTRNAL_VCC  	       1
#define INTERNAL_VOLT          2
/******************************************/

/**********ADC_Normal_CHANNELS**************/

#define CHANNEL_0    0
#define CHANNEL_1    1
#define CHANNEL_2    2
#define CHANNEL_3    3
#define CHANNEL_4    4
#define CHANNEL_5    5
#define CHANNEL_6    6
#define CHANNEL_7    7
#define CHANNEL_30   30   //1.22V (VBG)
#define CHANNEL_31   31   //0V GND
/*********************************************/

/**********ADC_DIFFERENTIAL_CHANNELS**********/

#define CHANNEL_8     8
#define CHANNEL_9     9
#define CHANNEL_10    10
#define CHANNEL_11    11
#define CHANNEL_12    12
#define CHANNEL_13    13
#define CHANNEL_14    14
#define CHANNEL_15    15
#define CHANNEL_16    16
#define CHANNEL_17    17
#define CHANNEL_18    18
#define CHANNEL_19    19
#define CHANNEL_20    20
#define CHANNEL_21    21
#define CHANNEL_22    22
#define CHANNEL_23    23
#define CHANNEL_24    24
#define CHANNEL_25    25
#define CHANNEL_26    26
#define CHANNEL_27    27
#define CHANNEL_28    28
#define CHANNEL_29    29
/*********************************************/

/*********ADCSRA_REG_BITS*******************/

#define ADCSRA_ADPS0    BIT0  //PRESCALLER
#define ADCSRA_ADPS1    BIT1  //PRECALLSER
#define ADCSRA_ADPS2    BIT2  //control the time of the one cycle
#define ADCSRA_ADIE     BIT3  //to enable the interrupt prephral
#define ADCSRA_ADIF     BIT4  //to read the flag of the interrupt
#define ADCSRA_ADATE    BIT5  // one for enable  auto triggering zero for disable triggering
#define ADCSRA_ADSC     BIT6  //PUT 1 means start conversion ,0 no conversion
#define ADCSRA_ADEN	    BIT7  //ENABLE BY 1 OR DISABLE BY 0 OF ADC
/*********************************************************/


/***************SFIOR_REG_BITS*************************/

#define SFIOR_ADTS0    BIT5
#define SFIOR_ADTS1    BIT6
#define SFIOR_ADTS2    BIT7
/*******************************************************/

/*****************TRIGGER_SOURCES*******************/
#define  FREE_RUN_MODE                     0
#define  ANALOG_COMPARATOR				   1
#define  EXTERNAL_INTERRUPT_REQ0           2
#define  TIMER0_OR_COUNTER0_COMPARE_MATCH  3
#define  TIMER0_OR_COUNTER0_OVERFLOW       4
#define  TIMER_OR_COUNTER_COMPARE_MATCH_B  5
#define  TIMER1_OR_COUNTER1_OVERFLOW       6
#define  TIMER1_OR_COUNTER1_CAPTURE_EVENT  7
/*******************************************************/





#endif /* ADC_DRIVER_CONFIG_H_ */
