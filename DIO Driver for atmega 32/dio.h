/*
 * dio.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Mohamed AbdelAzeem
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "Common_Macros.h"

typedef unsigned char uint8_t;
typedef unsigned long int uint32_t;

/***************************** Public Macros *******************************/

/* PORT definition */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/* PINS definitions */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/* OUTPUT states */
#define DIO_HIGH 1
#define DIO_LOW 0

/* Direction states */
#define DIO_INPUT 0
#define DIO_OUTPUT 1





//from data sheet Register summary page 299
#define PORTA_REG *((volatile uint8_t*) 0x3B)
#define DDRA_REG *((volatile uint8_t*) 0x3A)
#define PINA_REG *((volatile uint8_t*) 0x39)

//copy and paste and ctrl+f to find A and replace it with B
#define PORTB_REG *((volatile uint8_t*) 0x38)
#define DDRB_REG *((volatile uint8_t*) 0x37)
#define PINB_REG *((volatile uint8_t*) 0x36)

#define PORTC_REG *((volatile uint8_t*) 0x35)
#define DDRC_REG *((volatile uint8_t*) 0x34)
#define PINC_REG *((volatile uint8_t*) 0x33)

#define PORTD_REG *((volatile uint8_t*) 0x32)
#define DDRD_REG *((volatile uint8_t*) 0x31)
#define PIND_REG *((volatile uint8_t*) 0x30)



/*****************************************************************************************/
/***************************** Public functions Prototypes *******************************/
/*****************************************************************************************/

/*******************************************************************/
/* Description: this function is to set pin value to one or zero
 * Input      : PortId, Range: 0 ~ 3 	[DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD]
 * 				PinId , Range: 0 ~ 7 	[DIO_PIN0 ~ DIO_PIN7]
 * 				PinVal, Range: [DIO_LOW, DIO_HIGH]
 * Return     : Void
 *
 *  naming rules: indicates the return type and functioning
 *******************************************************************/
void DIO_SetPinVal(uint8_t PortId, uint8_t PinId, uint8_t PinVal);

/*******************************************************************/
/* Description: this function is to set port value
 * Input      : PortId, Range: 0 ~ 3 [DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD]
 * 				PinId , Range: 0 ~ 7 [DIO_PIN0 ~ DIO_PIN7]
 * 				PinDir, Range: [DIO_INPUT, DIO_OUTPUT]
 * Return     : Void
 *******************************************************************/
void DIO_SetPinDir(uint8_t PortId, uint8_t PinId, uint8_t PinDir);

/*******************************************************************/
/* Description: this function is to Get the pin value
 * Input      : PortId, Range: 0 ~ 3 [DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD]
 * 				PinId , Range: 0 ~ 7 [DIO_PIN0 ~ DIO_PIN7]
 * Return     : Void
 *******************************************************************/
uint8_t DIO_GetPinVal(uint8_t PortId, uint8_t PinId);

/*******************************************************************/
/* Description: this function is to set port value
 * Input      : PortId,  Range: 0 ~ 3 [DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD]
 * 				PortVal, Range: 0~255 [0x00 ~ 0xff]
 * Return     : Void
 *******************************************************************/
void DIO_SetPortVal(uint8_t PortId, uint8_t PortVal);

/*******************************************************************/
/* Description: this function is to set port direction
 * Input      : PortId,	Range: 0 ~ 3 [DIO_PORTA, DIO_PORTB, DIO_PORTC, DIO_PORTD]
 * 				PortDir,Range: [DIO_INPUT, DIO_OUTPUT]
 * Return     : Void
 *******************************************************************/
void DIO_SetPortDir(uint8_t PortId, uint8_t PortDir);



#endif /* DIO_H_ */
