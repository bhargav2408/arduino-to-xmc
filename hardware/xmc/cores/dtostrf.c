//****************************************************************************
// @Module        Arduino-compatible dtostrf implementation.
// @Filename      dtostrf.c
// @Project       Arduino_XMC
//----------------------------------------------------------------------------
// @Controller    Infineon XMC1x00
//
// @Compiler      GCC
//
// @Codegenerator DAvE 3.0 Compatible
//
// @Description   This file contains low level functions to implement the
//					dtostrf conversion.
//
// @Link          http://arduino.cc/en/Reference/Delay
//
//----------------------------------------------------------------------------
// @Date          10/02/2014 00.17.23
//
//****************************************************************************



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "dtostrf.h"
#include <string.h>
#include <stdio.h>

//****************************************************************************
// @Macros
//****************************************************************************


//****************************************************************************
// @Defines
//****************************************************************************

//****************************************************************************
// @Typedefs
//****************************************************************************


//****************************************************************************
// @Imported Global Variables
//****************************************************************************


//****************************************************************************
// @Global Variables
//****************************************************************************


//****************************************************************************
// @External Prototypes
//****************************************************************************


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************


//****************************************************************************
// @Function      dtostrf
//
//----------------------------------------------------------------------------
// @Description   Converts a float into string.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Link          http://forum.arduino.cc/index.php?topic=103935.0
//----------------------------------------------------------------------------
// @Date          28/01/2014
//
//****************************************************************************

char * dtostrf(float val, int width, unsigned int precision, char *buf)
{
	char format[20];
	sprintf(format, "%%%d.%df", width, precision);
	sprintf(buf, format, val);
	return buf;
}



//****************************************************************************
// @Local Functions
//****************************************************************************



//****************************************************************************
// 							       END OF FILE
//****************************************************************************

