/** ***************************************************************************
 * Description       : Teletext tables for VBIT 
 * Compiler          : GCC
 *
 * Copyright (C) 2010, Peter Kwan
 *
 * Permission to use, copy, modify, and distribute this software
 * and its documentation for any purpose and without fee is hereby
 * granted, provided that the above copyright notice appear in all
 * copies and that both that the copyright notice and this
 * permission notice and warranty disclaimer appear in supporting
 * documentation, and that the name of the author not be used in
 * advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.
 *
 * The author disclaim all warranties with regard to this
 * software, including all implied warranties of merchantability
 * and fitness.  In no event shall the author be liable for any
 * special, indirect or consequential damages or any damages
 * whatsoever resulting from loss of use, data or profits, whether
 * in an action of contract, negligence or other tortious action,
 * arising out of or in connection with the use or performance of
 * this software.
 *************************************************************************** **/
 
#include "tables.h"
 
/*--------------------------------------
*TABLES
--------------------------------------*/
/* Parity table.
* Use 1st half to add odd parity,
* Use 2nd half to add even parity
* Both halves to remove odd parity - signals error if -ve.
*/
const char ParTab[] = {
    0x80,0x01,0x02,0x83,0x04,0x85,0x86,0x07,
	0x08,0x89,0x8A,0x0B,0x8C,0x0D,0x0E,0x8F,
	0x10,0x91,0x92,0x13,0x94,0x15,0x16,0x97,
	0x98,0x19,0x1A,0x9B,0x1C,0x9D,0x9E,0x1F,
	0x20,0xA1,0xA2,0x23,0xA4,0x25,0x26,0xA7,
	0xA8,0x29,0x2A,0xAB,0x2C,0xAD,0xAE,0x2F,
	0xB0,0x31,0x32,0xB3,0x34,0xB5,0xB6,0x37,
	0x38,0xB9,0xBA,0x3B,0xBC,0x3D,0x3E,0xBF,
	0x40,0xC1,0xC2,0x43,0xC4,0x45,0x46,0xC7,
	0xC8,0x49,0x4A,0xCB,0x4C,0xCD,0xCE,0x4F,
	0xD0,0x51,0x52,0xD3,0x54,0xD5,0xD6,0x57,
	0x58,0xD9,0xDA,0x5B,0xDC,0x5D,0x5E,0xDF,
	0xE0,0x61,0x62,0xE3,0x64,0xE5,0xE6,0x67,
	0x68,0xE9,0xEA,0x6B,0xEC,0x6D,0x6E,0xEF,
	0x70,0xF1,0xF2,0x73,0xF4,0x75,0x76,0xF7,
	0xF8,0x79,0x7A,0xFB,0x7C,0xFD,0xFE,0x7F,

	0x00,0x81,0x82,0x03,0x84,0x05,0x06,0x87,
	0x88,0x09,0x0A,0x8B,0x0C,0x8D,0x8E,0x0F,
	0x90,0x11,0x12,0x93,0x14,0x95,0x96,0x17,
	0x18,0x99,0x9A,0x1B,0x9C,0x1D,0x1E,0x9F,
	0xA0,0x21,0x22,0xA3,0x24,0xA5,0xA6,0x27,
	0x28,0xA9,0xAA,0x2B,0xAC,0x2D,0x2E,0xAF,
	0x30,0xB1,0xB2,0x33,0xB4,0x35,0x36,0xB7,
	0xB8,0x39,0x3A,0xBB,0x3C,0xBD,0xBE,0x3F,
	0xC0,0x41,0x42,0xC3,0x44,0xC5,0xC6,0x47,
	0x48,0xC9,0xCA,0x4B,0xCC,0x4D,0x4E,0xCF,
	0x50,0xD1,0xD2,0x53,0xD4,0x55,0x56,0xD7,
	0xD8,0x59,0x5A,0xDB,0x5C,0xDD,0xDE,0x5F,
	0x60,0xE1,0xE2,0x63,0xE4,0x65,0x66,0xE7,
	0xE8,0x69,0x6A,0xEB,0x6C,0xED,0xEE,0x6F,
	0xF0,0x71,0x72,0xF3,0x74,0xF5,0xF6,0x77,
	0x78,0xF9,0xFA,0x7B,0xFC,0x7D,0x7E,0xFF};
/*-------------------------------------------
* Hamming code table
*		0	  1   2    3    4    5    6    7    8    9    A    B    C    D    E    F *///
// lets move this out of progmem, we need it to be fast
const char HamTab[] = 
{    0x15,0x02,0x49,0x5E,0x64,0x73,0x38,0x2F,0xD0,0xC7,0x8C,0x9B,0xA1,0xB6,0xFD,0xEA};

/*-------------------------------------------
* Hamming decode table
*/
const char DehamTable[] = {
	0x01,0x80,0x01,0x01,0x80,0x00,0x01,0x80,
	0x80,0x02,0x01,0x80,0x0A,0x80,0x80,0x07,
	0x80,0x00,0x01,0x80,0x00,0x00,0x80,0x00,
	0x06,0x80,0x80,0x0B,0x80,0x00,0x03,0x80,
	0x80,0x0C,0x01,0x80,0x04,0x80,0x80,0x07,
	0x06,0x80,0x80,0x07,0x80,0x07,0x07,0x07,
	0x06,0x80,0x80,0x05,0x80,0x00,0x0D,0x80,
	0x06,0x06,0x06,0x80,0x06,0x80,0x80,0x07,
	0x80,0x02,0x01,0x80,0x04,0x80,0x80,0x09,
	0x02,0x02,0x80,0x02,0x80,0x02,0x03,0x80,
	0x08,0x80,0x80,0x05,0x80,0x00,0x03,0x80,
	0x80,0x02,0x03,0x80,0x03,0x80,0x03,0x03,
	0x04,0x80,0x80,0x05,0x04,0x04,0x04,0x80,
	0x80,0x02,0x0F,0x80,0x04,0x80,0x80,0x07,
	0x80,0x05,0x05,0x05,0x04,0x80,0x80,0x05,
	0x06,0x80,0x80,0x05,0x80,0x0E,0x03,0x80,
	0x80,0x0C,0x01,0x80,0x0A,0x80,0x80,0x09,
	0x0A,0x80,0x80,0x0B,0x0A,0x0A,0x0A,0x80,
	0x08,0x80,0x80,0x0B,0x80,0x00,0x0D,0x80,
	0x80,0x0B,0x0B,0x0B,0x0A,0x80,0x80,0x0B,
	0x0C,0x0C,0x80,0x0C,0x80,0x0C,0x0D,0x80,
	0x80,0x0C,0x0F,0x80,0x0A,0x80,0x80,0x07,
	0x80,0x0C,0x0D,0x80,0x0D,0x80,0x0D,0x0D,
	0x06,0x80,0x80,0x0B,0x80,0x0E,0x0D,0x80,
	0x08,0x80,0x80,0x09,0x80,0x09,0x09,0x09,
	0x80,0x02,0x0F,0x80,0x0A,0x80,0x80,0x09,
	0x08,0x08,0x08,0x80,0x08,0x80,0x80,0x09,
	0x08,0x80,0x80,0x0B,0x80,0x0E,0x03,0x80,
	0x80,0x0C,0x0F,0x80,0x04,0x80,0x80,0x09,
	0x0F,0x80,0x0F,0x0F,0x80,0x0E,0x0F,0x80,
	0x08,0x80,0x80,0x05,0x80,0x0E,0x0D,0x80,
	0x80,0x0E,0x0F,0x80,0x0E,0x0E,0x80,0x0E};
/*-------------------------------------------
*/

// Four bit reverse nybble
unsigned char BitRev[16] = {
  '\x0','\x8','\x4','\xc',
  '\x2','\xa','\x6','\xe',
  '\x1','\x9','\x5','\xd',
  '\x3','\xb','\x7','\xf'
};

/*------------------------------------------
*Mrag Table. Contains pairs of bytes for
*Mrags for lines 0-27 in mags 1-8.
* While this is convenient it is a bit extravagant and might be a candidate for coding
* because it is a simple bit manipulation task.
*/
#define LenMragMagEntry	56

const char MragTable[8][LenMragMagEntry] = {
/*Mag 1 */
	  {0x02,0x15,0xc7,0x15,0x02,0x02,0xc7,0x02,
	  0x02,0x49,0xc7,0x49,0x02,0x5e,0xc7,0x5e,
	  0x02,0x64,0xc7,0x64,0x02,0x73,0xc7,0x73,
	  0x02,0x38,0xc7,0x38,0x02,0x2f,0xc7,0x2f,
	  0x02,0xd0,0xc7,0xd0,0x02,0xc7,0xc7,0xc7,
	  0x02,0x8c,0xc7,0x8c,0x02,0x9b,0xc7,0x9b,
	  0,0,0,0,0,0,0,0},

/*Mag 2 */
	  {0x49,0x15,0x8c,0x15,0x49,0x02,0x8c,0x02,
	  0x49,0x49,0x8c,0x49,0x49,0x5e,0x8c,0x5e,
	  0x49,0x64,0x8c,0x64,0x49,0x73,0x8c,0x73,
	  0x49,0x38,0x8c,0x38,0x49,0x2f,0x8c,0x2f,
	  0x49,0xd0,0x8c,0xd0,0x49,0xc7,0x8c,0xc7,
	  0x49,0x8c,0x8c,0x8c,0x49,0x9b,0x8c,0x9b,
	  0,0,0,0,0,0,0,0},

/*Mag 3*/
	  {0x5e,0x15,0x9b,0x15,0x5e,0x02,0x9b,0x02,
	  0x5e,0x49,0x9b,0x49,0x5e,0x5e,0x9b,0x5e,
	  0x5e,0x64,0x9b,0x64,0x5e,0x73,0x9b,0x73,
	  0x5e,0x38,0x9b,0x38,0x5e,0x2f,0x9b,0x2f,
	  0x5e,0xd0,0x9b,0xd0,0x5e,0xc7,0x9b,0xc7,
	  0x5e,0x8c,0x9b,0x8c,0x5e,0x9b,0x9b,0x9b,
	  0,0,0,0,0,0,0,0},

/*Mag 4*/
	  {0x64,0x15,0xa1,0x15,0x64,0x02,0xa1,0x02,
	  0x64,0x49,0xa1,0x49,0x64,0x5e,0xa1,0x5e,
	  0x64,0x64,0xa1,0x64,0x64,0x73,0xa1,0x73,
	  0x64,0x38,0xa1,0x38,0x64,0x2f,0xa1,0x2f,
	  0x64,0xd0,0xa1,0xd0,0x64,0xc7,0xa1,0xc7,
	  0x64,0x8c,0xa1,0x8c,0x64,0x9b,0xa1,0x9b,
	  0,0,0,0,0,0,0,0},

/*Mag 5 */
	  {0x73,0x15,0xb6,0x15,0x73,0x02,0xb6,0x02,
	  0x73,0x49,0xb6,0x49,0x73,0x5e,0xb6,0x5e,
	  0x73,0x64,0xb6,0x64,0x73,0x73,0xb6,0x73,
	  0x73,0x38,0xb6,0x38,0x73,0x2f,0xb6,0x2f,
	  0x73,0xd0,0xb6,0xd0,0x73,0xc7,0xb6,0xc7,
	  0x73,0x8c,0xb6,0x8c,0x73,0x9b,0xb6,0x9b,
	  0,0,0,0,0,0,0,0},

/*Mag 6 */
	  {0x38,0x15,0xfd,0x15,0x38,0x02,0xfd,0x02,
	  0x38,0x49,0xfd,0x49,0x38,0x5e,0xfd,0x5e,
	  0x38,0x64,0xfd,0x64,0x38,0x73,0xfd,0x73,
	  0x38,0x38,0xfd,0x38,0x38,0x2f,0xfd,0x2f,
	  0x38,0xd0,0xfd,0xd0,0x38,0xc7,0xfd,0xc7,
	  0x38,0x8c,0xfd,0x8c,0x38,0x9b,0xfd,0x9b,
	  0,0,0,0,0,0,0,0},

/*Mag 7 */
	  {0x2f,0x15,0xea,0x15,0x2f,0x02,0xea,0x02,
	  0x2f,0x49,0xea,0x49,0x2f,0x5e,0xea,0x5e,
	  0x2f,0x64,0xea,0x64,0x2f,0x73,0xea,0x73,
	  0x2f,0x38,0xea,0x38,0x2f,0x2f,0xea,0x2f,
	  0x2f,0xd0,0xea,0xd0,0x2f,0xc7,0xea,0xc7,
	  0x2f,0x8c,0xea,0x8c,0x2f,0x9b,0xea,0x9b,
	  0,0,0,0,0,0,0,0},

/*Mag 8 */
	  {0x15,0x15,0xd0,0x15,0x15,0x02,0xd0,0x02,
	  0x15,0x49,0xd0,0x49,0x15,0x5e,0xd0,0x5e,
	  0x15,0x64,0xd0,0x64,0x15,0x73,0xd0,0x73,
	  0x15,0x38,0xd0,0x38,0x15,0x2f,0xd0,0x2f,
	  0x15,0xd0,0xd0,0xd0,0x15,0xc7,0xd0,0xc7,
	  0x15,0x8c,0xd0,0x8c,0x15,0x9b,0xd0,0x9b,
	  0,0,0,0,0,0,0,0}

};
	  
/*----------------------------------------------
*------------------------------------------
*CRC lookup tables
*high byte table
*/
const char TH[] = {
	  0x00,0x52,0x25,0x77,0x4A,0x18,0x6F,0x3D,
	  0x94,0xC6,0xB1,0xE3,0xDE,0x8C,0xFB,0xA9,
	  0x28,0x7A,0x0D,0x5F,0x62,0x30,0x47,0x15,
	  0xBC,0xEE,0x99,0xCB,0xF6,0xA4,0xD3,0x81,
	  0x50,0x02,0x75,0x27,0x1A,0x48,0x3F,0x6D,
	  0xC4,0x96,0xE1,0xB3,0x8E,0xDC,0xAB,0xF9,
	  0x78,0x2A,0x5D,0x0F,0x32,0x60,0x17,0x45,
	  0xEC,0xBE,0xC9,0x9B,0xA6,0xF4,0x83,0xD1,
	  0xA0,0xF2,0x85,0xD7,0xEA,0xB8,0xCF,0x9D,
	  0x34,0x66,0x11,0x43,0x7E,0x2C,0x5B,0x09,
	  0x88,0xDA,0xAD,0xFF,0xC2,0x90,0xE7,0xB5,
	  0x1C,0x4E,0x39,0x6B,0x56,0x04,0x73,0x21,
	  0xF0,0xA2,0xD5,0x87,0xBA,0xE8,0x9F,0xCD,
	  0x64,0x36,0x41,0x13,0x2E,0x7C,0x0B,0x59,
	  0xD8,0x8A,0xFD,0xAF,0x92,0xC0,0xB7,0xE5,
	  0x4C,0x1E,0x69,0x3B,0x06,0x54,0x23,0x71,
	  0x40,0x12,0x65,0x37,0x0A,0x58,0x2F,0x7D,
	  0xD4,0x86,0xF1,0xA3,0x9E,0xCC,0xBB,0xE9,
	  0x68,0x3A,0x4D,0x1F,0x22,0x70,0x07,0x55,
	  0xFC,0xAE,0xD9,0x8B,0xB6,0xE4,0x93,0xC1,
	  0x10,0x42,0x35,0x67,0x5A,0x08,0x7F,0x2D,
	  0x84,0xD6,0xA1,0xF3,0xCE,0x9C,0xEB,0xB9,
	  0x38,0x6A,0x1D,0x4F,0x72,0x20,0x57,0x05,
	  0xAC,0xFE,0x89,0xDB,0xE6,0xB4,0xC3,0x91,
	  0xE0,0xB2,0xC5,0x97,0xAA,0xF8,0x8F,0xDD,
	  0x74,0x26,0x51,0x03,0x3E,0x6C,0x1B,0x49,
	  0xC8,0x9A,0xED,0xBF,0x82,0xD0,0xA7,0xF5,
	  0x5C,0x0E,0x79,0x2B,0x16,0x44,0x33,0x61,
	  0xB0,0xE2,0x95,0xC7,0xFA,0xA8,0xDF,0x8D,
	  0x24,0x76,0x01,0x53,0x6E,0x3C,0x4B,0x19,
	  0x98,0xCA,0xBD,0xEF,0xD2,0x80,0xF7,0xA5,
	  0x0C,0x5E,0x29,0x7B,0x46,0x14,0x63,0x31};
/*low byte table
*/
const char TL[] = {
	0x00,0x88,0x02,0x8A,0x04,0x8C,0x06,0x8E,
	0x08,0x80,0x0A,0x82,0x0C,0x84,0x0E,0x86,
	0x11,0x99,0x13,0x9B,0x15,0x9D,0x17,0x9F,
	0x19,0x91,0x1B,0x93,0x1D,0x95,0x1F,0x97,
	0x22,0xAA,0x20,0xA8,0x26,0xAE,0x24,0xAC,
	0x2A,0xA2,0x28,0xA0,0x2E,0xA6,0x2C,0xA4,
	0x33,0xBB,0x31,0xB9,0x37,0xBF,0x35,0xBD,
	0x3B,0xB3,0x39,0xB1,0x3F,0xB7,0x3D,0xB5,
	0x44,0xCC,0x46,0xCE,0x40,0xC8,0x42,0xCA,
	0x4C,0xC4,0x4E,0xC6,0x48,0xC0,0x4A,0xC2,
	0x55,0xDD,0x57,0xDF,0x51,0xD9,0x53,0xDB,
	0x5D,0xD5,0x5F,0xD7,0x59,0xD1,0x5B,0xD3,
	0x66,0xEE,0x64,0xEC,0x62,0xEA,0x60,0xE8,
	0x6E,0xE6,0x6C,0xE4,0x6A,0xE2,0x68,0xE0,
	0x77,0xFF,0x75,0xFD,0x73,0xFB,0x71,0xF9,
	0x7F,0xF7,0x7D,0xF5,0x7B,0xF3,0x79,0xF1,
	0x89,0x01,0x8B,0x03,0x8D,0x05,0x8F,0x07,
	0x81,0x09,0x83,0x0B,0x85,0x0D,0x87,0x0F,
	0x98,0x10,0x9A,0x12,0x9C,0x14,0x9E,0x16,
	0x90,0x18,0x92,0x1A,0x94,0x1C,0x96,0x1E,
	0xAB,0x23,0xA9,0x21,0xAF,0x27,0xAD,0x25,
	0xA3,0x2B,0xA1,0x29,0xA7,0x2F,0xA5,0x2D,
	0xBA,0x32,0xB8,0x30,0xBE,0x36,0xBC,0x34,
	0xB2,0x3A,0xB0,0x38,0xB6,0x3E,0xB4,0x3C,
	0xCD,0x45,0xCF,0x47,0xC9,0x41,0xCB,0x43,
	0xC5,0x4D,0xC7,0x4F,0xC1,0x49,0xC3,0x4B,
	0xDC,0x54,0xDE,0x56,0xD8,0x50,0xDA,0x52,
	0xD4,0x5C,0xD6,0x5E,0xD0,0x58,0xD2,0x5A,
	0xEF,0x67,0xED,0x65,0xEB,0x63,0xE9,0x61,
	0xE7,0x6F,0xE5,0x6D,0xE3,0x6B,0xE1,0x69,
	0xFE,0x76,0xFC,0x74,0xFA,0x72,0xF8,0x70,
	0xF6,0x7E,0xF4,0x7C,0xF2,0x7A,0xF0,0x78};

/*---------------------------------------------------------------------*/
