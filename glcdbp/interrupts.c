/***************************************************************************
interrupts.c

Interrupt definition file for the serial graphical LCD backpack project. The
 only actual interrupt handler is the serial receive handler. It lives here.

02 May 2013 - Mike Hord, SparkFun Electronics

This code is released under the Creative Commons Attribution Share-Alike 3.0
 license. You are free to reuse, remix, or redistribute it as you see fit,
 so long as you provide attribution to SparkFun Electronics.

***************************************************************************/

#include <AVR/interrupt.h>
#include "glcdbp.h"
#include "serial.h"

extern volatile uint8_t 	rxRingBuffer[BUF_DEPTH];
extern volatile uint8_t 	rxRingHead;
extern volatile uint8_t		rxRingTail;
extern volatile uint8_t		bufferSize;  // must be 16 rather than 8

// Handler for USART receive interrupts. This is basically just a stack push
//  for the FIFO we use to store incoming commands. Note that there is no
//  overflow; that might be a nice touch but so far, I haven't even come close
//  to hitting the buffer depth. In fact, I've never exceeded a depth of more
//  than two or three bytes.
// 
// Implemented simple flow control, raise TX if we're running out of buffer
//
ISR(USART_RX_vect)
{
	while((UCSR0A & (1 << RXC0)) != 0){
		if(bufferSize > (BUF_DEPTH-128)){
			PORTD |= 0x02;		// tell sender to stop,STOP a little before we run out so there is time to put the brakes on
		}
		bufferSize++;
		rxRingBuffer[rxRingHead++] = UDR0;
		if (rxRingHead == BUF_DEPTH) rxRingHead = 0;  // if it wrapped when we incremented point loop back  rxRingHead always shows where to store NEXT incoming byte
	}	
}
