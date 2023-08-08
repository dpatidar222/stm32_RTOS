/*
 * task_led.h
 *
 *  Created on: Aug 8, 2023
 *      Author: deepakp
 */

#ifndef INC_TASK_LED_H_
#define INC_TASK_LED_H_

typedef enum {
	ON,
	OFF
}led_state;

void led_task(void * pvParameters);
void LED(led_state state);

#endif /* INC_TASK_LED_H_ */
