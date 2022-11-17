/*
 * TIMER_DRIVER_private.h
 *
 *  Created on: Nov 13, 2022
 *      Author: moham
 */

#ifndef TIMER_DRIVER_PRIVATE_H_
#define TIMER_DRIVER_PRIVATE_H_


/***********************************TCCR0_REG***********************************/
//--|FUNCTION-->CONTROL  REGISTER FOR TIMER0
#define TCCR0_REG    *((volatile u8 *)0X53)
/******************BIT0,1,2_FUNCTIONS*******************************************/
//--|FUNCTION-->SELECT THE CLOCK SOURCE
//--|NO CLOCK
//--|CLOCK WITH NO PRESCALLING
//--|CLOCK WITH PRESCALLING BY[8,64,256,1024]
//--|EXTERNAL CLOCK ON TO PIN T0 ,CLOCK ON FALLING EDGE
//--|EXTERNAL CLOCK ON TO PIN T0 ,CLOCK ON RAISING EDGE
//--| **************************************************************************/
#define CS00               BIT0
#define CS01               BIT1
#define CS02               BIT2
//*****************************************************************************/

/******************BIT4,5_FUNCTIONS*********************************************/
//--|FUNCTION-->CONTROL OC0 OUTPUT THROUGH 3 MODES
//--|NON PWM_MODE-->[set,or clear or toggle or disconnect to OC0]
//--|FAST PWM_MODE-->[set,or clear or disconnect to OC0]
//--|PWM OR PHASE_CORRECT-->[set,or clear or disconnect to OC0]
//--| **************************************************************************/
#define COM00 			   BIT4
#define COM01              BIT5
/*******************************************************************************/

/******************BIT3,6_FUNCTIONS*********************************************/
//--|select the mode of operation-->[normal mode,PWN,PHASE CORRECT,CTC,FAST PWM]
//--| ***************************************************************************
#define WGM01              BIT3
#define WGM00			   BIT6
/*******************************************************************************/

/******************BIT7_FUNCTIONS**********************************************/
//--|force compare match by setting it[GENERATE INTERRUPT TO TEST COMPARE MATCH]
//--|it used for testing
//--| **************************************************************************
#define FOC0			   BIT7
/******************************************************************************/


/***********************TCNT0_REG***********************************************/
//--|FUNCTION-->STORE THE COUNTER/TIMER DATA OR READ DATA
#define TCNT0_REG    *((volatile u8 *)0X52)
/******************************************************************************/

/*************************OCR0_REG*********************************************/
//--|compare register FUNCTION-->write the compare value here
#define OCR0_REG    *((volatile u8 *)0X5C)
/******************************************************************************/


/**************************TIMSK_REG*******************************************/
//--|INTERRUPT MASK REGISTER FUNCTION-->WORK AS PIE
#define TIMSK_REG    *((volatile u8 *)0X59)

/******************BIT0_FUNCTIONS**********************************************/
//--|ENABLE THE OVERFLOW INTERRUPT FOR TIMER0-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define TOIE0               BIT0
//********************************************************************************
/******************BIT1_FUNCTIONS***********************************************/
//--|ENABLE THE COMAPRE MATCH INTERRUPT FOR TIMER0-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define OCIE0               BIT1
/*******************************************************************************/
/******************BIT2_FUNCTIONS**********************************************/
//--|ENABLE THE OVERFLOW INTERRUPT FOR TIMER1-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define TOIE1               BIT2
//********************************************************************************
/******************BIT3_FUNCTIONS***********************************************/
//--|ENABLE THE COMAPRE MATCH INTERRUPT FOR TIMER1B-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define OCIE1B               BIT3
/*******************************************************************************/
/******************BIT4_FUNCTIONS**********************************************/
//--|ENABLE THE COMAPRE MATCH INTERRUPT FOR TIMER1A-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define OCIE1A               BIT4
//********************************************************************************
/******************BIT5_FUNCTIONS***********************************************/
//--|ENABLE INPUT CAPTURE UNIT INTERRUPT FOR TIMER1-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define TICIE1               BIT5
/*******************************************************************************/
/******************BIT6_FUNCTIONS**********************************************/
//--|ENABLE THE overflow INTERRUPT FOR TIMER2-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define TOIE2               BIT6
//********************************************************************************
/******************BIT7_FUNCTIONS***********************************************/
//--|ENABLE COMAPRE MATCH INTERRUPT FOR TIMER2-->BY SETTING IT WITH 1
//--| ***************************************************************************
#define OCIE2               BIT7
/*******************************************************************************/



/*********************************TIFR_REG**************************************/
//--|INTERRUPT FLAG REGISTER FUNCTION-->WORK AS PIF
#define TIFR_REG    *((volatile u8 *)0X58)
/**************************BIT0_FUNCTIONS********************************************/
//--|FLAG FOR THE OVERFLOW INTERRUPT FOR TIMER0-->BECOME ONE IF OVERFLOW INTERRUPT OCCURED
//--| ********************************************************************************
#define TOV0               BIT0
//************************************************************************************
/***********************************BIT1_FUNCTIONS***********************************/
//--|FLAG FOR THE COMAPRE MATCH INTERRUPT FOR TIMER0-->BECOME ONE IF COMAPRE MATCH INTERRUPT OCCURED
//--| *******************************************************************************
#define OCF0               BIT1
/************************************************************************************/
/**************************BIT2_FUNCTIONS********************************************/
//--|FLAG FOR THE OVERFLOW INTERRUPT FOR TIMER1-->BECOME ONE IF OVERFLOW INTERRUPT OCCURED
//--| ********************************************************************************
#define TOV1               BIT2
//************************************************************************************
/***********************************BIT3_FUNCTIONS***********************************/
//--|FLAG FOR THE COMAPRE MATCH INTERRUPT FOR TIMER1B-->BECOME ONE IF COMAPRE MATCH INTERRUPT OCCURED
//--| *******************************************************************************
#define OCF1B               BIT3
/************************************************************************************/
/**************************BIT4_FUNCTIONS********************************************/
//--|FLAG FOR THE COMAPRE MATCH INTERRUPT FOR TIMER1A-->BECOME ONE IF OVERFLOW INTERRUPT OCCURED
//--| ********************************************************************************
#define OCF1A               BIT4
//************************************************************************************
/***********************************BIT5_FUNCTIONS***********************************/
//--|FLAG FOR INPUT CAPTURE UNIT INTERRUPT FOR TIMER1-->BECOME ONE IF COMAPRE MATCH INTERRUPT OCCURED
//--| *******************************************************************************
#define ICF1               BIT5
/************************************************************************************/
/**************************BIT6_FUNCTIONS********************************************/
//--|FLAG FOR OVERFLOW INTERRUPT FOR TIMER2-->BECOME ONE IF OVERFLOW INTERRUPT OCCURED
//--| ********************************************************************************
#define TOV2               BIT6
//************************************************************************************
/***********************************BIT7_FUNCTIONS***********************************/
//--|FLAG FOR INPUT COMPARE MATCH INTERRUPT FOR TIMER2-->BECOME ONE IF COMAPRE MATCH INTERRUPT OCCURED
//--| *******************************************************************************
#define OCF2               BIT7
/************************************************************************************/



/*********************************SFIOR_REG******************************************/
//--|FUNCTION-->REST THE PRESCALLER
#define SFIOR_REG    *((volatile u8 *)0X50)
/**************************BIT0_FUNCTIONS********************************************/
//--|REST THE PRESACLLER VALUE FOR TIMER0,TIMER1-->BY SETTING IT WITH 1
//--| ********************************************************************************
#define PSR10               BIT0
//************************************************************************************
/**************************BIT1_FUNCTIONS********************************************/
//--|REST THE PRESACLLER VALUE FOR TIMER2,TIMER1-->BY SETTING IT WITH 1
//--| ********************************************************************************
#define PSR2                BIT1
//************************************************************************************



/***********************************TCCR1A_REG***************************************/
//--|FUNCTION-->CONTROL  REGISTER FOR TIMER1
#define TCCR1A_REG    *((volatile u8 *)0X4F)    //CONTROL REGISTER
/******************BIT0,1_FUNCTIONS************************************************/
//--|FUNCTION-->control the counting sequence
//--|and what type of waveform generation to be used
//--|they used with WGM12,WGM13 in TCCR1B_REG
//--| ******************************************************************************/
#define WGM10               BIT0
#define WGM11               BIT1

//**********************************************************************************/
/******************BIT4,5_FUNCTIONS*********************************************/
//--|FUNCTION-->CONTROL OC1B OUTPUT THROUGH 3 MODES
//--|NON PWM_MODE-->[set,or clear or toggle or disconnect to OC1B]
//--|FAST PWM_MODE-->[set,or clear or disconnect to OC1B]
//--|PWM OR PHASE_CORRECT-->[set,or clear or disconnect to OC1B]
//--| **************************************************************************/
#define COM1B0 			    BIT4
#define COM1B1              BIT5
/*******************************************************************************/
/******************BIT2,3_FUNCTIONS****************************************************/
//--|BIT2 force compare match by setting it[GENERATE INTERRUPT TO TEST COMPARE MATCH ON OC1B]
//--|BIT3 force compare match by setting it[GENERATE INTERRUPT TO TEST COMPARE MATCH ON OC1A]
//--|they used for testing
//--| *********************************************************************************
#define FOC1B               BIT2
#define FOC1A               BIT3
/*******************************************************************/
/******************BIT6,7_FUNCTIONS*********************************************/
//--|FUNCTION-->CONTROL OC1A OUTPUT THROUGH 3 MODES
//--|NON PWM_MODE-->[set,or clear or toggle or disconnect to OC1A]
//--|FAST PWM_MODE-->[set,or clear Or TOGGLE or disconnect to OC1A]
//--|PWM OR PHASE_CORRECT-->[set,or clear Or TOGGLE or disconnect to OC1A]
//--| **************************************************************************/
#define COM1A0			   BIT6
#define COM1A1			   BIT7
/******************************************************************************/



/***********************************TCCR1B_REG***************************************/
//--|FUNCTION-->INPUT CAPTURE UNIT
#define TCCR1B_REG    *((volatile u8 *)0X4E)
/******************BIT0,1,2_FUNCTIONS*******************************************/
//--|FUNCTION-->SELECT THE CLOCK SOURCE
//--|NO CLOCK
//--|CLOCK WITH NO PRESCALLING
//--|CLOCK WITH PRESCALLING BY[8,64,256,1024]
//--|EXTERNAL CLOCK ON TO PIN T1 ,CLOCK ON FALLING EDGE
//--|EXTERNAL CLOCK ON TO PIN T1 ,CLOCK ON RAISING EDGE
//--| **************************************************************************/
#define CS10               BIT0
#define CS11               BIT1
#define CS12               BIT2
//**********************************************************************************/
/******************BIT3,4_FUNCTIONS************************************************/
//--|FUNCTION-->control the counting sequence
//--|and what type of waveform generation to be used
//--|they used with WGM10,WGM11 in TCCR1A_REG
//--| ******************************************************************************/
#define WGM12               BIT3
#define WGM13 			    BIT4
/***********************************************************************************/
/******************BIT6_FUNCTIONS***********************************************************/
//--|FUNCTION-->This bit selects which edge on the Input Capture Pin (ICP1)
//--|When the ICES1 bit is written to zero, a falling (negative) edge is used as trigger
//--|when the ICES1 bit is written to one, a rising (positive) edge will trigger the capture
//--| **************************************************************************************/
#define ICES1			   BIT6
/*******************************************************************************************/
/******************BIT7_FUNCTIONS*******************************************************/
//--|FUNCTION-->Setting this bitTO 1 activates the Input Capture Noise Canceler
#define ICNC1			   BIT7
/***************************************************************************************/



/***********************************TCNT1H_REG,TCNT1L_REG***************************************/
//--|FUNCTION-->both for read and for write operations
#define TCNT1H_REG           *((volatile u8 *)0X4D) //HIGHER REG
#define TCNT1L_REG           *((volatile u8 *)0X4C) //LOWER REG
#define TCNT1L_TCNT1H_REG    *((volatile u16 *)0X4C)//TO ACCESS BOTH OF THEM AT A TIME
/************************************************************************************************/


/***********************************OCR1AH_REG,OCR1AL_REG***************************************/
//--|FUNCTION-->COMPARE REGISTER FOR 1A
#define OCR1AH_REG           *((volatile u8 *)0X4B) //HIGHER REG
#define OCR1AL_REG           *((volatile u8 *)0X4A) //LOWER REG
#define TCNT1L_OCR1AH_REG    *((volatile u16 *)0X4A)//TO ACCESS BOTH OF THEM AT A TIME
/************************************************************************************************/


/***********************************OCR1BH_REG,OCR1BL_REG***************************************/
//--|FUNCTION-->COMPARE REGISTER FOR 1B
#define OCR1BH_REG           *((volatile u8 *)0X49) //HIGHER REG
#define OCR1BL_REG           *((volatile u8 *)0X48) //LOWER REG
#define OCR1BL_OCR1BH_REG    *((volatile u16 *)0X48)//TO ACCESS BOTH OF THEM AT A TIME
/************************************************************************************************/


/***********************************ICR1H_REG,ICR1L_REG***************************************/
//--|FUNCTION-->INPUT CAPTURE UNIT REGISTER
#define ICR1H_REG           *((volatile u8 *)0X47) //HIGHER REG
#define ICR1L_REG           *((volatile u8 *)0X46) //LOWER REG
#define ICR1L_ICR1H_REG    *((volatile u16 *)0X46)//TO ACCESS BOTH OF THEM AT A TIME
/************************************************************************************************/


/***********************************TCCR2_REG***********************************/
//--|FUNCTION-->CONTROL  REGISTER FOR TIMER0
#define TCCR2_REG    *((volatile u8 *)0X45)
/******************BIT0,1,2_FUNCTIONS*******************************************/
//--|FUNCTION-->SELECT THE CLOCK SOURCE
//--|NO CLOCK
//--|CLOCK WITH NO PRESCALLING
//--|CLOCK WITH PRESCALLING BY[8,64,256,1024]
//--|EXTERNAL CLOCK ON TO PIN T0 ,CLOCK ON FALLING EDGE
//--|EXTERNAL CLOCK ON TO PIN T0 ,CLOCK ON RAISING EDGE
//--| **************************************************************************/
#define CS20               BIT0
#define CS21               BIT1
#define CS22               BIT2
//*****************************************************************************/
/******************BIT4,5_FUNCTIONS*********************************************/
//--|FUNCTION-->CONTROL OC2 OUTPUT THROUGH 3 MODES
//--|NON PWM_MODE-->[set,or clear or toggle or disconnect to OC2]
//--|FAST PWM_MODE-->[set,or clear or disconnect to OC2]
//--|PWM OR PHASE_CORRECT-->[set,or clear or disconnect to OC2]
//--| **************************************************************************/
#define COM20 			   BIT4
#define COM21              BIT5
/*******************************************************************************/
/******************BIT3,6_FUNCTIONS*********************************************/
//--|select the mode of operation-->[normal mode,PWN,PHASE CORRECT,CTC,FAST PWM]
//--| ***************************************************************************
#define WGM21              BIT3
#define WGM20			   BIT6
/*******************************************************************************/
/******************BIT7_FUNCTIONS**********************************************/
//--|force compare match by setting it[GENERATE INTERRUPT TO TEST COMPARE MATCH]
//--|it used for testing
//--| **************************************************************************
#define FOC2			   BIT7
/******************************************************************************/



/***********************TCNT2_REG***********************************************/
//--|FUNCTION-->STORE THE COUNTER/TIMER2 DATA OR READ DATA
#define TCNT2_REG    *((volatile u8 *)0X44)
/******************************************************************************/


/*************************OCR2_REG*********************************************/
//--|compare register FOR TIMER/COUNTER 2 FUNCTION-->write the compare value here
#define OCR2_REG    *((volatile u8 *)0X43)
/******************************************************************************/


/***********************************AASR_REG***********************************/
//--|FUNCTION-->CONTROL  REGISTER FOR TIMER0
#define AASR_REG    *((volatile u8 *)0X45)
/******************BIT0_FUNCTIONS*******************************************/
//--|FUNCTION-->When Timer/Counter2 operates asynchronously and TCCR2 is written,
//--|this bit becomes set.
//--|A logical zero in this bit indicates that TCCR2 is ready to be
//--|updated with a new value
//--|FOR CONTROL REGISTER
//--| **************************************************************************/
#define TCR2UB               BIT0
/******************BIT1_FUNCTIONS*******************************************/
//--|FUNCTION-->When Timer/Counter2 operates asynchronously and OCR2 is written,
//--|this bit becomes set.
//--|A logical zero in this bit indicates that OCR2 is ready to be
//--|updated with a new value
//--|FOR COMPARE REGISTER
//--|***************************************************************************/
#define OCR2UB               BIT1
/******************BIT2_FUNCTIONS*******************************************/
//--|FUNCTION-->When Timer/Counter2 operates asynchronously and TCNT2 is written,
//--|this bit becomes set.
//--|A logical zero in this bit indicates that TCNT2 is ready to be
//--|updated with a new value
//--|FOR DATA REGISTER
//--|***************************************************************************/
#define TCN2UB               BIT2
//*****************************************************************************/
/******************BIT3_FUNCTIONS*********************************************/
//--|FUNCTION-->When AS2 is written to zero, Timer/Counter 2 is clocked
//--|from the I/O clock, clkI/O.
//--|when AS2 is written to oneTimer/Counter2 is clocked from a Crystal Oscillator
//--|connected to the Timer Oscillator 1 (TOSC1) pin
//--|***************************************************************************/
#define AS2 			   BIT3
/*******************************************************************************/



#endif
