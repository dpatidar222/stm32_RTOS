/*
 * task_led.c
 *
 *  Created on: Aug 8, 2023
 *      Author: deepakp
 */

#include "main.h"
#include "cmsis_os.h"
#include "task_led.h"
#include "queue.h"

extern QueueHandle_t xQueue_serial_com_tx;

void led_task(void * pvParameters){

	while(1){
		LED(ON);
		xQueueSend(xQueue_serial_com_tx, "LED ON\n\r", 1 );
		vTaskDelay( 1000 );
		LED(OFF);
		xQueueSend(xQueue_serial_com_tx, "LED OFF\n\r", 1 );
		vTaskDelay( 1000 );
	}

}

void LED(led_state state){
	if(state == ON) HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	else if(state == OFF)  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	else{}
}
