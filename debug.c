#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "debug.h"
#include "config.h"

// #include <stdio.h>
#include <stdarg.h>

#if IN_USE_PLATFORM == STM32_PLATFORM
//	#include "usart.h"
#include "main.h"

void debug_print(
	UART_HandleTypeDef* uart_interface,
	char* 							data,
	uint16_t 						data_size
) {
	HAL_UART_Transmit(uart_interface, (const uint8_t*)data, data_size,2000);
}



Void debug_info(
	UART_HandleTypeDef* uart_interface,
	Char*				data
) {
	Char buffer[1024] = {0};
	sprintf(buffer, "Debug Info: %s \r\n", data);		
	HAL_UART_Transmit(uart_interface, (const uint8_t*)buffer, strlen(buffer),2000);
}


void _printf(const char *format, ...) {
    static char buffer[DEBUG_BUFFER_SIZE];
    va_list args;
    
    va_start(args, format);
    int len = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    
    if (len > 0) {
        HAL_UART_Transmit(
			&DEBUG_PORT, 
			(uint8_t*)buffer, 
            (len < DEBUG_BUFFER_SIZE) ? len : DEBUG_BUFFER_SIZE - 1, 
            HAL_MAX_DELAY
		);
    }
}
#endif
