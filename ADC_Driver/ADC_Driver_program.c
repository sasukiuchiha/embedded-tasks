/*
 * ADC_Driver_program.c
 *
 *  Created on: Nov 4, 2022
 *      Author: moham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "ADC_Driver_private.h"
#include "ADC_Driver_config.h"
#include "ADC_Driver_interface.h"



/***************************CHANNING_SECTION*******************************************************/
/*size of the arr of struct to hold the addreesses of the user funs and variables to hold the reading*/
#define ARR_SIZE  255

/*struct to hold the addreesses of the user funs and variables to hold the reading*/
struct store_ADC_ASY{

	void (*Add_Of_Fun)(void);
	u16  *Read_ADC_val;
};

/*arr of structs to hold the data*/
struct store_ADC_ASY arr[ARR_SIZE]={0};

/*local var to hold the current location in the arr of struct*/
u8 current_location=0;

/*local to hold the last location that ii reached due to the calling of the ADCASY FUN*/
u8 last_location=0;

/******************************************************************************************/
//*****************************************************************************************

/******STATIC GLOBAL TO RETURN THE val of reading of adc in ISR*/
static u16 *ADC_Val_Holder=NULL;

/*global to hold the addresses of the user function to run it in ISR*/
static void (*Add_FunHolder)(void)=NULL;

void ADC_Vinit(void){
	
	//save the selected vref in the ADMUX_REG
	ADMUX_REG=VOLT_REF_SELECTOR; 
	//select the right adjustment
	ADMUX_REG=ADJ_SELECTOR;
	//set a pre scalling to the c\k
	ADCSRA_REG=PRE_SCALLING_SELECTOR; 
	//enable the adc
	ADCSRA_REG=ADC_STATE;

}

u8 ADC_u8GeTADCSync(u16 *ADC_val){
	

	//counter to terminate the function in case there is any error
	u32 Local_U23counter=0;

	//variable to represent the state of the function/
	u8 Local_U8state=OK;
	//set the channel number to the value from it
	ADMUX_REG=CHANNEL_NUM;  
	
	/*select the required channel*/
	switch(ADC_CHANNEL){

		/*set the direction to the required channel to output through cases*/
		case CHANNEL_0:
			DIO_vSetPin_Dir(PORTA,BIT0,INPUT);
			break;
		case CHANNEL_1:
			DIO_vSetPin_Dir(PORTA,BIT1,INPUT);
			break;
		case CHANNEL_2:
			DIO_vSetPin_Dir(PORTA,BIT2,INPUT);
			break;
		case CHANNEL_3:
			DIO_vSetPin_Dir(PORTA,BIT3,INPUT);
			break;
		case CHANNEL_4:
			DIO_vSetPin_Dir(PORTA,BIT4,INPUT);
			break;
		case CHANNEL_5:
			DIO_vSetPin_Dir(PORTA,BIT5,INPUT);
			break;
		case CHANNEL_6:
			DIO_vSetPin_Dir(PORTA,BIT6,INPUT);
			break;
		case CHANNEL_7:
			DIO_vSetPin_Dir(PORTA,BIT7,INPUT);
			break;

		default:
			break;
		}

	//start convertion
	ADCSRA_REG=ADC_SRCONV_MASK;

	//polling until getting the value
	while((GET_BIT(ADCSRA_REG,ADCSRA_ADIF)==0)&& (Local_U23counter<=5000)){
		
		Local_U23counter++;
		
		}
	
	//check if the adc didnot finish the conversion
	if (GET_BIT(ADCSRA_REG,ADCSRA_ADIF)==0){
		Local_U8state=NOTOK;
		return Local_U8state;
		
		}
	else{
		
		//CLEAR ADC_INTERRUPT FLAG BY SET HIS BIT WITH 1
		ADCSRA_REG=ADC_PIF_MASK;
			
			
		*ADC_val=ADCL_ADCH_REG;
		return Local_U8state;
		}
	
	

}



u8 ADC_u8GeTADCASync(void *add_OfUserFun_ToISR(void),u16 *ADC_Read_Val){
	
	//variable to represent the state of the function/
	u8 Local_U8ErrorState=0;

	if(add_OfUserFun_ToISR==NULL){

		//put a null in error state
		Local_U8ErrorState=NULL_POINTER;
		return Local_U8ErrorState;

	}

	else{




		if(ADC_state==IDEAL){


			//intialize the global pointer
			ADC_Val_Holder=ADC_Read_Val;;

			//put the user fun address in the global pointer to fun
			Add_FunHolder=(void *)add_OfUserFun_ToISR;

			//put the ADC in running mode to represent that it's in the conversion phase
			ADC_state=RUNNING;

			//set the channel number to the value from it
			ADMUX_REG=CHANNEL_NUM;
			/*select the required channel*/
			switch(ADC_CHANNEL){

					/*set the direction to the required channel to output through cases*/
					case CHANNEL_0:
						DIO_vSetPin_Dir(PORTA,BIT0,INPUT);
						break;
					case CHANNEL_1:
						DIO_vSetPin_Dir(PORTA,BIT1,INPUT);
						break;
					case CHANNEL_2:
						DIO_vSetPin_Dir(PORTA,BIT2,INPUT);
						break;
					case CHANNEL_3:
						DIO_vSetPin_Dir(PORTA,BIT3,INPUT);
						break;
					case CHANNEL_4:
						DIO_vSetPin_Dir(PORTA,BIT4,INPUT);
						break;
					case CHANNEL_5:
						DIO_vSetPin_Dir(PORTA,BIT5,INPUT);
						break;
					case CHANNEL_6:
						DIO_vSetPin_Dir(PORTA,BIT6,INPUT);
						break;
					case CHANNEL_7:
						DIO_vSetPin_Dir(PORTA,BIT7,INPUT);
						break;

					default:
						break;
					}
			//start convertion
			ADCSRA_REG=ADC_SRCONV_MASK;

			//INTERRUPT ENABLE
			ADCSRA_REG=ADC_STATE;

			//select the triger source
			ADCSRA_REG=TRIGR_SOURCE_SELECTOR;

			//to detect that i entered the IDEAL state return ok
			return OK;
			}
		else{
			/*CASE THAT I ENTERED THE FUN WHIILE ADC IS RUNNING
			 * STORE THE DATA IN THE ARR OF STARUCT*/
			arr[last_location].Add_Of_Fun=(void *)add_OfUserFun_ToISR;
			arr[last_location].Read_ADC_val=ADC_Read_Val;

			/*increase last_location by one to represent the next location to save the
			 * data in*/
			last_location++;

			//PUT RUNNING VAL IN Local_U8ErrorState
			Local_U8ErrorState=RUNNING;
			//return the val of Local_U8ErrorState
			return Local_U8ErrorState;


			}

		}



}



// ADC ISR (Conversion Complete)
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
	
	//SET THE ADC_STATE to ideal
	ADC_state=IDEAL;
	
	//return the value of conversion to the user
	*ADC_Val_Holder=ADCL_ADCH_REG;
	
	//call the user  fun in the ISR
	Add_FunHolder();
	
	/**test if there is any data added in the arr of struct*/
	if(current_location<=(last_location-1)){

		/*call the function by the current_location variable*/
		ADC_u8GeTADCASync((void *)(arr[current_location].Add_Of_Fun),arr[current_location].Read_ADC_val);

		/**delet the current_location in the arr**/
		arr[current_location].Add_Of_Fun=0;
		arr[current_location].Read_ADC_val=0;


		/*check if i reached the last location in the arr*/
		if(current_location==(last_location-1)){

			/**reset the current_location to zero*/
			current_location=0;

			/**reset the last_location to zero*/
			last_location=0;

			}

		else{

			/**add 1 to the current_location to access the next location in the arr*/
			current_location++;
			}

	}
	
}

