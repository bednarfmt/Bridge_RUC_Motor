
TYPE
	ServoData_typ : 	STRUCT 
		VelocitySetPoint : DINT; (*[rpm]*)
		VelocityActual : DINT; (*[rpm]*)
		ServoON : BOOL;
		Servo_OK : BOOL;
	END_STRUCT;
END_TYPE
