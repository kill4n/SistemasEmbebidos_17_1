/*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Example developed by Crhistian Segura 201624633
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include <string.h>

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"


/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)
#define task_PRIORITY (configMAX_PRIORITIES - 1)

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void hello_task(void *pvParameters) {
	int cont = 0;
	for (;;) {
		PRINTF("Helloo world.%d\r\n", cont++);
		/* Add your code here */
		//vTaskSuspend(NULL);
		vTaskDelay(1000);
	}
}

static void init_task(void *pvParameters)
{
	gpio_pin_config_t led_config = {kGPIO_DigitalOutput, 0, };
	/* Init output LED GPIO. */
	GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &led_config);
	GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, &led_config);
	GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, &led_config);
	vTaskSuspend(NULL);
}

static void task_blue(void *pvParameters){
	while(1){
		/* Toggle LED BLUE */
		LED_BLUE_TOGGLE();
		vTaskDelay( 300 );
	}
}

static void task_red(void *pvParameters){
	while(1){
		/* Toggle RED BLUE */
		LED_RED_TOGGLE();
		vTaskDelay( 600 );
	}
}

static void task_green(void *pvParameters){
	while(1){
		/* Toggle GREEN BLUE */
		LED_GREEN_TOGGLE();
		vTaskDelay( 900 );
	}
}

/*!
 * @brief Application entry point.
 */
int main(void) {
	/* Init board hardware. */
	BOARD_InitPins();

	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	/* Add your code here */

	/* Create RTOS task */
	xTaskCreate(hello_task, "Hello_task", configMINIMAL_STACK_SIZE, NULL, hello_task_PRIORITY, NULL);
	xTaskCreate(init_task, "Init_task", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, NULL);
	xTaskCreate(task_blue, "Task_blue", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, NULL);
	xTaskCreate(task_red, "Task_red", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, NULL);
	xTaskCreate(task_green, "Task_green", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, NULL);
	vTaskStartScheduler();

	for(;;) { /* Infinite loop to avoid leaving the main function */
		__asm("NOP"); /* something to use as a breakpoint stop while looping */
	}
}



