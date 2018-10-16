/***************************************************************************
io_support.c

IO support function file for the serial graphical LCD backpack project. This
 file provides an init function for the IO pins, as well as a set/get data
 function which abstracts away the dance you have to do to integrate data
 from two different ports into one byte.

02 May 2013 - Mike Hord, SparkFun Electronics

This code is released under the Creative Commons Attribution Share-Alike 3.0
 license. You are free to reuse, remix, or redistribute it as you see fit,
 so long as you provide attribution to SparkFun Electronics.

***************************************************************************/

#include <avr/io.h>
#include <util/delay.h>    // F_CPU is defined in the makefile
#include "glcdbp.h"
#include "io_support.h"

// This is setup in glcdbp.c and is used to track the "type" of the display
//  throughout the code.
extern enum DISPLAY_TYPE display;

void ioInit(void)
{
  // Set up the data direction registers for the data bus pins.
  //  The data bus is on PB0:1 and PD2:7, so make those pins outputs.
  // make D1 (TX) and output so we can flag buffer full
  DDRB = 0b00111111;	// set PB4/PB5 as debug outputs
  PORTB = 0;			// Pullups off, and outputs to 0
  DDRD = 0b11111110;	// bit 2 is tx
  PORTD = 0;			// Pullups off and outputs to 0
  MCUCR |= 0b00010000;  // disable all pullups
  
  #ifdef DEBUG_IO
	PORTB |= 0x10;		// toggle both debug io lines
	_delay_us(5);
	PORTB &= ~0x10;		// right at the beginning so we know they work
	PORTB |= 0x20;		// and so we can use them as triggers if necessary
	_delay_us(5);
	PORTB &= ~0x20;
  #endif

 

  PORTB &= ~(1<<nBL_EN);  // Turn backlight on
  
  // Now we need to configure the I/O to support the two types of display.
  if (display == SMALL)
  {
    DDRC =  ((1<<EN) | (1<<RS) | (1<<R_W) | (1<<RESET) | (1<<CS1) | (1<<CS2));
    PORTC = ((1<<EN) | (1<<RS) | (1<<R_W) | (1<<RESET) | (1<<CS1) | (1<<CS2));
  }
  else if (display == LARGE)
  {
    DDRC =  ((1<<WR) | (1<<RD) | (1<<CE) | (1<<CD) | (1<<HALT) | (1<<RST));
    PORTC = ((1<<WR) | (1<<RD) | (1<<CE) | (1<<CD) | (1<<HALT) | (1<<RST));
  }
}

// Abstracts away the fact that the data pins are not on one port. We *could*
//  inline this code wherever necessary, but who wants to read all this?
void setData(uint8_t data)
{
  // Set the port direction registers to make data pins outputs.
  DDRB |= 0x03;
  DDRD |= 0xFC;
  
  PORTB = (PORTB & ~(0x03)) | (data & 0x03);
                          //  and then write the other two bits.
                          //  The data is now in place.
  PORTD = (PORTD & ~(0xFC)) | (data & 0xFC);
}

// Same deal as setData.
uint8_t readData(void)
{
  // Set the port direction to input.
  DDRB &= ~(0x03);
  DDRD &= ~(0xFC);
  
  return (PINB & 0x03) | (PIND & 0xFC);
}

// I've noticed that the ks0108b displays don't always play well with their
//  data pins, and to avoid contention and the assorted ugly crap, I've
//  added this function to put the data pins in a hi-z state. I suppose I
//  could just call readData(), but this is easier to read.
void hiZDataPins(void)
{
  // Set the port direction to input.
  DDRB  &= ~(0x03);			// argh!!! the PORTB/D values will determine what has Pull-Up's or not  make sure all pullups are disabled!
  DDRD  &= ~(0xFC);			// and those CHANGE as we write data to the LCD!!!
}
