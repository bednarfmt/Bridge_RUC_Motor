/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1708587174_3_
#define _BUR_1708587174_3_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef enum SDO_step_type
{	SDO_SET_REGISTERS,
	SDO_WAIT_4_CMD,
	SDO_RUN_TIMER,
	SDO_READ,
	SDO_WRITE_MAX_CURRENT,
	SDO_WRITE_MAX_VELOCITY,
	SDO_WRITE_MAX_ACCELERATION,
	SDO_WRITE_MAX_DECELERATION,
	SDO_WRITE_VELOCITY_FEEDBACK,
	SDO_WRITE_2500,
	SDO_WRITE_2501,
	SDO_WRITE_2505,
	SDO_WRITE_2506,
	SDO_WRITE_250A,
	SDO_WRITE_250B
} SDO_step_type;

typedef enum SERVO_step_type
{	SERVO_INIT,
	SERVO_FIRST_STEP,
	SERVO_SWITCH_ON_DISABLED,
	SERVO_READY_TO_SWITCH_ON,
	SERVO_SWITCHED_ON,
	SERVO_OPERATION_ENABLE
} SERVO_step_type;

typedef struct SDO_type
{	enum SDO_step_type step;
	plcstring device[81];
	struct CANopenSDORead8 CANopenSDORead8_0;
	struct CANopenSDOWrite8 CANopenSDOWrite8_0;
} SDO_type;

typedef struct test_type
{	unsigned char data0;
	unsigned char data1;
	unsigned char data2;
	unsigned char data3;
} test_type;

typedef struct SERVO_type
{	enum SERVO_step_type step;
	plcbit EnableOperation;
	plcbit DisableOperation;
	signed long ActualVelocity;
} SERVO_type;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/ServoCtrl/Types.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1708587174_3_ */

