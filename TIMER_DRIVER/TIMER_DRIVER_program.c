/*
 * TIMER_DRIVER_program.c
 *
 *  Created on: Nov 13, 2022
 *      Author: moham
 */
#include "STD_TYPES.h"
#include "TIMER_DRIVER_private.h"
#include "TIMER_DRIVER_interface.h"

static void (*Fun_Pointer)(void)=NULL_POINTER;

void T0_VInit(void){

	/*******SWITCH BETWEEN DIFFERENT GENERATIONS_MODE*********/
	switch(GENERATION_MODE){

	/****IN CASE OF NORMAL****/
	case NORMAL:

		//PUT A PRELOAD VALUE TO THE TIMER
		TCNT0_REG=PRELOAD_VALUE;

		//SELECT NORMAL MODE
		TCCR0_REG=T0_NORMAL_MODE_MASK;

		//ENABLE OVERFLOW INTERRUPT
		TIMSK_REG=T0_OVERFLOW_ENABLE_MASK;

		//SET PRESCALLER WITH CLK/8
		TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

		//break from the switch
		break;

	/****IN CASE OF PWM****/
	case PWM:

		//SELECT PWM MODE
		TCCR0_REG=T0_PWM_MODE_MASK;

		switch(FPWM_PWM_GENERATION_MODE){

			case CTC:

				//ENABLE COMPAREMATCH INTERRUPT
				TIMSK_REG=T0_COMPMATCH_ENABLE_MASK;

				//SWITCH BETWEEN THE OUTPUT STATE TO OC0
				switch(OC0_PIN_OUTPUT_STATE){

					//CASE OF OUTPUT DISSCONNECT STATE
					case DISSCONNECT:

						//SET OC0 TO DISSCONNECT STATE
						TCCR0_REG=T0_OC0_DISCONNECT_MASK;

						//BREAK FROM THE SWITCH
						break;

					//CASE OF OUTPUT CLEAR STATE
	     			case CLEAR:

						//SET OC0 TO CLEAR STATE
						TCCR0_REG=T0_OC0_CLEAR_MASK;

						//BREAK FROM THE SWITCH
						break;

					//CASE OF OUTPUT SET STATE
	    			case SET:

	    				//SET OC0 TO SET STATE
	    				TCCR0_REG=T0_OC0_SET_MASK;

	    				//BREAK FROM THE SWITCH
	    				break;

					//default break
	     			default:break;
					}

				//SET THE COMPARE MATCH VALUE
				OCR0_REG=COMPMATCH_VAL;

				//SET PRESCALLER WITH CLK/8
				TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

				//break this CTC case
				break;

			case NORMAL:
				//PUT A PRELOAD VALUE TO THE TIMER
				TCNT0_REG=PRELOAD_VALUE;

				//ENABLE OVERFLOW INTERRUPT
				TIMSK_REG=T0_OVERFLOW_ENABLE_MASK;

				//SET PRESCALLER WITH CLK/8
				TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

				//break from the switch
				break;

			//break from the switch
			default:break;
		}

		//ENABLE OVERFLOW INTERRUPT
		TIMSK_REG=T0_OVERFLOW_ENABLE_MASK;

		//SET PRESCALLER WITH CLK/8
		TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

		//break from the switch
		break;


	/****IN CASE OF CTC****/
	case CTC:

		//SELECT CTC MODE
		TCCR0_REG=T0_CTC_MODE_MASK;

		//ENABLE COMPAREMATCH INTERRUPT
		TIMSK_REG=T0_COMPMATCH_ENABLE_MASK;

		//SWITCH BETWEEN THE OUTPUT STATE TO OC0
		switch(OC0_PIN_OUTPUT_STATE){

			//CASE OF OUTPUT DISSCONNECT STATE
			case DISSCONNECT:

				//SET OC0 TO DISSCONNECT STATE
				TCCR0_REG=T0_OC0_DISCONNECT_MASK;

				//BREAK FROM THE SWITCH
				break;

			//CASE OF OUTPUT TOGGLE STATE
			case TOGGLE:

				//SET OC0 TO TOGGLE STATE
				TCCR0_REG=T0_OC0_TOGGLE_MASK;

				//BREAK FROM THE SWITCH
				break;

			//CASE OF OUTPUT CLEAR STATE
			case CLEAR:

				//SET OC0 TO CLEAR STATE
				TCCR0_REG=T0_OC0_CLEAR_MASK;

				//BREAK FROM THE SWITCH
				break;

			//CASE OF OUTPUT SET STATE
			case SET:

				//SET OC0 TO SET STATE
				TCCR0_REG=T0_OC0_SET_MASK;

				//BREAK FROM THE SWITCH
				break;
			//DEFAULT_THEN BREAK
			default:break;

		}


		//SET THE COMPARE MATCH VALUE
		OCR0_REG=COMPMATCH_VAL;

		//SET PRESCALLER WITH CLK/8
		TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

		//break from the switch
		break;


	/****IN CASE OF FAST_PWM****/
	case FAST_PWM:

		//SELECT FAST PWM MODE
		TCCR0_REG=T0_FASTPWM_MODE_MASK;

		switch(FPWM_PWM_GENERATION_MODE){

			case CTC:

				//ENABLE COMPAREMATCH INTERRUPT
				TIMSK_REG=T0_COMPMATCH_ENABLE_MASK;

				//SWITCH BETWEEN THE OUTPUT STATE TO OC0
				switch(OC0_PIN_OUTPUT_STATE){

					//CASE OF OUTPUT DISSCONNECT STATE
					case DISSCONNECT:

						//SET OC0 TO DISSCONNECT STATE
						TCCR0_REG=T0_OC0_DISCONNECT_MASK;

						//BREAK FROM THE SWITCH
						break;

					//CASE OF OUTPUT CLEAR STATE
	     			case CLEAR:

						//SET OC0 TO CLEAR STATE
						TCCR0_REG=T0_OC0_CLEAR_MASK;

						//BREAK FROM THE SWITCH
						break;

					//CASE OF OUTPUT SET STATE
	    			case SET:

	    				//SET OC0 TO SET STATE
	    				TCCR0_REG=T0_OC0_SET_MASK;

	    				//BREAK FROM THE SWITCH
	    				break;

					//default break
	     			default:break;}

				//SET THE COMPARE MATCH VALUE
				OCR0_REG=COMPMATCH_VAL;

				//SET PRESCALLER WITH CLK/8
				TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

				//break this CTC case
				break;

			case NORMAL:
				//PUT A PRELOAD VALUE TO THE TIMER
				TCNT0_REG=PRELOAD_VALUE;

				//ENABLE OVERFLOW INTERRUPT
				TIMSK_REG=T0_OVERFLOW_ENABLE_MASK;

				//SET PRESCALLER WITH CLK/8
				TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

				//break from the switch
				break;

			//break from the switch
			default:break;
		}

		//ENABLE OVERFLOW INTERRUPT
		TIMSK_REG=T0_OVERFLOW_ENABLE_MASK;

		//SET PRESCALLER WITH CLK/8
		TCCR0_REG=T0_SYSCLOCK_PRESCALL8_SOURCE_MASK;

		//break from the switch
		break;



	//DEFAULT_THEN BREAK;
	default:break;


	}

}



u8 T0_U8SetCallBack(void (*FunHolder)(void)){

	//INTIALIZE VARIABLE TO DEFINE THE STATE OF THE FUNCTION
	u8 LOCAL_U8FunState=OK;

	//CHEACK IF THE FunHolder HAS AN ADDRESS OR NULL
	if(FunHolder==NULL_POINTER){

		//SET NULL_POINTER VAL IN LOCAL_U8FunState
		LOCAL_U8FunState=NULL_POINTER;

		//RETURN THE VALUE OF LOCAL_U8FunState
		return LOCAL_U8FunState;

		}

	//IF NOT EQUL TO NULL
	else{

		//SET THE GLOBAL POINTER TO FUNCTION TO THE ADDRESS OF THE USER FUNCTION
		Fun_Pointer=FunHolder;

		}
	//RETURN LOCAL_U8FunState VALUE
	return LOCAL_U8FunState;

}


/**********ISR FOR TIMER 0 COMPARE MATCH**************/
void __vector_10(void) __attribute__((signal));
void __vector_10 (void){

	Fun_Pointer();


}


/**********ISR FOR TIMER 0 OVERFLOW MATCH**************/
void __vector_11(void) __attribute__((signal));
void __vector_11 (void){

	Fun_Pointer();


}
