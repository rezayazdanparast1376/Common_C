#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "debug.h"
#include "config.h"

#if IN_USE_PLATFORM == STM32_PLATFORM
	#include "usart.h"

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
#endif
