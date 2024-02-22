#ifndef __GLOBAL_DEFINES__
#define __GLOBAL_DEFINES__

//#define _DEBUG								//WARNING: DEBUG causes a malfunction -\_(-.-)_/-
//#define _FALLBACK_FORCE

#ifdef _DEBUG
	#define SWVERSION "       "
#else
	#define SWVERSION "       "
#endif

#define TRUE 1
#define FALSE 0
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define abs(x) ((x)<0 ? -(x) : (x))
#define PWM_MAX 32767
#define PP_RATIO 0.007246

#endif