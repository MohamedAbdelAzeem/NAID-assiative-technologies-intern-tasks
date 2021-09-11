/*
 * dio.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Mohamed AbdelAzeem
 */


#include "dio.h"

/*******************************************************************/
/*******************************************************************/
void DIO_SetPinVal(uint8_t PortId, uint8_t PinId, uint8_t PinVal){

	if( PortId <= DIO_PORTD && PinId <= DIO_PIN7 ){
		if( PinVal == DIO_HIGH )
		{
			switch(PortId)
			{
			case DIO_PORTA: SET_BIT(PORTA_REG, PinId); break;
			case DIO_PORTB: SET_BIT(PORTB_REG, PinId); break;
			case DIO_PORTC: SET_BIT(PORTC_REG, PinId); break;
			case DIO_PORTD: SET_BIT(PORTD_REG, PinId); break;
			}
		}else if( PinVal == DIO_LOW ){
			switch(PortId)
			{
			case DIO_PORTA: CLEAR_BIT(PORTA_REG, PinId); break;
			case DIO_PORTB: CLEAR_BIT(PORTB_REG, PinId); break;
			case DIO_PORTC: CLEAR_BIT(PORTC_REG, PinId); break;
			case DIO_PORTD: CLEAR_BIT(PORTD_REG, PinId); break;
			}
		}
	}else{
		//error report
	}

}

/*******************************************************************/
/*******************************************************************/
void DIO_SetPinDir(uint8_t PortId, uint8_t PinId, uint8_t PinDir){
	if( PortId <= DIO_PORTD && PinId <= DIO_PIN7 ){
		if( PinDir == DIO_OUTPUT )
		{
			switch(PortId)
			{
			case DIO_PORTA: SET_BIT(DDRA_REG, PinId); break;
			case DIO_PORTB: SET_BIT(DDRB_REG, PinId); break;
			case DIO_PORTC: SET_BIT(DDRC_REG, PinId); break;
			case DIO_PORTD: SET_BIT(DDRD_REG, PinId); break;
			}
		}else if( PinDir == DIO_INPUT ){


			switch(PortId)
			{
			case DIO_PORTA: CLEAR_BIT(DDRA_REG, PinId); break;
			case DIO_PORTB: CLEAR_BIT(DDRB_REG, PinId); break;
			case DIO_PORTC: CLEAR_BIT(DDRC_REG, PinId); break;
			case DIO_PORTD: CLEAR_BIT(DDRD_REG, PinId); break;
			}

		}
	}else{
		//error report
	}
}

/*******************************************************************/
/*******************************************************************/
uint8_t DIO_GetPinVal(uint8_t PortId, uint8_t PinId){
	uint8_t uint8_t_PinValue_Loc;


	if( PortId <= DIO_PORTD && PinId <= DIO_PIN7 ){

		switch(PortId)
		{
		case DIO_PORTA: uint8_t_PinValue_Loc = BIT_IS_SET(PINA_REG, PinId); break;
		case DIO_PORTB: uint8_t_PinValue_Loc = BIT_IS_SET(PINB_REG, PinId); break;
		case DIO_PORTC: uint8_t_PinValue_Loc = BIT_IS_SET(PINC_REG, PinId); break;
		case DIO_PORTD: uint8_t_PinValue_Loc = BIT_IS_SET(PIND_REG, PinId); break;
		}

	}else{

	}
	return uint8_t_PinValue_Loc;
}

/*******************************************************************/
/*******************************************************************/
void DIO_SetPortVal(uint8_t PortId, uint8_t PortVal){
	if( PortId <= DIO_PORTD ){

		switch(PortId)
		{
		case DIO_PORTA: PORTA_REG = PortVal; break;
		case DIO_PORTB: PORTB_REG = PortVal; break;
		case DIO_PORTC: PORTC_REG = PortVal; break;
		case DIO_PORTD: PORTD_REG = PortVal; break;
		}

	}else{

	}
}

/*******************************************************************/
/*******************************************************************/
void DIO_SetPortDir(uint8_t PortId, uint8_t PortDir){

	if( PortId <= DIO_PORTD ){
		if(PortDir == DIO_OUTPUT){
				switch(PortId)
				{
				case DIO_PORTA: DDRA_REG = 0xff; break;
				case DIO_PORTB: DDRB_REG = 0xff; break;
				case DIO_PORTC: DDRC_REG = 0xff; break;
				case DIO_PORTD: DDRD_REG = 0xff; break;
				}

				}else if(PortDir == DIO_INPUT){
					switch(PortId)
							{
							case DIO_PORTA: DDRA_REG = 0; break;
							case DIO_PORTB: DDRB_REG = 0; break;
							case DIO_PORTC: DDRC_REG = 0; break;
							case DIO_PORTD: DDRD_REG = 0; break;
							}
				}else{
					// invalid DIO port value
				}

	}else{

	}
}

