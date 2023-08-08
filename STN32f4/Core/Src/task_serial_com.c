/*
 * task_serial_com.c
 *
 *  Created on: Aug 8, 2023
 *      Author: deepakp
 */


#include "main.h"
#include "cmsis_os.h"
#include "task_serial_com.h"
#include "queue.h"

extern QueueHandle_t xQueue_serial_com_tx;
extern UART_HandleTypeDef huart2;

void task_serial_com(void * pvParameters){
	BaseType_t status;
	uint8_t data;
	while(1){
		status = xQueueReceive( xQueue_serial_com_tx, &data, 1 );
		if(status == pdPASS) HAL_UART_Transmit_IT(&huart2, &data, 1);
	}

}
