/*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
 * All rights reserved.
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

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"

#include "fsl_gpio.h"

static void delay(volatile uint32_t nof) {
  while(nof!=0) {
    __asm("NOP");
    nof--;
  }
}

/*!
 * @brief Application entry point.
 */
int main(void) {
	//gpio_pin_config_t RedLed_config = {kGPIO_DigitalOutput, 0, };
	//gpio_pin_config_t BlueLed_config = {kGPIO_DigitalOutput, 0, };
	/* Init board hardware. */
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	static const gpio_pin_config_t LED_configOutput = {
	  kGPIO_DigitalOutput,  /* use as output pin */
	  1,  /* initial value */
	};

	GPIO_PinInit(GPIOA, 13u, &LED_configOutput); /* mux PTA13 as output */
	GPIO_PinInit(GPIOB, 18u, &LED_configOutput); /* mux PTB18 as output */
	GPIO_PinInit(GPIOB, 19u, &LED_configOutput); /* mux PTB19 as output */
	/* Add your code here */

	//GPIO_PinInit(GPIOB, BOARD_LED_RED_GPIO_PIN, &RedLed_config);
	//GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &BlueLed_config);

	for(;;)
	{
	    GPIO_ClearPinsOutput(GPIOA, 1<<13u); /* blue led on */
	    delay(1000000);
	    GPIO_SetPinsOutput(GPIOA, 1<<13u); /* blue led off */
	    delay(1000000);
	    GPIO_ClearPinsOutput(GPIOB, 1<<18u); /* red led on */
	    delay(1000000);
	    GPIO_SetPinsOutput(GPIOB, 1<<18u); /* red led off */
	    delay(1000000);
	    GPIO_ClearPinsOutput(GPIOB, 1<<19u); /* green led on */
	    delay(1000000);
	    GPIO_SetPinsOutput(GPIOB, 1<<19u); /* green led off */
	    delay(1000000);
	}

	for(;;) { /* Infinite loop to avoid leaving the main function */
		__asm("NOP"); /* something to use as a breakpoint stop while looping */
	}
}
