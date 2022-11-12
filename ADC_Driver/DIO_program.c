#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"


void DIO_vSetPort_Dir(u8 port_id,u8 port_dir){

	switch(port_id){
		case PORTA:
			DDRA_REG=port_dir;
			break;
		case PORTB:
			DDRB_REG=port_dir;
			break;

		case PORTC:
			DDRC_REG=port_dir;
			break;

		case PORTD:
			DDRD_REG=port_dir;
			break;
		default:
			break;
	}

}


void DIO_vSetPort_Val(u8 port_id,u8 port_val){

	switch(port_id){
		case PORTA:
			PORTA_REG=port_val;
			break;
		case PORTB:
			PORTB_REG=port_val;
			break;

		case PORTC:
			PORTC_REG=port_val;
			break;

		case PORTD:
			PORTD_REG=port_val;
			break;
		default:
			break;
	}
}

u8 DIO_u8GetPORT_Val(u8 port_id){

	u8 val=0;
	switch(port_id){
			case PORTA:
				val=PORTA_REG;
				break;
			case PORTB:
				val=PORTB_REG;
				break;

			case PORTC:
				val=PORTC_REG;
				break;

			case PORTD:
				val=PORTD_REG;
				break;
			default:
				break;
		}

	return val;


}


void DIO_vSetPin_Dir(u8 port_id,u8 pin_id,u8 pin_dir){

	switch(port_id){
		case PORTA:
			if(pin_dir==OUTPUT){
				SET_BIT(DDRA_REG,pin_id);
			}
			else if(pin_dir==INPUT){
				CLR_BIT(DDRA_REG,pin_id);

			}
			else{}
			break;
		case PORTB:
			if(pin_dir==OUTPUT){
				SET_BIT(DDRB_REG,pin_id);
				}
			else if(pin_dir==INPUT){
				CLR_BIT(DDRB_REG,pin_id);

				}
			else{}
			break;

		case PORTC:
			if(pin_dir==OUTPUT){
				SET_BIT(DDRC_REG,pin_id);
				}
			else if(pin_dir==INPUT){
				CLR_BIT(DDRC_REG,pin_id);

				}
			else{}
			break;
		case PORTD:
			if(pin_dir==OUTPUT){
				SET_BIT(DDRD_REG,pin_id);
				}
			else if(pin_dir==INPUT){
				CLR_BIT(DDRD_REG,pin_id);

				}
			else{}
			break;
		default:break;
	}

}
void DIO_vSetPin_Val(u8 port_id,u8 pin_id,u8 pin_val){
	switch(port_id){
		case PORTA:
			if(pin_val==HIGH){
				SET_BIT(PORTA_REG,pin_id);
			}
			else if(pin_val==LOW){
				CLR_BIT(PORTA_REG,pin_id);

			}
			else{}
			break;
		case PORTB:
			if(pin_val==HIGH){
				SET_BIT(PORTB_REG,pin_id);
				}
			else if(pin_val==LOW){
				CLR_BIT(PORTB_REG,pin_id);

				}
			else{}
			break;

		case PORTC:
			if(pin_val==HIGH){
				SET_BIT(PORTC_REG,pin_id);
				}
			else if(pin_val==LOW){
				CLR_BIT(PORTC_REG,pin_id);

				}
			else{}
			break;
		case PORTD:
			if(pin_val==HIGH){
				SET_BIT(PORTD_REG,pin_id);
				}
			else if(pin_val==LOW){
				CLR_BIT(PORTD_REG,pin_id);

				}
			else{}
			break;
		default:break;
	}


}
u8 DIO_u8GetPins_Val(u8 port_id,u8 pin_id){

	u8 val=0;
	switch(port_id){
		case PORTA:
			val=GET_BIT(PINA_REG,pin_id);
			break;
		case PORTB:
			val=GET_BIT(PINB_REG,pin_id);
			break;

		case PORTC:
			val=GET_BIT(PINC_REG,pin_id);
			break;
		case PORTD:
			val=GET_BIT(PIND_REG,pin_id);
			break;
		default:
		   break;
	}
	return val;

}


void DIO_vTogglePin_Val(u8 port_id,u8 pin_id,u8 pin_val){
	switch(port_id){
		case PORTA:
			TOGGLE_BIT(PORTA_REG,pin_id);
			break;
		case PORTB:
			TOGGLE_BIT(PORTB_REG,pin_id);
			break;

		case PORTC:
			TOGGLE_BIT(PORTC_REG,pin_id);
			break;
		case PORTD:
			TOGGLE_BIT(PORTD_REG,pin_id);
			break;
		default:
		   break;
	}


}
