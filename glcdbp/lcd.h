/***************************************************************************
lcd.h

Function prototypes for the LCD code. Also includes character maps, the
 SparkFun logo, and masks and sprites for the sprite drawing funcitonality.

02 May 2013 - Mike Hord, SparkFun Electronics

This code is released under the Creative Commons Attribution Share-Alike 3.0
 license. You are free to reuse, remix, or redistribute it as you see fit,
 so long as you provide attribution to SparkFun Electronics.

***************************************************************************/

#ifndef __lcd_h
#define __lcd_h

// Yo dawg. Include files in include files is generally a frowned-upon
//  practice; in this case, I'm doing it because I need the definition of
//  the PIX_VAL typedef from glcdbp.h and the PROGMEM support provided in
//  pgmspace.h. Do as I say, not as I do.

#include <avr/pgmspace.h> 
#include "glcdbp.h"

void	lcdConfig(void);
void	lcdClearScreen(void);
void 	lcdDrawPixel(uint8_t x, uint8_t y, PIX_VAL pixel);
void 	lcdDrawLine(uint8_t p1x, uint8_t p1y, uint8_t p2x, uint8_t p2y, PIX_VAL pixel);
void 	lcdDrawCircle(uint8_t x0, uint8_t y0, uint8_t r, PIX_VAL pixel);
void	lcdDrawBox(uint8_t p1x, uint8_t p1y, uint8_t p2x, uint8_t p2y, PIX_VAL pixel);
void	lcdDrawChar(char printMe);
void    lcdDrawLogo(void);
void    lcdEraseBlock(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void    lcdGetDataBlock(uint8_t x, uint8_t y, uint8_t *buffer);
void    lcdDrawSprite(uint8_t x, uint8_t y, uint8_t sprite, char angle, PIX_VAL pixel);

// Sprite maps for characters. Lifted from the original glcd code, which in turn
//   lifted them from something called "Sinister 7". I don't know what that is.
//   What I *do* know is that the original codes were upside-down, and I had
//   to write a python script to reverse the bit order of these bitmaps.
static const char characterArray[475] PROGMEM = {
	0x00,0x00,0x00,0x00,0x00,/*space*/
	0x00,0x6f,0x6f,0x00,0x00,/*!*/
	0x00,0x07,0x00,0x07,0x00,/*"*/
	0x14,0x7f,0x14,0x7f,0x14,/*#*/
	0x00,0x26,0x6b,0x2a,0x10,/*$*/
	0x43,0x33,0x08,0x64,0x63,/*%*/
	0x32,0x4d,0x49,0x36,0x50,/*&*/
	0x00,0x00,0x07,0x00,0x00,/*'*/
	0x00,0x1c,0x22,0x41,0x00,/*(*/
	0x00,0x41,0x22,0x1c,0x00,/*)*/
	0x11,0x0a,0x1f,0x0a,0x11,/***/
	0x10,0x10,0x7c,0x10,0x10,/*+*/
	0x00,0x00,0xa0,0x60,0x00,/*,*/
	0x10,0x10,0x10,0x10,0x10,/*-*/
	0x00,0x00,0x60,0x60,0x00,/*.*/
	0x40,0x30,0x08,0x06,0x01,/*/*/
	0x3e,0x51,0x49,0x45,0x3e,/*0*/
	0x00,0x42,0x7f,0x40,0x00,/*1*/
	0x42,0x61,0x51,0x49,0x46,/*2*/
	0x22,0x41,0x49,0x49,0x36,/*3*/
	0x18,0x14,0x12,0x7f,0x10,/*4*/
	0x27,0x45,0x45,0x45,0x39,/*5*/
	0x3c,0x4a,0x49,0x49,0x30,/*6*/
	0x01,0x71,0x09,0x05,0x03,/*7*/
	0x36,0x49,0x49,0x49,0x36,/*8*/
	0x06,0x49,0x49,0x29,0x1e,/*9*/
	0x00,0x00,0x6c,0x6c,0x00,/*:*/
	0x00,0x00,0xac,0x6c,0x00,/*;*/
	0x08,0x14,0x22,0x41,0x00,/*<*/
	0x14,0x14,0x14,0x14,0x14,/*=*/
	0x00,0x41,0x22,0x14,0x08,/*>*/
	0x02,0x01,0x51,0x09,0x06,/*?*/
	0x3e,0x41,0x5d,0x5d,0x46,/*@*/
	0x7c,0x12,0x11,0x12,0x7c,/*A*/
	0x7f,0x49,0x49,0x49,0x36,/*B*/
	0x3e,0x41,0x41,0x41,0x22,/*C*/
	0x7f,0x41,0x41,0x41,0x3e,/*D*/
	0x7f,0x49,0x49,0x49,0x41,/*E*/
	0x7f,0x09,0x09,0x09,0x01,/*F*/
	0x3e,0x41,0x41,0x51,0x72,/*G*/
	0x7f,0x08,0x08,0x08,0x7f,/*H*/
	0x41,0x41,0x7f,0x41,0x41,/*I*/
	0x21,0x41,0x3f,0x01,0x01,/*J*/
	0x7f,0x08,0x14,0x22,0x41,/*K*/
	0x7f,0x40,0x40,0x40,0x40,/*L*/
	0x7f,0x02,0x04,0x02,0x7f,/*M*/
	0x7f,0x06,0x08,0x30,0x7f,/*N*/
	0x3e,0x41,0x41,0x41,0x3e,/*O*/
	0x7f,0x09,0x09,0x09,0x06,/*P*/
	0x3e,0x41,0x41,0x61,0x7e,/*Q*/
	0x7f,0x09,0x19,0x29,0x46,/*R*/
	0x26,0x49,0x49,0x49,0x32,/*S*/
	0x01,0x01,0x7f,0x01,0x01,/*T*/
	0x3f,0x40,0x40,0x40,0x3f,/*U*/
	0x1f,0x20,0x40,0x20,0x1f,/*V*/
	0x3f,0x40,0x30,0x40,0x3f,/*W*/
	0x63,0x14,0x08,0x14,0x63,/*X*/
	0x03,0x04,0x78,0x04,0x03,/*Y*/
	0x61,0x51,0x49,0x45,0x43,/*Z*/
	0x00,0x00,0x7f,0x41,0x00,/*[*/
	0x00,0x00,0x00,0x00,0x00,/*this should be / */
	0x01,0x06,0x08,0x30,0x40,/*]*/
	0x04,0x02,0x01,0x02,0x04,/*^*/
	0x80,0x80,0x80,0x80,0x80,/*_*/
	0x01,0x02,0x04,0x00,0x00,/*`*/
	0x20,0x54,0x54,0x54,0x78,/*a*/
	0x7f,0x48,0x44,0x44,0x38,/*b*/
	0x38,0x44,0x44,0x44,0x28,/*c*/
	0x38,0x44,0x44,0x48,0x7f,/*d*/
	0x38,0x54,0x54,0x54,0x18,/*e*/
	0x08,0x7e,0x09,0x01,0x02,/*f*/
	0x18,0xa4,0xa4,0xa4,0x78,/*g*/
	0x7f,0x08,0x08,0x08,0x70,/*h*/
	0x00,0x48,0x7a,0x40,0x00,/*i*/
	0x40,0x80,0x80,0x88,0x7a,/*j*/
	0x7f,0x10,0x10,0x28,0x44,/*k*/
	0x00,0x41,0x7f,0x40,0x00,/*l*/
	0x7c,0x04,0x38,0x04,0x78,/*m*/
	0x7c,0x04,0x04,0x04,0x78,/*n*/
	0x38,0x44,0x44,0x44,0x38,/*o*/
	0xfc,0x24,0x24,0x24,0x18,/*p*/
	0x18,0x24,0x24,0xfc,0x80,/*q*/
	0x7c,0x08,0x04,0x04,0x08,/*r*/
	0x48,0x54,0x54,0x54,0x20,/*s*/
	0x00,0x08,0x3c,0x48,0x20,/*t*/
	0x3c,0x40,0x40,0x40,0x7c,/*u*/
	0x0c,0x30,0x40,0x30,0x0c,/*v*/
	0x1c,0x60,0x18,0x60,0x1c,/*w*/
	0x44,0x28,0x10,0x28,0x44,/*x*/
	0x1c,0xa0,0xa0,0xa0,0x7c,/*y*/
	0x44,0x64,0x54,0x4c,0x44,/*z*/
	0x00,0x08,0x36,0x41,0x41,/*{*/
	0x20,0x40,0xff,0x40,0x20,/*arrow*/
	0x41,0x41,0x36,0x08,0x00,/*}*/
	0x10,0x08,0x18,0x10,0x08/*~*/
	};

// The SparkFun Logo rendered as a sprite 10 pixels wide and 16 pixels high.
//  The first ten bytes are the top half, the second ten, the bottom half.
static const char logoArray[20] PROGMEM = {
  0x80, 0xc0, 0x40, 0x0c, 0x3e,
  0xfe, 0xf2, 0xe0, 0xf0, 0xe0,
  0xff, 0x7f, 0x3f, 0x1f, 0x1f,
  0x1f, 0x1f, 0x0f, 0x07, 0x03
  };
#endif

// This is our block of sprites. It's an array of 128 8x8 sprites, mostly
//  unused.
static const char spriteArray[1024] PROGMEM = {
  0x00, 0x3f, 0x42, 0x91, 0x82, 0x91, 0x42, 0x3f, // Pac-man ghost
  0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, // four corners
  0x10, 0x20, 0x40, 0xff, 0xff, 0x40, 0x20, 0x10, // up arrow.
  0x10, 0x20, 0x40, 0xff, 0x00, 0x00, 0x00, 0x00, // half up arrow
  0x3c, 0x42, 0x81, 0xa1, 0x89, 0x99, 0x66, 0x24, // Pac-man right mouth open
  0x3c, 0x42, 0x81, 0xa1, 0x81, 0x89, 0x4a, 0x3c, // Pac-man right mouth shut
  0x24, 0x66, 0x99, 0x89, 0xa1, 0x81, 0x42, 0x3c, // Pac-man left mouth open
  0x3c, 0x4a, 0x89, 0x81, 0xa1, 0x81, 0x42, 0x3c, // Pac-man left mouth shut
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
  };
  
  
// This is our block of sprite masks. The mask for the sprite should be a '1'
//  anywhere we want the original background to show through.
static const char maskArray[1024] PROGMEM = {
  0xff, 0xc0, 0x81, 0x00, 0x01, 0x00, 0x81, 0xc0, // Pac-man ghost
  0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7e,
  0xef, 0xdf, 0xbf, 0x00, 0x00, 0xbf, 0xdf, 0xef, // up arrow
  0xef, 0xdf, 0xbf, 0x00, 0xff, 0xff, 0xff, 0xff, // half up arrow
  0xc3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x99, 0xdb, // Pac-man right mouth open
  0xc3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc3, // Pac-man right mouth shut
  0xdb, 0x99, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc3, // Pac-man left mouth open
  0xc3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc3, // Pac-man left mouth shut
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
  };
