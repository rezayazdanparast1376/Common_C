#ifndef _DEBUG_H_
#define _DEBUG_H_


#include 	"defs.h"
#include 	"config.h"
#include	"color.h"



#if IN_USE_PLATFORM == STM32_PLATFORM
	#include "usart.h"
	#define DEBUG_PORT 			huart1
	extern 	UART_HandleTypeDef 	DEBUG_PORT;
#endif

#define _DEBUG_MODE_		0
#define _RELEASE_MODE_		1
#define PROG_MODE 			_DEBUG_MODE_	

#define DEBUG_INFO_MSG		COLOR_BLUE"INFO"COLOR_WHITE
#define DEBUG_WARNING_MSG	COLOR_YELLOW"WARNING"COLOR_WHITE
#define DEBUG_ERROR_MSG		COLOR_RED"ERROR"COLOR_WHITE


#if IN_USE_PLATFORM == STM32_PLATFORM
	#define Soft_Assert_Void(condition, msg)    do{ if(!condition){ debug_info(&DEBUG_PORT, msg); return;      } } while(0)
	#define Soft_Assert_Int(condition, msg)     do{ if(!condition){ debug_info(&DEBUG_PORT, msg); return -1;   } } while(0)
	#define Soft_Assert_Ptr(condition, msg)     do{ if(!condition){ debug_info(&DEBUG_PORT, msg); return NULL; } } while(0)
	#define Soft_Assert_Ignore(condition, msg)  do{ if(!condition){ debug_info(&DEBUG_PORT, msg);              } } while(0)
	#define Soft_Assert_Break(condition, msg)   do{ if(!condition){ debug_info(&DEBUG_PORT, msg); break;       } } while(0)
	#define Soft_Assert_Contiue(condition, msg) do{ if(!condition){ debug_info(&DEBUG_PORT, msg); continue;    } } while(0)

	Void debug_print(
		UART_HandleTypeDef* uart_interface,
		Char*				data,
		UInt16				data_size
	);
		
	Void debug_info(
		UART_HandleTypeDef* uart_interface,
		Char*				data
	);

#elif IN_USE_PLATFORM == X86_PLATFORM
	#define Debug_Info(msg)								printf("%s[FILE: %s - LINE: %d] %s \n", DEBUG_INFO_MSG, __FILE__, __LINE__, msg)
	#define Debug_Warning(msg)							printf("%s[FILE: %s - LINE: %d] %s \n", DEBUG_WARNING_MSG, __FILE__, __LINE__, msg)
	#define Debug_Error(msg)							printf("%s[FILE: %s - LINE: %d] %s \n", DEBUG_ERROR_MSG, __FILE__, __LINE__, msg)

	#define Soft_Assert_Ignore(condition, msg)    		do{ if(!condition){ Debug_Error(msg);               } } while(0)
	
	#define Soft_Assert_Void(condition, msg) 			do{ if(!condition){ Debug_Error(msg); return;       } } while(0)
	#define Soft_Assert_Ret(condition, error, msg)		do{ if(!condition){ Debug_Error(msg); return error; }} while (0)
	#define Soft_Assert_Break(condition, msg)     		do{ if(!condition){ Debug_Error(msg); break;        } } while(0)
	#define Soft_Assert_Contiue(condition, msg)   		do{ if(!condition){ Debug_Error(msg); continue;     } } while(0)

	#define Soft_Assert_Int(condition, msg)       		Soft_Assert_Ret(condition, -1, msg)
	#define Soft_Assert_Ptr(condition, msg)       		Soft_Assert_Ret(condition, NULL, msg)

	// #define Soft_Assert_Int(condition, msg)       		do{ if(!condition){ Debug_Error(msg); return -1;    } } while(0)
	// #define Soft_Assert_Ptr(condition, msg)       		do{ if(!condition){ Debug_Error(msg); return NULL;  } } while(0)
#endif
	
		
#endif //#ifndef _DEBUG_H_
