
TYPE
	SDO_step_type : 
		(
		SDO_SET_REGISTERS,
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
		);
	SDO_type : 	STRUCT 
		step : SDO_step_type;
		device : STRING[80];
		CANopenSDORead8_0 : CANopenSDORead8;
		CANopenSDOWrite8_0 : CANopenSDOWrite8;
	END_STRUCT;
	test_type : 	STRUCT 
		data0 : USINT;
		data1 : USINT;
		data2 : USINT;
		data3 : USINT;
	END_STRUCT;
	SERVO_type : 	STRUCT 
		step : SERVO_step_type;
		EnableOperation : BOOL;
		DisableOperation : BOOL;
		ActualVelocity : DINT; (*[mrev/s]*)
	END_STRUCT;
	SERVO_step_type : 
		(
		SERVO_INIT,
		SERVO_FIRST_STEP,
		SERVO_SWITCH_ON_DISABLED,
		SERVO_READY_TO_SWITCH_ON,
		SERVO_SWITCHED_ON,
		SERVO_OPERATION_ENABLE
		);
END_TYPE
