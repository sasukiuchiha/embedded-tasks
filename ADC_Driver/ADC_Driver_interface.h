/*
 * ADC_Driver_interface.h
 *
 *  Created on: Nov 4, 2022
 *      Author: moham
 */

#ifndef ADC_DRIVER_INTERFACE_H_
#define ADC_DRIVER_INTERFACE_H_

/***********VOLT_REF_MASK******************************/
#define AREF_MASK    	     ADMUX_REG & 0X3F
#define EXTRNAL_VCC_MASK (ADMUX_REG | 0X40)& 0X7F
#define INTERNAL_VOLT_MASK   ADMUX_REG | 0XC0
/*******************************************************/

/***************ADJUSTMENT_MASK************************/
#define ADC_LEFTADJ_MASK       ADMUX_REG | 0X20
#define ADC_RIGHTADJ_MASK      ADMUX_REG & 0XDF
/************************************************/

/**********ADC_CHANNELS_MASK**************/
#define CHANNEL_0_MASK   ADMUX_REG & 0XE0
#define CHANNEL_1_MASK  (ADMUX_REG | 0X01)& 0XE1
#define CHANNEL_2_MASK  (ADMUX_REG | 0X02)& 0XE2
#define CHANNEL_3_MASK  (ADMUX_REG | 0X03)& 0XE3
#define CHANNEL_4_MASK  (ADMUX_REG | 0X04)& 0XE4
#define CHANNEL_5_MASK  (ADMUX_REG | 0X05)& 0XE5
#define CHANNEL_6_MASK  (ADMUX_REG | 0X06)& 0XE6
#define CHANNEL_7_MASK  (ADMUX_REG | 0X07)& 0XE7
#define CHANNEL_8_MASK  (ADMUX_REG | 0X08)& 0XE8
#define CHANNEL_9_MASK  (ADMUX_REG | 0X09)& 0XE9
#define CHANNEL_10_MASK (ADMUX_REG | 0X0A)& 0XEA
#define CHANNEL_11_MASK (ADMUX_REG | 0X0B)& 0XEB
#define CHANNEL_12_MASK (ADMUX_REG | 0X0C)& 0XEC
#define CHANNEL_13_MASK (ADMUX_REG | 0X0D)& 0XED
#define CHANNEL_14_MASK (ADMUX_REG | 0X0E)& 0XEE
#define CHANNEL_15_MASK (ADMUX_REG | 0X0F)& 0XEF
#define CHANNEL_16_MASK (ADMUX_REG | 0X10)& 0XF0
#define CHANNEL_17_MASK (ADMUX_REG | 0X11)& 0XF1
#define CHANNEL_18_MASK (ADMUX_REG | 0X12)& 0XF2
#define CHANNEL_19_MASK (ADMUX_REG | 0X13)& 0XF3
#define CHANNEL_20_MASK (ADMUX_REG | 0X14)& 0XF4
#define CHANNEL_21_MASK (ADMUX_REG | 0X15)& 0XF5
#define CHANNEL_22_MASK (ADMUX_REG | 0X16)& 0XF6
#define CHANNEL_23_MASK (ADMUX_REG | 0X17)& 0XF7
#define CHANNEL_24_MASK (ADMUX_REG | 0X18)& 0XF8
#define CHANNEL_25_MASK (ADMUX_REG | 0X19)& 0XF9
#define CHANNEL_26_MASK (ADMUX_REG | 0X1A)& 0XFA
#define CHANNEL_27_MASK (ADMUX_REG | 0X1B)& 0XFB
#define CHANNEL_28_MASK (ADMUX_REG | 0X1C)& 0XFC
#define CHANNEL_29_MASK (ADMUX_REG | 0X1D)& 0XFD
#define CHANNEL_30_MASK (ADMUX_REG | 0X1E)& 0XFE  //1.22V (VBG)
#define CHANNEL_31_MASK  ADMUX_REG |0X1F
/**********************************************************/

/*************ADC_EN_AND_DISABLE_MASK****************************/
#define ADC_EN_MASK              ADCSRA_REG | 0X80
#define ADC_DISABLE_MASK         ADCSRA_REG & 0X7F
/*****************************************************************/

/*****************ADC_sTART_CONVERSION_AND_AUTO_TRIG**************/
#define ADC_SRCONV_MASK       ADCSRA_REG | 0X40
#define ADC_AUTO_TRIG_MASK    ADCSRA_REG | 0X20
/*****************************************************************/

/***************ADC_FLAG_AND_ENABLE_MASK*********************/
#define ADC_PIF_MASK          ADCSRA_REG | 0X10
#define ADC_PIE_MASK          ADCSRA_REG | 0X08
/*************************************************************/

/*************PRESCALLER_MASKS********************************/
#define ADC_PRESCALL_2_MASK        ADCSRA_REG & 0XF8
#define ADC_PRESCALL_4_MASK       (ADCSRA_REG | 0X02)& 0XFA
#define ADC_PRESCALL_8_MASK       (ADCSRA_REG | 0X03)& 0XFB
#define ADC_PRESCALL_16_MASK      (ADCSRA_REG | 0X04)& 0XFC
#define ADC_PRESCALL_32_MASK      (ADCSRA_REG | 0X05)& 0XFD
#define ADC_PRESCALL_64_MASK      (ADCSRA_REG | 0X0C)& 0XFC
#define ADC_PRESCALL_128_MASK     (ADCSRA_REG | 0X07)& 0XFF
/**********************************************************/

/***************TRIGER_SOURCE_MASK**************************************/
#define FREE_RUNNING_MASK                       SFIOR_REG &  0X1F
#define ANALOG_COMAPRATOR_MASK                 (SFIOR_REG | 0X20)& 0X3F
#define EXTERNAL_INTERRUPT_0_MASK              (SFIOR_REG | 0X40)& 0X5F
#define TIMER_OR_COUNTER_COMP_MATCH1_MASK      (SFIOR_REG | 0X60)& 0X7F
#define TIMER_OR_COUNTER_OVERFLOW1_MASK        (SFIOR_REG | 0X80)& 0X9F
#define TIMER_OR_COUNTER_COMP_MATCH2_MASK      (SFIOR_REG | 0XA0)& 0XBF
#define TIMER_OR_COUNTER_OVERFLOW2_MASK        (SFIOR_REG | 0C0)& 0XDF
#define TIMER_OR_COUNTER_CAPTURE_EVENT_MASK    (SFIOR_REG | 0XE0)& 0XFF
/***************************************************************************/

/*********************ADC_GLOBAL_CONFIG_MACROS*********************/
#define PRE_SCALLING_SELECTOR       ADC_PRESCALL_128_MASK
#define VOLT_REF_SELECTOR          INTERNAL_VOLT_MASK
#define CHANNEL_NUM                  CHANNEL_1_MASK
#define ADJ_SELECTOR               ADC_RIGHTADJ_MASK
#define ADC_STATE                      ADC_EN_MASK
#define TRIGR_SOURCE_SELECTOR      FREE_RUNNING_MASK
#define ADC_CHANNEL					    CHANNEL_1
/******************************************************************/

/*****enum for return state from funs**********/
enum State{

	OK=0,NOTOK
};
/**********************************************/

/*******enum for adc_states**********************/
typedef enum ADC_States{
	IDEAL=0,
	RUNNING


}STATE_T;

STATE_T ADC_state=IDEAL;  //intial state to the adc

/***********************************************/

/*****FUNCTION_STATES*******************/
#define NULL_POINTER          (void *) 0
#define NULL                   0
/***************************************/

/*********************************ADC_Vinit********************************/
/*INPUTS:TAKE NOTHING
 *OUTPUT:RETURN NOTHING
 *DESCRIBTION:INTIALIZE THE ADC
****************************************************************************/
void ADC_Vinit(void);


/*********************************ADC_u8GeTADCSync********************************/
/*INPUTS:POINTER REPRESENT THE VALUE OF THE READING OF THE ADC[ENTER VAR ADD TO STORE THE VAL IN]
 *OUTPUT:RETURN ERROR STATE [OK ,NOTOK]
 *DESCRIBTION:GET THE VAL OF THE ANALOG SIGNAL AND STORE IT IN ADC_val
**********************************************************************************/

u8 ADC_u8GeTADCSync(u16 *ADC_val);


/*********************************ADC_u8GeTADCASync********************************/
/*INPUTS:POINTER REPRESENT THE VALUE OF THE READING OF THE ADC[ENTER VAR ADD TO STORE THE VAL IN]
 * ALSO TAKE A POINTER TO FUN TO STORE THE ADD OF THE FUN FROM USER
 *OUTPUT:RETURN ERROR STATE [OK ,NOTOK,RUNNING]
 *DESCRIBTION:GET THE VAL OF THE ANALOG SIGNAL AND STORE IT IN ADC_val
 *NOTE:BEFORE USING THIS FUN ENABLE GLOBAL INTERRUPT
**********************************************************************************/
u8 ADC_u8GeTADCASync(void *add_OfUserFun_ToISR(void),u16 *ADC_Read_Val);


#endif /* ADC_DRIVER_INTERFACE_H_ */
