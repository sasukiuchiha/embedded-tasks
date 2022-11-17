/*
 * TIMER_DRIVER_interface.h
 *
 *  Created on: Nov 13, 2022
 *      Author: moham
 */

#ifndef TIMER_DRIVER_INTERFACE_H_
#define TIMER_DRIVER_INTERFACE_H_

/*************TO_FORCE_COMPARE_MATCH INTERRUP_MASK****************/
#define T0_FORCE_COMPMATCH_INTERRUPT_MASK    (TCCR0_REG | 0X80)
/****************************************************************/

/************WAVEFORM_GENERATION_MODE_TIMER0_MASKS****************/
#define T0_NORMAL_MODE_MASK          (TCCR0_REG & 0XB7)
#define T0_PWM_MODE_MASK			((TCCR0_REG | 0X40) & 0XF7)
#define T0_CTC_MODE_MASK			((TCCR0_REG | 0X08) & 0XBF)
#define T0_FASTPWM_MODE_MASK         (TCCR0_REG | 0X48)
/*****************************************************************/

/********COMPARE_MATCH_@PWM_@FAST PWM_OUTPUT_OC0_TIMER0_MASKS**************/
#define  T0_OC0_DISCONNECT_MASK     (TCCR0_REG & 0XCF)
/*TOGGLE AVAILABE FOR COMPARE MATCH AND RESERVED FOR PWM AND FAST PWM*/
#define  T0_OC0_TOGGLE_MASK        ((TCCR0_REG | 0X10) & 0XDF)
#define  T0_OC0_CLEAR_MASK         ((TCCR0_REG | 0X20) & 0XEF)
#define  T0_OC0_SET_MASK            (TCCR0_REG | 0X30)
/**************************************************************************/

/***********************TIMER0_SELECT CLOCK_MASKS**************************/
#define  T0_NO_CLOCK_SOURCE_MASK `				 (TCCR0_REG & 0XF8)
#define  T0_SYSCLOCK_NOPRESCALL_SOURCE_MASK     ((TCCR0_REG | 0X01) & 0XF9)
#define  T0_SYSCLOCK_PRESCALL8_SOURCE_MASK      ((TCCR0_REG | 0X02) & 0XFA)
#define  T0_SYSCLOCK_PRESCALL64_SOURCE_MASK     ((TCCR0_REG | 0X03) & 0XFB)
#define  T0_SYSCLOCK_PRESCALL256_SOURCE_MASK    ((TCCR0_REG | 0X04) & 0XFC)
#define  T0_SYSCLOCK_PRESCALL1024_SOURCE_MASK   ((TCCR0_REG | 0X05) & 0XFD)
#define  T0_EXTCLOCK_FALLEDGE_SOURCE_MASK       ((TCCR0_REG | 0X06) & 0XFE)
#define  T0_SYSCLOCK_RAISEEDGE_SOURCE_MASK      ((TCCR0_REG | 0X07) & 0XFF)
/******************************************************************************/

/*****************TIMER0_INTERRUPTS_ENABLE_MASKS******************************/
#define T0_COMPMATCH_ENABLE_MASK                 (TIMSK_REG | 0X01)
#define T0_OVERFLOW_ENABLE_MASK                  (TIMSK_REG | 0X02)
/******************************************************************************/

/*****************TIMER0_INTERRUPTS_FLAG_MASKS******************************/
#define T0_COMPMATCH_FLAG_MASK                 (TIFR_REG | 0X01)
#define T0_OVERFLOW_FLAG_MASK                  (TIFR_REG | 0X02)
/******************************************************************************/

/********COMPARE_MATCH_@PWM_@FAST PWM_OUTPUT_OC1A_MASKS**************/
#define  T0_OC0_DISCONNECT_MASK     (TCCR1A_REG & 0X3F)
#define  T0_OC0_TOGGLE_MASK        ((TCCR1A_REG | 0X40) & 0X7F)
#define  T0_OC0_CLEAR_MASK         ((TCCR1A_REG | 0X80) & 0XBF)
#define  T0_OC0_SET_MASK            (TCCR1A_REG | 0XC0)
/**************************************************************************/

/********COMPARE_MATCH_@PWM_@FAST PWM_OUTPUT_OC1B_MASKS**************/
#define  T0_OC0_DISCONNECT_MASK     (TCCR1A_REG & 0XCF)
#define  T0_OC0_TOGGLE_MASK        ((TCCR1A_REG | 0X10) & 0XDF)
#define  T0_OC0_CLEAR_MASK         ((TCCR1A_REG | 0X20) & 0XEF)
#define  T0_OC0_SET_MASK            (TCCR1A_REG | 0X30)
/**************************************************************************/

/*************T1A_FORCE_COMPARE_MATCH INTERRUP_MASK****************/
#define T0_FORCE_COMPMATCH_INTERRUPT_MASK    (TCCR1A_REG | 0X08)
/****************************************************************/

/*************T1B_FORCE_COMPARE_MATCH INTERRUP_MASK****************/
#define T0_FORCE_COMPMATCH_INTERRUPT_MASK    (TCCR1A_REG | 0X04)
/****************************************************************/


/*******************WAVE_GENERATION_MODE_TIMER1*************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE NORMAL MODE
#define T1A_NORMAL_MODE_MASK        TCCR1A_REG & 0XFC
#define T1B_NORMAL_MODE_MASK        TCCR1B_REG & 0XE7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE PWM 8 BIT
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X01) & 0XFD
#define T1B_NORMAL_MODE_MASK        TCCR1B_REG & 0XE7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE PWM 9 BIT
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X02) & 0XFE
#define T1B_NORMAL_MODE_MASK        TCCR1B_REG & 0XE7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE PWM 10 BIT
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X03)
#define T1B_NORMAL_MODE_MASK        TCCR1B_REG & 0XE7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE CTC
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG & 0XFC)
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X08) & 0XEF
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE FAST PWM 8 BIT
#define T1A_NORMAL_MODE_MASK        (TCCR1A_REG | 0X01) & 0XFD
#define T1B_NORMAL_MODE_MASK        (TCCR1B_REG | 0X08) & 0XEF
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE FAST PWM 9 BIT
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X02) & 0XFE
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X08) & 0XEF
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE FAST PWM 10 BIT
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X03)
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X08) & 0XEF
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE PWM,PHASE CORRECTION,FREQUANCY CORRECTION
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG & 0XFC)
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X10) & 0XF7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE PWM,PHASE CORRECTION,FREQUANCY CORRECTION
#define T1A_NORMAL_MODE_MASK        (TCCR1A_REG | 0X01) & 0XFD
#define T1B_NORMAL_MODE_MASK        (TCCR1B_REG | 0X10) & 0XF7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE PWM,PHASE CORRECTION
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X02) & 0XFE
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X10) & 0XF7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE PWM,PHASE CORRECTION
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X03)
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X10) & 0XF7
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE CTC
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG & 0XFC)
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X18)
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE FAST PWM
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X02) & 0XFE
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X18)
/**************************************************************/
//APPLAY THIS TWO MASKS TO ACHEIVE THE FAST PWMN
#define T1A_NORMAL_MODE_MASK       (TCCR1A_REG | 0X03)
#define T1B_NORMAL_MODE_MASK       (TCCR1B_REG | 0X18)
/**************************************************************/
/**********************************************************************/


/**************TIMER1B_INPUT_CAPTURE_UNIT_CANCLLER_MASK******************/
#define T1B_INPUT_CAP_CANCLLER_MASK          (TCCR1B_REG | 0X80)
/************************************************************************/

/**************TIMER1B_INPUT_cAPTURE_EDGE_SELECTOR_MASK****************/
#define T1B_INPUT_CAP_FALLING_EDGE_MASK          (TCCR1B_REG & 0XBF)
#define T1B_INPUT_CAP_RAISING_EDGE_MASK          (TCCR1B_REG | 0X40)
/*********************************************************************/

/***********************TIMER1B_SELECT CLOCK_MASKS**************************/
#define  T1B_NO_CLOCK_SOURCE_MASK `				 (TCCR1B_REG & 0XF8)
#define  T1B_SYSCLOCK_NOPRESCALL_SOURCE_MASK     ((TCCR1B_REG | 0X01) & 0XF9)
#define  T1B_SYSCLOCK_PRESCALL8_SOURCE_MASK      ((TCCR1B_REG | 0X02) & 0XFA)
#define  T1B_SYSCLOCK_PRESCALL64_SOURCE_MASK     ((TCCR1B_REG | 0X03) & 0XFB)
#define  T1B_SYSCLOCK_PRESCALL256_SOURCE_MASK    ((TCCR1B_REG | 0X04) & 0XFC)
#define  T1B_SYSCLOCK_PRESCALL1024_SOURCE_MASK   ((TCCR1B_REG | 0X05) & 0XFD)
#define  T1B_EXTCLOCK_FALLEDGE_SOURCE_MASK       ((TCCR1B_REG | 0X06) & 0XFE)
#define  T1B_SYSCLOCK_RAISEEDGE_SOURCE_MASK      ((TCCR1B_REG | 0X07) & 0XFF)
/******************************************************************************/

/*****************TIMER1_INTERRUPTS_ENABLE_MASKS******************************/
#define T1A_COMPMATCH_ENABLE_MASK                 (TIMSK_REG | 0X10)
#define T1B_COMPMATCH_ENABLE_MASK                 (TIMSK_REG | 0X08)
#define T1_INPUTCAPUNIT_ENABLE_MASK               (TIMSK_REG | 0X20)
#define T1_OVERFLOW_ENABLE_MASK                   (TIMSK_REG | 0X04)
/******************************************************************************/

/*****************TIMER1_INTERRUPTS_FLAG_MASKS******************************/
#define T1_INPUTCAPUNIT_FLAG_MASK                (TIFR_REG | 0X20)
#define T1A_COMPMATCH_FLAG_MASK                  (TIFR_REG | 0X10)
#define T1B_COMPMATCH_FLAG_MASK                  (TIFR_REG | 0X08)
#define T1_OVERFLOW_FLAG_MASK                    (TIFR_REG | 0X04)
/******************************************************************************/


/*************T2_FORCE_COMPARE_MATCH INTERRUP_MASK****************/
#define T2_FORCE_COMPMATCH_INTERRUPT_MASK    (TCCR2_REG | 0X80)
/****************************************************************/

/************WAVEFORM_GENERATION_MODE_TIMER2_MASKS****************/
#define T2_NORMAL_MODE_MASK          (TCCR2_REG & 0XB7)
#define T2_PWM_MODE_MASK			((TCCR2_REG | 0X40) & 0XF7)
#define T2_CTC_MODE_MASK			((TCCR2_REG | 0X08) & 0XBF)
#define T2_FASTPWM_MODE_MASK         (TCCR2_REG | 0X48)
/*****************************************************************/

/********COMPARE_MATCH_@PWM_@FAST PWM_OUTPUT_OC2_TIMER2_MASKS**************/
#define  T2_OC0_DISCONNECT_MASK     (TCCR2_REG & 0XCF)
/*TOGGLE AVAILABE FOR COMPARE MATCH AND RESERVED FOR PWM AND FAST PWM*/
#define  T2_OC0_TOGGLE_MASK        ((TCCR2_REG | 0X10) & 0XDF)
#define  T2_OC0_CLEAR_MASK         ((TCCR2_REG | 0X20) & 0XEF)
#define  T2_OC0_SET_MASK            (TCCR2_REG | 0X30)
/**************************************************************************/

/***********************TIMER0_SELECT CLOCK_MASKS**************************/
#define  T2_NO_CLOCK_SOURCE_MASK `				 (TCCR2_REG & 0XF8)
#define  T2_SYSCLOCK_NOPRESCALL_SOURCE_MASK     ((TCCR2_REG | 0X01) & 0XF9)
#define  T2_SYSCLOCK_PRESCALL8_SOURCE_MASK      ((TCCR2_REG | 0X02) & 0XFA)
#define  T2_SYSCLOCK_PRESCALL64_SOURCE_MASK     ((TCCR2_REG | 0X03) & 0XFB)
#define  T2_SYSCLOCK_PRESCALL256_SOURCE_MASK    ((TCCR2_REG | 0X04) & 0XFC)
#define  T2_SYSCLOCK_PRESCALL1024_SOURCE_MASK   ((TCCR2_REG | 0X05) & 0XFD)
#define  T2_EXTCLOCK_FALLEDGE_SOURCE_MASK       ((TCCR2_REG | 0X06) & 0XFE)
#define  T2_SYSCLOCK_RAISEEDGE_SOURCE_MASK      ((TCCR2_REG | 0X07) & 0XFF)
/******************************************************************************/

/*****************TIMER2_INTERRUPTS_ENABLE_MASKS******************************/
#define T2_COMPMATCH_ENABLE_MASK                 (TIMSK_REG | 0X80)
#define T2_OVERFLOW_ENABLE_MASK                  (TIMSK_REG | 0X40)
/******************************************************************************/

/*****************TIMER0_INTERRUPTS_FLAG_MASKS******************************/
#define T2_COMPMATCH_FLAG_MASK                 (TIFR_REG | 0X80)
#define T2_OVERFLOW_FLAG_MASK                  (TIFR_REG | 0X40)
/******************************************************************************/

/***********************TIMER2_STATUS_REGISTER*********************************/
#define T2_CLOCKED_EXTERNALLY_MASK          (ASSR_REG | 0X08)
#define T2_CLOCKED_INTERNALLY_MASK          (ASSR_REG & 0XF7)
#define T2_READ_TCNT2_INDECATOR_MASK        (ASSR_REG &(1<<2))
#define T2_READ_OCR2_INDECATOR_MASK         (ASSR_REG &(1<<1))
#define T2_READ_TCCR2_INDECATOR_MASK        (ASSR_REG &(1<<0))
/*****************************************************************************/

/****************************IMPORTANT_DEFINATIONS*****************************/
#define NULL_POINTER         (void *)0
#define NULL                       0
/******************************************************************************/

enum ERROR_STATE{
	OK=0,
	NOTOK
};


enum GENERATION_MODES{
	NORMAL=0,
	PWM,
	CTC,
	FAST_PWM
};

enum COMPMATCH_OUTPUTPINS_CONTROLLER{
	DISSCONNECT=0,
	TOGGLE,
	CLEAR,
	SET
};

enum PRESCALLER_HANDLER{
	NO_CLOCK=0,
	NO_PRESCALL,
	PRESCALL_8,
	PRESCALL_64,
	PRESCALL_256,
	PRESCALL_1024,
	EXT_CLOCK_FALLING,
	EXT_CLOCK_RASING
};

/****************************GLOBAL_CONFIG_TIMER0********************************/
#define GENERATION_MODE               	    CTC
#define OC0_PIN_OUTPUT_STATE                SET
#define PRESCALL_SELECTOR                PRESCALL_8
#define COMPMATCH_VAL                        250
#define PRELOAD_VALUE                         0
#define FPWM_PWM_GENERATION_MODE             CTC
/********************************************************************************/



/***************************T0_VInit***********************************************/
/*-->INPUTS:TAKE NOTHING
/*-->OUTPUTS:RETURN NOTHING
/*-->DESCRIBTION:INTIALIZE TIMER0
/*-->note=ENABLE GLOBAL INTERRUPT BEFORE USING THIS FUNCTIOM
/*-->ALSO IN CASE OF CTC SET PINS OF OC0,OC1A,OC1B,OC2 TO OUTPUT DIRECTION
 *********************************************************************************/
void T0_VInit(void);


/***************************T0_U8SetCallBack*****************************************/
/*-->INPUTS:POINTER TO FUNCTION(CALLBACK CONCEPT)
/*-->OUTPUTS:RETURN STATUS OF THE FUNCTION AS unsigned char 8 bits
/*-->DESCRIBTION:GIVE THE ADDRESS OF THE APPLICATION FUN TO GLOBAL POINTER TO FUNCTION
 ************************************************************************************/
u8 T0_U8SetCallBack(void (*FunHolder)(void));

#endif /* TIMER_DRIVER_INTERFACE_H_ */
