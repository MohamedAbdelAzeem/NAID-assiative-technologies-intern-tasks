﻿/*
 * DIO.c
 *
 * Created: 30/06/2021 
 *  Author: Mohamed AbdelAzeem
 */ 
#include "DIO_Config.h"
#include "common_macros.h"

void DIO_SetPinDirection (uint8_t PortNumber , uint8_t PinNumber , uint8_t Direction) {
	switch (PortNumber) {
		case portA :
			if (Direction == OUTPUT) {
				SET_BIT(DDRA_REG,PinNumber) ; 
			}
			else if (Direction == INPUT) {
				CLEAR_BIT(DDRA_REG,PinNumber) ; 
			}
		break;
			
		case portB :
			if (Direction == OUTPUT) {
				SET_BIT(DDRB_REG,PinNumber) ;
			}
			else if (Direction == INPUT) {
				CLEAR_BIT(DDRB_REG,PinNumber) ;
			}
		break;
		
		case portC :
			if (Direction == OUTPUT) {
				SET_BIT(DDRC_REG,PinNumber) ;
			}
			else if (Direction == INPUT) {
				CLEAR_BIT(DDRC_REG,PinNumber) ;
			}
			break;	
			
		case portD :
			if (Direction == OUTPUT) {
				SET_BIT(DDRD_REG,PinNumber) ;
			}
			else if (Direction == INPUT) {
				CLEAR_BIT(DDRD_REG,PinNumber) ;
			}
		break;	
	}
}

void DIO_SetPinValue (uint8_t PortNumber , uint8_t PinNumber , uint8_t Value) {
	switch (PortNumber) {
		case portA :
			if (Value == 1) {
				SET_BIT(PORTA_REG,PinNumber) ;
			}
			else if (Value == 0) {
				CLEAR_BIT(PORTA_REG,PinNumber) ;
			}
		break;
		
		case portB :
			if (Value == 1) {
				SET_BIT(PORTB_REG,PinNumber) ;
			}
			else if (Value == 0) {
				CLEAR_BIT(PORTB_REG,PinNumber) ;
			}
		break;
		
		case portC :
			if (Value == 1) {
				SET_BIT(PORTC_REG,PinNumber) ;
			}
			else if (Value == 0) {
				CLEAR_BIT(PORTC_REG,PinNumber) ;
			}
		break;
		
		case portD :
			if (Value == 1) {
				SET_BIT(PORTD_REG,PinNumber) ;
			}
			else if (Value == 0) {
				CLEAR_BIT(PORTD_REG,PinNumber) ;
			}
		break;
	}	
}
void DIO_TogglePinValue (uint8_t PortNumber , uint8_t PinNumber) {
	switch (PortNumber) {
		case portA :
			TOGGLE_BIT(PORTA_REG , PinNumber) ; 
			break ;
			
		case portB :
			TOGGLE_BIT(PORTB_REG , PinNumber) ;
			break ;
			
		case portC :
			TOGGLE_BIT(PORTC_REG , PinNumber) ;
			break ;
			
		case portD :
			TOGGLE_BIT(PORTD_REG , PinNumber) ;
			break ;
	}
}

void DIO_SetPortDirection (uint8_t PortNumber , uint8_t Direction) {
	switch(PortNumber) {
		case portA : 
			if (Direction == OUTPUT) {
				DDRA_REG = 0xff ; 
			}
			else if (Direction == INPUT) {
				DDRA_REG = 0x00 ; 
			}
		break;
		
		case portB :
			if (Direction == OUTPUT) {
				DDRB_REG = 0xff ;
			}
			else if (Direction == INPUT) {
				DDRB_REG = 0x00 ;
			}
		break;
		
		case portC :
			if (Direction == OUTPUT) {
				DDRC_REG = 0xff ;
			}
			else if (Direction == INPUT) {
				DDRC_REG = 0x00 ;
			}	
		break;
		
		case portD :
			if (Direction == OUTPUT) {
				DDRD_REG = 0xff ;
			}
			else if (Direction == INPUT) {
				DDRD_REG = 0x00 ;
			}
			break;
	}
}

void DIO_SetPortValue (uint8_t PortNumber , uint8_t Value) {
	switch(PortNumber) {
		case portA :
			PORTA_REG = Value ; 
		break;
		
		case portB :
			PORTB_REG = Value ; 
		break;
		
		case portC :
			PORTC_REG = Value ; 
		break;
		
		case portD :
			PORTD_REG = Value ; 
		break;
	}	
}


void DIO_SetUpperHalfPortValue (uint8_t PortNumber , uint8_t Value) {
	switch(PortNumber) {
		case portA :
		PORTA_REG = (PORTA_REG & 0x0F) |  Value ;
		break;
		
		case portB :
		PORTB_REG = (PORTB_REG & 0x0F) |  Value ;
		break;
		
		case portC :
		PORTC_REG = (PORTC_REG & 0x0F) |  Value ;
		break;
		
		case portD :
		PORTD_REG = (PORTD_REG & 0x0F) | Value  ;
		break;
	}
}


void DIO_SetLowerHalfPortValue (uint8_t PortNumber , uint8_t Value) {
	switch(PortNumber) {
		case portA :
		PORTA_REG = (PORTA_REG & 0xF0) |  Value  ;
		break;
		
		case portB :
		PORTB_REG = (PORTB_REG & 0xF0) |  Value ;
		break;
		
		case portC :
		PORTC_REG = (PORTC_REG & 0xF0) | Value ;
		break;
		
		case portD :
		PORTD_REG = (PORTD_REG & 0xF0) |  Value  ;
		break;
	}
}


uint8_t DIO_GetPinValue (uint8_t PortNumber , uint8_t PinNumber) {
	uint8_t value = 0 ; 
	switch (PortNumber) {
		case portA : 
			value = (PINA_REG >> PinNumber) & 0x01 ; 	
		break;
		
		case portB :
			value = (PINB_REG >> PinNumber) & 0x01 ;
		break;
		
		case portC :
			value = (PINC_REG >> PinNumber) & 0x01 ;
		break;

		case portD :
			value = (PIND_REG >> PinNumber) & 0x01 ;
		break;
	}
	return value ; 
}
uint8_t DIO_GetPortValue (uint8_t PortNumber) {
	uint8_t value = 0 ;
	switch (PortNumber) {
		case portA :
			value = PINA_REG ;
		break;
		
		case portB :
			value = PINB_REG ;
		break;
		
		case portC :
			value = PINC_REG ;
		break;

		case portD :
			value = PIND_REG ;
		break;
	}
	return value ;
}