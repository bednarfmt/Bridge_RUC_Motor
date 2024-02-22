/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1708587174_4_
#define _BUR_1708587174_4_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_BUR_LOCAL unsigned char mask7;
_BUR_LOCAL unsigned char mask6;
_BUR_LOCAL unsigned char mask5;
_BUR_LOCAL unsigned char mask4;
_BUR_LOCAL unsigned char mask3;
_BUR_LOCAL unsigned char mask2;
_BUR_LOCAL unsigned char mask1;
_BUR_LOCAL unsigned char mask0;
_BUR_LOCAL struct SERVO_type SERVO;
_BUR_LOCAL signed long IOActualVelocity;
_BUR_LOCAL unsigned short IOOperationModeDisplay;
_BUR_LOCAL signed long IOVelocitySetpoint;
_BUR_LOCAL signed char IOOperationMode;
_BUR_LOCAL unsigned short IOStatusWord;
_BUR_LOCAL unsigned short IOControlWord;
_BUR_LOCAL plcbit ServoDriveModuleOK;
_BUR_LOCAL plctime SDOWriteWaitTime;
_BUR_LOCAL plcbit ParamWriteDone;
_BUR_LOCAL struct TON TON_0;
_BUR_LOCAL unsigned long VelocityFeedbackFilter;
_BUR_LOCAL float ProfilerMaxDec;
_BUR_LOCAL float ProfilerMaxAcc;
_BUR_LOCAL float ProfilerMaxVelocity;
_BUR_LOCAL float VelocityLoopKp;
_BUR_LOCAL float VelocityLoopKi;
_BUR_LOCAL float MaxCurrent;
_BUR_LOCAL float Test;
_BUR_LOCAL struct SDO_type SDO;
_BUR_LOCAL struct ArCanSetBitTimingRegisters ArCanSetBitTimingRegisters_0;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/ServoCtrl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/standard/standard.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/ArCan/ArCan.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1708587174_4_ */

