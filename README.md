# GraphicLCD_Serial_Backpack
Modification  of SparkFun GraphicLCD_Serial_Backpack
10/4/2018

Multiple modifications and bug-fixes from the original SparkFun Firmware

1) Serial buffer overflow handing

    With a fast enough processor (Particle Photon in my case) it was possible to 
	overrun the serial buffer.  Firmware now uses the TX pin as a overflow flag.  TX pin
	is set HIGH when the serial buffer gets 1/2 full.  Once the buffer is empty
	the TX pin goes LOW.
	
2) Serial Buffer modification

    Variable bufferSize was uint8_t and BUF_DEPTH was 256, so at 'full' buffer 
	bufferSize would be 256 which doesn't fit in 8 bits.  Changed BUF_DEPTH to 255 to
	facilitate uint8_t size pointers for ALL serial buffer access.  This fixes the full
	buffer problem AND speeds up buffer access as it's 8 bit math rather than 16 bit
	
3) Bugfix writedata across chip boundary

    on the Small display, when writedata crossed the 64 byte boundary into the 2nd chip
	the in-chip X (column) doesn't auto-reset to 0 and instead picks up wherever the
	2nd chip X last was.  Added code in writedate to force chip 2's X to 0 when X crosses
	63->64 byte boundary

4) Fast Text write

    Small Display only (someone else write the large display).  Modified the draw text
	algorithm to optimize when drawing text on a full row boundaries (ie Y = 0,8,16, etc)
	Much, much faster as full row only does write rather than read/modify/write
	
5) Fast area fill

    Small Display only.  Modified the area fill algorithm to optimize for filling full
	rows a byte at a time when possible.
	
6) Implement Serial Test function code 0x01

    Byte following the 0x01 is the 'target byte'.  Host should send continuous stream
	of 'target bytes' after that.  If the received byte does not match the target byte
	then an X is written to the LCD.  Over an extended test time, the number of X's 
	displayed indicates the number of transmission errors.
	
7) Implemented debug bits
	
	if DEBUG_IO is defined in glcdbp.h then use PB4/5 as information bits.  Look at 
	ks0108b.c WaitReady routine as example.  Turn PB5 HIGH when entering the routine
	and LOW when exiting the routine.  This is only as example, use to delineate routines
	when you do your own firmware development
	
8) Implemented Trigger function code 0x08

    use in conjunction with PB4/5 debug information bits above.  Function 0x08 causes PB5
	to toggle HIGH/LOW for use in signal capture when troubleshooting firmware routes.
    
