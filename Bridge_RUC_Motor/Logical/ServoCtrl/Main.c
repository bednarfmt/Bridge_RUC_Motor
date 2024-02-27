
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

#define TRUE 1
#define FALSE 0
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define abs(x) ((x)<0 ? -(x) : (x))

void _INIT ProgramInit(void)
{
	SDO.step = SDO_SET_REGISTERS;
	brsstrcpy((UDINT) SDO.device, (UDINT) "IF8");  //set interface 
	gServoData.Servo_OK = FALSE;
}

BOOL Ready_to_switch_on_disabled_state (void){ // 592
	return ((IOStatusWord & mask6) && (~IOStatusWord & mask3) && (~IOStatusWord & mask2) && (~IOStatusWord & mask1) && (~IOStatusWord & mask0));
}

BOOL Fault_state (void){

	return (IOStatusWord & mask3);
}


void _CYCLIC ProgramCyclic(void)
{

	
		// ============== STATE MACHINE FOR WRITING SERVO PARAMETERS ("SDO download") ==============
		switch(SDO.step) {
			
			case SDO_SET_REGISTERS :
					
				ArCanSetBitTimingRegisters_0.Execute = 1;
				brsstrcpy((UDINT) &ArCanSetBitTimingRegisters_0.DeviceName, (UDINT) &SDO.device);
				ArCanSetBitTimingRegisters_0.Register0 = 0x01; 	/*250kbit/s*/	/* 0x00; Set to 1 000 000 bit/s */
				ArCanSetBitTimingRegisters_0.Register1 = 0x1C; 	/*250kbit/s*/	/* 0x14; Set to 1 000 000 bit/s */
					
				ArCanSetBitTimingRegisters(&ArCanSetBitTimingRegisters_0);
			
				if (ArCanSetBitTimingRegisters_0.Done) SDO.step = SDO_WAIT_4_CMD;
				
				break;
			case SDO_WAIT_4_CMD:
			
				if (ServoDriveModuleOK && !ParamWriteDone) {
					SDO.step = SDO_RUN_TIMER;
				}
				break;
		
			case SDO_RUN_TIMER:
			
				TON_0.PT = SDOWriteWaitTime;
				TON_0.IN = 1;	
			
				if (TON_0.Q) {
					TON_0.IN = 0;
			//		SDO.step = SDO_READ;
			
					SDO.step = SDO_WAIT_4_CMD;
					ParamWriteDone = 1;
			
				}
				break;
			
			case SDO_READ:

				SDO.CANopenSDORead8_0.enable = 1;
				SDO.CANopenSDORead8_0.pDevice =(UDINT) &(SDO.device);
				SDO.CANopenSDORead8_0.node = 32; //(* Node ID from IO device *)
				SDO.CANopenSDORead8_0.index = 0x21E0;
				SDO.CANopenSDORead8_0.subindex = 0x00;
			
				CANopenSDORead8(&SDO.CANopenSDORead8_0); // (* Call function block *) 
			
				if (SDO.CANopenSDORead8_0.status == ERR_OK) {
					brsmemcpy((UDINT) &Test, (UDINT) &SDO.CANopenSDORead8_0.data0, 4);
					SDO.step = SDO_WRITE_MAX_CURRENT; //(* next step *)
				} else if (SDO.CANopenSDORead8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
					//busy
				} else {  //(* Error step *)
					//	SDO.step = 10;
				}
				break;
		
			case SDO_WRITE_MAX_CURRENT:
	
				SDO.CANopenSDOWrite8_0.enable = 1;
				SDO.CANopenSDOWrite8_0.pDevice = (UDINT) &(SDO.device);
				SDO.CANopenSDOWrite8_0.node = 32;  //(* Node ID from IO device *)
				SDO.CANopenSDOWrite8_0.index = 0x21E0;
				SDO.CANopenSDOWrite8_0.subindex = 0x00;
				brsmemcpy((UDINT) &SDO.CANopenSDOWrite8_0.data0, (UDINT) &MaxCurrent, 4);
				SDO.CANopenSDOWrite8_0.datalen = 4;
		
				if (SDO.CANopenSDOWrite8_0.status == ERR_OK) { // (* OK *)
					SDO.step = SDO_WRITE_MAX_VELOCITY; //(* next step *)
				} else if (SDO.CANopenSDOWrite8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
					//(* busy *)
				} else { // (* Error step *)
					//	SDO.step = 10;
				}
				break;
		
			case SDO_WRITE_MAX_VELOCITY:
	
				SDO.CANopenSDOWrite8_0.enable = 1;
				SDO.CANopenSDOWrite8_0.pDevice = (UDINT) &(SDO.device);
				SDO.CANopenSDOWrite8_0.node = 32;  //(* Node ID from IO device *)
				SDO.CANopenSDOWrite8_0.index = 0x2025;
				SDO.CANopenSDOWrite8_0.subindex = 0x00;
				brsmemcpy((UDINT) &SDO.CANopenSDOWrite8_0.data0, (UDINT) &ProfilerMaxVelocity, 4);
				SDO.CANopenSDOWrite8_0.datalen = 4;
			
				if (SDO.CANopenSDOWrite8_0.status == ERR_OK) { // (* OK *)
					SDO.step = SDO_WRITE_MAX_ACCELERATION; //(* next step *)
				} else if (SDO.CANopenSDOWrite8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
					//(* busy *)
				} else { // (* Error step *)
					//	SDO.step = 10;
				}
				break;
		
			case SDO_WRITE_MAX_ACCELERATION:
	
				SDO.CANopenSDOWrite8_0.enable = 1;
				SDO.CANopenSDOWrite8_0.pDevice = (UDINT) &(SDO.device);
				SDO.CANopenSDOWrite8_0.node = 32;  //(* Node ID from IO device *)
				SDO.CANopenSDOWrite8_0.index = 0x2026;
				SDO.CANopenSDOWrite8_0.subindex = 0x00;
				brsmemcpy((UDINT) &SDO.CANopenSDOWrite8_0.data0, (UDINT) &ProfilerMaxAcc, 4);
				SDO.CANopenSDOWrite8_0.datalen = 4;
			
				if (SDO.CANopenSDOWrite8_0.status == ERR_OK) { // (* OK *)
					SDO.step = SDO_WRITE_MAX_DECELERATION; //(* next step *)
				} else if (SDO.CANopenSDOWrite8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
					//(* busy *)
				} else { // (* Error step *)
					//	SDO.step = 10;
				}
				break;
		
			case SDO_WRITE_MAX_DECELERATION:
	
				SDO.CANopenSDOWrite8_0.enable = 1;
				SDO.CANopenSDOWrite8_0.pDevice = (UDINT) &(SDO.device);
				SDO.CANopenSDOWrite8_0.node = 32;  //(* Node ID from IO device *)
				SDO.CANopenSDOWrite8_0.index = 0x2027;
				SDO.CANopenSDOWrite8_0.subindex = 0x00;
				brsmemcpy((UDINT) &SDO.CANopenSDOWrite8_0.data0, (UDINT) &ProfilerMaxDec, 4);
				SDO.CANopenSDOWrite8_0.datalen = 4;

				if (SDO.CANopenSDOWrite8_0.status == ERR_OK) { // (* OK *)
					SDO.step = SDO_WRITE_VELOCITY_FEEDBACK; //(* next step *)
				} else if (SDO.CANopenSDOWrite8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
					//(* busy *)
				} else { // (* Error step *)
					//	SDO.step = 10;
				}
				break;
		
			case SDO_WRITE_VELOCITY_FEEDBACK:
	
				SDO.CANopenSDOWrite8_0.enable = 1;
				SDO.CANopenSDOWrite8_0.pDevice = (UDINT) &(SDO.device);
				SDO.CANopenSDOWrite8_0.node = 32;  //(* Node ID from IO device *)
				SDO.CANopenSDOWrite8_0.index = 0x2551;
				SDO.CANopenSDOWrite8_0.subindex = 0x00;
				brsmemcpy((UDINT) &SDO.CANopenSDOWrite8_0.data0, (UDINT) &VelocityFeedbackFilter, 4);
				SDO.CANopenSDOWrite8_0.datalen = 4;

				if (SDO.CANopenSDOWrite8_0.status == ERR_OK) { // (* OK *)
					SDO.step = SDO_WRITE_2360; //(* next step *)
				} else if (SDO.CANopenSDOWrite8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
					//(* busy *)
				} else { // (* Error step *)
					//	SDO.step = 10;
				}
				break;	
		case SDO_WRITE_2360:
	
			SDO.CANopenSDOWrite8_0.enable = 1;
			SDO.CANopenSDOWrite8_0.pDevice = (UDINT) &(SDO.device);
			SDO.CANopenSDOWrite8_0.node = 32;  //(* Node ID from IO device *)
			SDO.CANopenSDOWrite8_0.index = 0x2360;
			SDO.CANopenSDOWrite8_0.subindex = 0x00;
			brsmemcpy((UDINT) &SDO.CANopenSDOWrite8_0.data0, (UDINT) &VelocityFeedbackType, 4);
			SDO.CANopenSDOWrite8_0.datalen = 4;
			
			if (SDO.CANopenSDOWrite8_0.status == ERR_OK) { // (* OK *)
				SDO.step = SDO_WRITE_2388; //(* next step *)
			} else if (SDO.CANopenSDOWrite8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
				//(* busy *)
			} else { // (* Error step *)
				//	SDO.step = 10;
			}
			break;	
		
		case SDO_WRITE_2388:
	
			SDO.CANopenSDOWrite8_0.enable = 1;
			SDO.CANopenSDOWrite8_0.pDevice = (UDINT) &(SDO.device);
			SDO.CANopenSDOWrite8_0.node = 32;  //(* Node ID from IO device *)
			SDO.CANopenSDOWrite8_0.index = 0x2388;
			SDO.CANopenSDOWrite8_0.subindex = 0x00;
			brsmemcpy((UDINT) &SDO.CANopenSDOWrite8_0.data0, (UDINT) &IncrementalEncoderResolution, 4);
			SDO.CANopenSDOWrite8_0.datalen = 4;

			if (SDO.CANopenSDOWrite8_0.status == ERR_OK) { // (* OK *)
				ParamWriteDone = 1;
				SDO.step = SDO_WAIT_4_CMD; //(* next step *)
			} else if (SDO.CANopenSDOWrite8_0.status == ERR_FUB_BUSY) { // (* FBK not yet finished *)
				//(* busy *)
			} else { // (* Error step *)
				//	SDO.step = 10;
			}
			break;	
		
		}
	
		// If servo drive module is not OK, get ready to write servo parameters again
		if (!ServoDriveModuleOK) {
			ParamWriteDone = 0;
			SDO.step = SDO_WAIT_4_CMD;
			gServoData.Servo_OK = FALSE;
		}
		else
			gServoData.Servo_OK = TRUE;	
	
		CANopenSDOWrite8(&SDO.CANopenSDOWrite8_0); //call function block
		SDO.CANopenSDOWrite8_0.enable = 0; //disable function block
	
		TON(&TON_0); //call function block
		TON_0.IN = 0; //disable function block
		
		// Copy data
		//	gServoData.VelocityActual =(DINT) (((REAL) IOActualVelocity / 1000.0) * 60.0);
		gServoData.VelocityActual = (DINT) ((REAL) IOActualVelocity /** SERVO_VELOCITY_RECALC_PARAM*/);

		// Enable/disable servo drive
		if ((SERVO.step == SERVO_SWITCHED_ON) && (gServoData.ServoON)) {
			SERVO.EnableOperation = 1;
		}
		if ((SERVO.step == SERVO_OPERATION_ENABLE) && (!gServoData.ServoON)) {
			SERVO.DisableOperation = 1;
		}
	
	//if (Fault_state()) SERVO.step = FAULT;
	
		// ============== STATE MACHINE FOR SERVO DRIVE CONTROL ==============================
		switch(SERVO.step) {
		
			case SERVO_INIT:
		
				IOControlWord = 0; //Disable voltage command
			
				if (ParamWriteDone) {
					SERVO.step = SERVO_FIRST_STEP;	
				}
				break;
		
			case SERVO_FIRST_STEP:
			
				IOControlWord = 0; //Disable voltage command
			
				if (Ready_to_switch_on_disabled_state())  //0bxxxx xxxx x1xx 0000 (592 decimalne)
					SERVO.step = SERVO_SWITCH_ON_DISABLED;

				break;
		
			case SERVO_SWITCH_ON_DISABLED:
		
				IOControlWord = 6; //Shutdown command
			
				if ((~IOStatusWord & mask6) && (IOStatusWord & mask5) && (~IOStatusWord & mask3) && (~IOStatusWord & mask2) && (~IOStatusWord & mask1) && (IOStatusWord & mask0)) { //0bxxxx xxxx x01x 0001
					SERVO.step = SERVO_READY_TO_SWITCH_ON;	
				}
				break;
		
			case SERVO_READY_TO_SWITCH_ON:
		
				IOControlWord = 7; //Switch on command
			
				if ((~IOStatusWord & mask6) && (IOStatusWord & mask5) && (~IOStatusWord & mask3) && (~IOStatusWord & mask2) && (IOStatusWord & mask1) && (IOStatusWord & mask0)) { //0bxxxx xxxx x01x 0011
					SERVO.step = SERVO_SWITCHED_ON;	
				}
				break;
		
			case SERVO_SWITCHED_ON:
			
				IOOperationMode = 3; //Velocity mode
			
				if (SERVO.EnableOperation) {
					IOControlWord = 15; //Enable operation command
				}
		
				if ((~IOStatusWord & mask6) && (IOStatusWord & mask5) && (~IOStatusWord & mask3) && (IOStatusWord & mask2) && (IOStatusWord & mask1) && (IOStatusWord & mask0)) { //0bxxxx xxxx x01x 0111	
					IOVelocitySetpoint = 0;	
					SERVO.step = SERVO_OPERATION_ENABLE;
				}
				
				if (Ready_to_switch_on_disabled_state()) { //0bxxxx xxxx x1xx 0000 // 592
					SERVO.step = SERVO_SWITCH_ON_DISABLED;
				}
				
				break;
		
			case SERVO_OPERATION_ENABLE:
		
				IOVelocitySetpoint = (DINT) ((REAL) gServoData.VelocitySetPoint /*/ SERVO_VELOCITY_RECALC_PARAM*/);
			
				if (SERVO.DisableOperation) {
					IOControlWord = 7; //Switch on command
					SERVO.step = SERVO_SWITCHED_ON;
				}
				
				if (Ready_to_switch_on_disabled_state()) { //0bxxxx xxxx x1xx 0000 // 592
					SERVO.step = SERVO_SWITCH_ON_DISABLED;
				}
				
				break;	
		
			case FAULT:
			
				IOControlWord = 128; //reset fault
			
				if (!Fault_state())
					SERVO.step = SERVO_FIRST_STEP;
			
				break;
		}
	
		// Reset commands
		SERVO.EnableOperation = 0;
		SERVO.DisableOperation = 0;
		
	
}

void _EXIT ProgramExit(void)
{

}

