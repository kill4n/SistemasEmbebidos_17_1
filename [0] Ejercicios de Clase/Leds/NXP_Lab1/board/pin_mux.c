/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
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
 *
 */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
PinsProfile:
- !!product 'Pins v2.0'
- !!processor 'MKL27Z64xxx4'
- !!package 'MKL27Z64VLH4'
- !!mcu_data 'ksdk2_0'
- !!processor_version '1.0.1'
- !!board 'FRDM-KL27Z'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

#define PIN13_IDX                       13u   /*!< Pin number for pin 13 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitPins:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '29', peripheral: GPIOA, signal: 'GPIO, 13', pin_signal: PTA13/TPM1_CH1, direction: OUTPUT}
  - {pin_num: '41', peripheral: GPIOB, signal: 'GPIO, 18', pin_signal: PTB18/TPM2_CH0, direction: OUTPUT}
  - {pin_num: '42', peripheral: GPIOB, signal: 'GPIO, 19', pin_signal: PTB19/TPM2_CH1, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN13_IDX, kPORT_MuxAsGpio);         /* PORTA13 (pin 29) is configured as PTA13 */
  PORT_SetPinMux(PORTB, PIN18_IDX, kPORT_MuxAsGpio);         /* PORTB18 (pin 41) is configured as PTB18 */
  PORT_SetPinMux(PORTB, PIN19_IDX, kPORT_MuxAsGpio);         /* PORTB19 (pin 42) is configured as PTB19 */
}


#define PIN13_IDX                       13u   /*!< Pin number for pin 13 in a port */
#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitLEDs:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '29', peripheral: GPIOA, signal: 'GPIO, 13', pin_signal: PTA13/TPM1_CH1, identifier: '', direction: OUTPUT, slew_rate: slow, pull_select: down, pull_enable: disable}
  - {pin_num: '41', peripheral: GPIOB, signal: 'GPIO, 18', pin_signal: PTB18/TPM2_CH0, identifier: '', direction: OUTPUT, slew_rate: slow, pull_select: down, pull_enable: disable}
  - {pin_num: '42', peripheral: GPIOB, signal: 'GPIO, 19', pin_signal: PTB19/TPM2_CH1, identifier: '', direction: OUTPUT, slew_rate: slow, pull_select: down, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitLEDs
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitLEDs(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortB);                           /* Port B Clock Gate Control: Clock enabled */

  const port_pin_config_t porta13_pin29_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA13 */
  };
  PORT_SetPinConfig(PORTA, PIN13_IDX, &porta13_pin29_config); /* PORTA13 (pin 29) is configured as PTA13 */
  const port_pin_config_t portb18_pin41_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB18 */
  };
  PORT_SetPinConfig(PORTB, PIN18_IDX, &portb18_pin41_config); /* PORTB18 (pin 41) is configured as PTB18 */
  const port_pin_config_t portb19_pin42_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_SlowSlewRate,                                      /* Slow slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTB19 */
  };
  PORT_SetPinConfig(PORTB, PIN19_IDX, &portb19_pin42_config); /* PORTB19 (pin 42) is configured as PTB19 */
}


#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN4_IDX                         4u   /*!< Pin number for pin 4 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitButtons:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '26', peripheral: GPIOA, signal: 'GPIO, 4', pin_signal: PTA4/I2C1_SDA/TPM0_CH1/NMI_b, direction: INPUT, slew_rate: fast, pull_select: up, pull_enable: enable,
    passive_filter: disable}
  - {pin_num: '44', peripheral: GPIOC, signal: 'GPIO, 1', pin_signal: ADC0_SE15/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0, direction: INPUT, slew_rate: fast, pull_select: up,
    pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitButtons
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitButtons(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  const port_pin_config_t porta4_pin26_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
  };
  PORT_SetPinConfig(PORTA, PIN4_IDX, &porta4_pin26_config);  /* PORTA4 (pin 26) is configured as PTA4 */
  const port_pin_config_t portc1_pin44_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAsGpio,                                         /* Pin is configured as PTC1 */
  };
  PORT_SetPinConfig(PORTC, PIN1_IDX, &portc1_pin44_config);  /* PORTC1 (pin 44) is configured as PTC1 */
}


#define PCR_PE_DISABLED               0x00u   /*!< Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
#define PCR_PS_UP                     0x01u   /*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_SRE_SLOW                  0x01u   /*!< Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
#define PIN29_IDX                       29u   /*!< Pin number for pin 29 in a port */
#define PIN30_IDX                       30u   /*!< Pin number for pin 30 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitTSI:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '17', peripheral: GPIOE, signal: 'GPIO, 29', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, direction: INPUT, slew_rate: slow, pull_select: up,
    pull_enable: disable}
  - {pin_num: '18', peripheral: GPIOE, signal: 'GPIO, 30', pin_signal: ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1/LPUART1_TX/LPTMR0_ALT1, direction: INPUT, slew_rate: slow,
    pull_select: up, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitTSI
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitTSI(void) {
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTE, PIN29_IDX, kPORT_MuxAsGpio);         /* PORTE29 (pin 17) is configured as PTE29 */
  PORTE->PCR[29] = ((PORTE->PCR[29] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_SLOW)                           /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTE, PIN30_IDX, kPORT_MuxAsGpio);         /* PORTE30 (pin 18) is configured as PTE30 */
  PORTE->PCR[30] = ((PORTE->PCR[30] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_SLOW)                           /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
}


#define PCR_PE_DISABLED               0x00u   /*!< Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
#define PCR_PS_UP                     0x01u   /*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_SRE_FAST                  0x00u   /*!< Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
#define PIN0_IDX                         0u   /*!< Pin number for pin 0 in a port */
#define PIN5_IDX                         5u   /*!< Pin number for pin 5 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitUSB:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '5', peripheral: USB0, signal: DP, pin_signal: USB0_DP}
  - {pin_num: '6', peripheral: USB0, signal: DM, pin_signal: USB0_DM}
  - {pin_num: '27', peripheral: USB0, signal: CLKIN, pin_signal: PTA5/USB_CLKIN/TPM0_CH2, slew_rate: fast, pull_select: up, pull_enable: disable}
  - {pin_num: '7', peripheral: USB0, signal: VDD, pin_signal: USB_VDD}
  - {pin_num: '43', peripheral: USB0, signal: SOF_OUT, pin_signal: ADC0_SE14/PTC0/EXTRG_IN/USB_SOF_OUT/CMP0_OUT, slew_rate: fast, pull_select: up, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitUSB
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitUSB(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN5_IDX, kPORT_MuxAlt2);            /* PORTA5 (pin 27) is configured as USB_CLKIN */
  PORTA->PCR[5] = ((PORTA->PCR[5] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_FAST)                           /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTC, PIN0_IDX, kPORT_MuxAlt4);            /* PORTC0 (pin 43) is configured as USB_SOF_OUT */
  PORTC->PCR[0] = ((PORTC->PCR[0] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_FAST)                           /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
}


#define PCR_DSE_LOW                   0x00u   /*!< Drive Strength Enable: Low drive strength is configured on the corresponding pin, if pin is configured as a digital output. */
#define PCR_PE_DISABLED               0x00u   /*!< Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
#define PCR_PS_UP                     0x01u   /*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_SRE_FAST                  0x00u   /*!< Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN3_IDX                         3u   /*!< Pin number for pin 3 in a port */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitACCEL_I2C:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '46', peripheral: GPIOC, signal: 'GPIO, 3', pin_signal: PTC3/LLWU_P7/SPI1_SCK/LPUART1_RX/TPM0_CH2/CLKOUT, direction: INPUT, drive_strength: low, pull_select: up,
    pull_enable: disable}
  - {pin_num: '45', peripheral: GPIOC, signal: 'GPIO, 2', pin_signal: ADC0_SE11/PTC2/I2C1_SDA/TPM0_CH1, identifier: INT2_ACCEL, direction: INPUT, slew_rate: fast,
    pull_select: up, pull_enable: disable}
  - {pin_num: '63', peripheral: I2C1, signal: SDA, pin_signal: ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/LPUART0_RX/I2C1_SDA/SPI1_MISO/FXIO0_D6, identifier: ACCEL_I2C1_SDA}
  - {pin_num: '64', peripheral: I2C1, signal: SCL, pin_signal: PTD7/SPI1_MISO/LPUART0_TX/I2C1_SCL/SPI1_MOSI/FXIO0_D7, identifier: ACCEL_I2C1_SCL}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitACCEL_I2C
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitACCEL_I2C(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTC, PIN2_IDX, kPORT_MuxAsGpio);          /* PORTC2 (pin 45) is configured as PTC2 */
  PORTC->PCR[2] = ((PORTC->PCR[2] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_FAST)                           /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTC, PIN3_IDX, kPORT_MuxAsGpio);          /* PORTC3 (pin 46) is configured as PTC3 */
  PORTC->PCR[3] = ((PORTC->PCR[3] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_DSE(PCR_DSE_LOW)                            /* Drive Strength Enable: Low drive strength is configured on the corresponding pin, if pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTD, PIN6_IDX, kPORT_MuxAlt4);            /* PORTD6 (pin 63) is configured as I2C1_SDA */
  PORT_SetPinMux(PORTD, PIN7_IDX, kPORT_MuxAlt4);            /* PORTD7 (pin 64) is configured as I2C1_SCL */
}


#define PCR_PE_DISABLED               0x00u   /*!< Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
#define PCR_PS_UP                     0x01u   /*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_SRE_FAST                  0x00u   /*!< Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define PIN6_IDX                         6u   /*!< Pin number for pin 6 in a port */
#define PIN7_IDX                         7u   /*!< Pin number for pin 7 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitMAGNET_I2C:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '64', peripheral: I2C1, signal: SCL, pin_signal: PTD7/SPI1_MISO/LPUART0_TX/I2C1_SCL/SPI1_MOSI/FXIO0_D7, identifier: MAG_I2C1_SCL, slew_rate: fast, drive_strength: low,
    pull_select: up, pull_enable: enable}
  - {pin_num: '63', peripheral: I2C1, signal: SDA, pin_signal: ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/LPUART0_RX/I2C1_SDA/SPI1_MISO/FXIO0_D6, identifier: MAG_I2C1_SDA,
    slew_rate: fast, drive_strength: low, pull_select: up, pull_enable: enable}
  - {pin_num: '45', peripheral: GPIOC, signal: 'GPIO, 2', pin_signal: ADC0_SE11/PTC2/I2C1_SDA/TPM0_CH1, identifier: INT1_MAG, direction: INPUT, slew_rate: fast, pull_select: up,
    pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitMAGNET_I2C
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitMAGNET_I2C(void) {
  CLOCK_EnableClock(kCLOCK_PortC);                           /* Port C Clock Gate Control: Clock enabled */
  CLOCK_EnableClock(kCLOCK_PortD);                           /* Port D Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTC, PIN2_IDX, kPORT_MuxAsGpio);          /* PORTC2 (pin 45) is configured as PTC2 */
  PORTC->PCR[2] = ((PORTC->PCR[2] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_FAST)                           /* Slew Rate Enable: Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
  const port_pin_config_t portd6_pin63_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as I2C1_SDA */
  };
  PORT_SetPinConfig(PORTD, PIN6_IDX, &portd6_pin63_config);  /* PORTD6 (pin 63) is configured as I2C1_SDA */
  const port_pin_config_t portd7_pin64_config = {
    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt4,                                           /* Pin is configured as I2C1_SCL */
  };
  PORT_SetPinConfig(PORTD, PIN7_IDX, &portd7_pin64_config);  /* PORTD7 (pin 64) is configured as I2C1_SCL */
}


#define PIN1_IDX                         1u   /*!< Pin number for pin 1 in a port */
#define PIN2_IDX                         2u   /*!< Pin number for pin 2 in a port */
#define SOPT5_LPUART0RXSRC_LPUART_RX  0x00u   /*!< LPUART0 Receive Data Source Select: LPUART_RX pin */
#define SOPT5_LPUART0TXSRC_LPUART_TX  0x00u   /*!< LPUART0 Transmit Data Source Select: LPUART0_TX pin */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitDEBUG_UART:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '23', peripheral: LPUART0, signal: RX, pin_signal: PTA1/LPUART0_RX/TPM2_CH0, slew_rate: fast, pull_select: down, pull_enable: disable}
  - {pin_num: '24', peripheral: LPUART0, signal: TX, pin_signal: PTA2/LPUART0_TX/TPM2_CH1, direction: OUTPUT, slew_rate: fast, pull_select: down, pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UART
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitDEBUG_UART(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */

  const port_pin_config_t porta1_pin23_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt2,                                           /* Pin is configured as LPUART0_RX */
  };
  PORT_SetPinConfig(PORTA, PIN1_IDX, &porta1_pin23_config);  /* PORTA1 (pin 23) is configured as LPUART0_RX */
  const port_pin_config_t porta2_pin24_config = {
    kPORT_PullDisable,                                       /* Internal pull-up/down resistor is disabled */
    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
    kPORT_LowDriveStrength,                                  /* Low drive strength is configured */
    kPORT_MuxAlt2,                                           /* Pin is configured as LPUART0_TX */
  };
  PORT_SetPinConfig(PORTA, PIN2_IDX, &porta2_pin24_config);  /* PORTA2 (pin 24) is configured as LPUART0_TX */
  SIM->SOPT5 = ((SIM->SOPT5 &
    (~(SIM_SOPT5_LPUART0TXSRC_MASK | SIM_SOPT5_LPUART0RXSRC_MASK))) /* Mask bits to zero which are setting */
      | SIM_SOPT5_LPUART0TXSRC(SOPT5_LPUART0TXSRC_LPUART_TX) /* LPUART0 Transmit Data Source Select: LPUART0_TX pin */
      | SIM_SOPT5_LPUART0RXSRC(SOPT5_LPUART0RXSRC_LPUART_RX) /* LPUART0 Receive Data Source Select: LPUART_RX pin */
    );
}


#define PCR_PE_DISABLED               0x00u   /*!< Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
#define PCR_PS_UP                     0x01u   /*!< Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
#define PCR_SRE_SLOW                  0x01u   /*!< Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
#define PIN22_IDX                       22u   /*!< Pin number for pin 22 in a port */
#define PIN23_IDX                       23u   /*!< Pin number for pin 23 in a port */

/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitTHER:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '11', peripheral: GPIOE, signal: 'GPIO, 22', pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX/FXIO0_D6, direction: INPUT, slew_rate: slow, pull_select: up,
    pull_enable: disable}
  - {pin_num: '12', peripheral: GPIOE, signal: 'GPIO, 23', pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX/FXIO0_D7, direction: INPUT, slew_rate: slow, pull_select: up,
    pull_enable: disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitTHER
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitTHER(void) {
  CLOCK_EnableClock(kCLOCK_PortE);                           /* Port E Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTE, PIN22_IDX, kPORT_MuxAsGpio);         /* PORTE22 (pin 11) is configured as PTE22 */
  PORTE->PCR[22] = ((PORTE->PCR[22] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_SLOW)                           /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
  PORT_SetPinMux(PORTE, PIN23_IDX, kPORT_MuxAsGpio);         /* PORTE23 (pin 12) is configured as PTE23 */
  PORTE->PCR[23] = ((PORTE->PCR[23] &
    (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_SRE_MASK | PORT_PCR_ISF_MASK))) /* Mask bits to zero which are setting */
      | PORT_PCR_PS(PCR_PS_UP)                               /* Pull Select: Internal pullup resistor is enabled on the corresponding pin, if the corresponding PE field is set. */
      | PORT_PCR_PE(PCR_PE_DISABLED)                         /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
      | PORT_PCR_SRE(PCR_SRE_SLOW)                           /* Slew Rate Enable: Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output. */
    );
}


#define PIN18_IDX                       18u   /*!< Pin number for pin 18 in a port */
#define PIN19_IDX                       19u   /*!< Pin number for pin 19 in a port */
/*
 * TEXT BELOW IS USED AS SETTING FOR THE PINS TOOL *****************************
BOARD_InitOSC:
- options: {prefix: BOARD_, coreID: singlecore, enableClock: 'true'}
- pin_list:
  - {pin_num: '32', peripheral: OSC0, signal: EXTAL0, pin_signal: EXTAL0/PTA18/LPUART1_RX/TPM_CLKIN0, slew_rate: no_init, pull_select: no_init, pull_enable: no_init}
  - {pin_num: '33', peripheral: OSC0, signal: XTAL0, pin_signal: XTAL0/PTA19/LPUART1_TX/TPM_CLKIN1/LPTMR0_ALT1, slew_rate: no_init, pull_select: no_init, pull_enable: no_init}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR THE PINS TOOL ***
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitOSC
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitOSC(void) {
  CLOCK_EnableClock(kCLOCK_PortA);                           /* Port A Clock Gate Control: Clock enabled */

  PORT_SetPinMux(PORTA, PIN18_IDX, kPORT_PinDisabledOrAnalog); /* PORTA18 (pin 32) is configured as EXTAL0 */
  PORT_SetPinMux(PORTA, PIN19_IDX, kPORT_PinDisabledOrAnalog); /* PORTA19 (pin 33) is configured as XTAL0 */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
