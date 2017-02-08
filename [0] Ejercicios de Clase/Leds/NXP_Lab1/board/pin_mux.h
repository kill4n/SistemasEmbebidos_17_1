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

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_


/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/* PORTA13 (number 29), J1[10]/D4-TPM1_CH1/D4-LED_BLUE */
#define BOARD_LED_BLUE_GPIO                                                GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_LED_BLUE_PORT                                                PORTA   /*!< PORT device name: PORTA */
#define BOARD_LED_BLUE_GPIO_PIN                                              13U   /*!< PORTA pin index: 13 */
#define BOARD_LED_BLUE_PIN_NAME                                            PTA13   /*!< Pin name */
#define BOARD_LED_BLUE_LABEL                    "J1[10]/D4-TPM1_CH1/D4-LED_BLUE"   /*!< Label */
#define BOARD_LED_BLUE_NAME                                           "LED_BLUE"   /*!< Identifier name */
#define BOARD_LED_BLUE_DIRECTION                        kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB18 (number 41), J2[11]/D11[1]/LED_RED */
#define BOARD_LED_RED_GPIO                                                 GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_RED_PORT                                                 PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_RED_GPIO_PIN                                               18U   /*!< PORTB pin index: 18 */
#define BOARD_LED_RED_PIN_NAME                                             PTB18   /*!< Pin name */
#define BOARD_LED_RED_LABEL                              "J2[11]/D11[1]/LED_RED"   /*!< Label */
#define BOARD_LED_RED_NAME                                             "LED_RED"   /*!< Identifier name */
#define BOARD_LED_RED_DIRECTION                         kPIN_MUX_DirectionOutput   /*!< Direction */

/* PORTB19 (number 42), J2[13]/D11[4]/LED_GREEN */
#define BOARD_LED_GREEN_GPIO                                               GPIOB   /*!< GPIO device name: GPIOB */
#define BOARD_LED_GREEN_PORT                                               PORTB   /*!< PORT device name: PORTB */
#define BOARD_LED_GREEN_GPIO_PIN                                             19U   /*!< PORTB pin index: 19 */
#define BOARD_LED_GREEN_PIN_NAME                                           PTB19   /*!< Pin name */
#define BOARD_LED_GREEN_LABEL                          "J2[13]/D11[4]/LED_GREEN"   /*!< Label */
#define BOARD_LED_GREEN_NAME                                         "LED_GREEN"   /*!< Identifier name */
#define BOARD_LED_GREEN_DIRECTION                       kPIN_MUX_DirectionOutput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDs(void);

/* PORTA4 (number 26), J2[5]/SW1 */
#define BOARD_SW1_GPIO                                                     GPIOA   /*!< GPIO device name: GPIOA */
#define BOARD_SW1_PORT                                                     PORTA   /*!< PORT device name: PORTA */
#define BOARD_SW1_GPIO_PIN                                                    4U   /*!< PORTA pin index: 4 */
#define BOARD_SW1_PIN_NAME                                                  PTA4   /*!< Pin name */
#define BOARD_SW1_LABEL                                              "J2[5]/SW1"   /*!< Label */
#define BOARD_SW1_NAME                                                     "SW1"   /*!< Identifier name */
#define BOARD_SW1_DIRECTION                              kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTC1 (number 44), J3[13]/SW3 */
#define BOARD_SW3_GPIO                                                     GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_SW3_PORT                                                     PORTC   /*!< PORT device name: PORTC */
#define BOARD_SW3_GPIO_PIN                                                    1U   /*!< PORTC pin index: 1 */
#define BOARD_SW3_PIN_NAME                                                  PTC1   /*!< Pin name */
#define BOARD_SW3_LABEL                                             "J3[13]/SW3"   /*!< Label */
#define BOARD_SW3_NAME                                                     "SW3"   /*!< Identifier name */
#define BOARD_SW3_DIRECTION                              kPIN_MUX_DirectionInput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitButtons(void);

/* PORTE29 (number 17), TOUCH_A */
#define BOARD_TOUCH_A_GPIO                                                 GPIOE   /*!< GPIO device name: GPIOE */
#define BOARD_TOUCH_A_PORT                                                 PORTE   /*!< PORT device name: PORTE */
#define BOARD_TOUCH_A_GPIO_PIN                                               29U   /*!< PORTE pin index: 29 */
#define BOARD_TOUCH_A_PIN_NAME                                             PTE29   /*!< Pin name */
#define BOARD_TOUCH_A_LABEL                                            "TOUCH_A"   /*!< Label */
#define BOARD_TOUCH_A_NAME                                             "TOUCH_A"   /*!< Identifier name */
#define BOARD_TOUCH_A_DIRECTION                          kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTE30 (number 18), TOUCH_B */
#define BOARD_TOUCH_B_GPIO                                                 GPIOE   /*!< GPIO device name: GPIOE */
#define BOARD_TOUCH_B_PORT                                                 PORTE   /*!< PORT device name: PORTE */
#define BOARD_TOUCH_B_GPIO_PIN                                               30U   /*!< PORTE pin index: 30 */
#define BOARD_TOUCH_B_PIN_NAME                                             PTE30   /*!< Pin name */
#define BOARD_TOUCH_B_LABEL                                            "TOUCH_B"   /*!< Label */
#define BOARD_TOUCH_B_NAME                                             "TOUCH_B"   /*!< Identifier name */
#define BOARD_TOUCH_B_DIRECTION                          kPIN_MUX_DirectionInput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTSI(void);

/* USB0_DP (number 5), J10[3] */
#define BOARD_USB_DP_PERIPHERAL                                             USB0   /*!< Device name: USB0 */
#define BOARD_USB_DP_SIGNAL                                                   DP   /*!< USB0 signal: DP */
#define BOARD_USB_DP_PIN_NAME                                            USB0_DP   /*!< Pin name */
#define BOARD_USB_DP_LABEL                                              "J10[3]"   /*!< Label */
#define BOARD_USB_DP_NAME                                               "USB_DP"   /*!< Identifier name */

/* USB0_DM (number 6), J10[2] */
#define BOARD_USB_DM_PERIPHERAL                                             USB0   /*!< Device name: USB0 */
#define BOARD_USB_DM_SIGNAL                                                   DM   /*!< USB0 signal: DM */
#define BOARD_USB_DM_PIN_NAME                                            USB0_DM   /*!< Pin name */
#define BOARD_USB_DM_LABEL                                              "J10[2]"   /*!< Label */
#define BOARD_USB_DM_NAME                                               "USB_DM"   /*!< Identifier name */

/* PORTA5 (number 27), J2[4]/D9-TPM0_CH2 */
#define BOARD_TPM0_CH2_PERIPHERAL                                           USB0   /*!< Device name: USB0 */
#define BOARD_TPM0_CH2_SIGNAL                                              CLKIN   /*!< USB0 signal: CLKIN */
#define BOARD_TPM0_CH2_PIN_NAME                                        USB_CLKIN   /*!< Pin name */
#define BOARD_TPM0_CH2_LABEL                                 "J2[4]/D9-TPM0_CH2"   /*!< Label */
#define BOARD_TPM0_CH2_NAME                                           "TPM0_CH2"   /*!< Identifier name */

/* USB_VDD (number 7), P3V3_KL27Z */
#define BOARD_USB_VDD_PERIPHERAL                                            USB0   /*!< Device name: USB0 */
#define BOARD_USB_VDD_SIGNAL                                                 VDD   /*!< USB0 signal: VDD */
#define BOARD_USB_VDD_PIN_NAME                                           USB_VDD   /*!< Pin name */
#define BOARD_USB_VDD_LABEL                                         "P3V3_KL27Z"   /*!< Label */
#define BOARD_USB_VDD_NAME                                             "USB_VDD"   /*!< Identifier name */

/* PORTC0 (number 43), J4[4]/A1-ADC0_SE14 */
#define BOARD_USB_SOF_OUT_PERIPHERAL                                        USB0   /*!< Device name: USB0 */
#define BOARD_USB_SOF_OUT_SIGNAL                                         SOF_OUT   /*!< USB0 signal: SOF_OUT */
#define BOARD_USB_SOF_OUT_PIN_NAME                                   USB_SOF_OUT   /*!< Pin name */
#define BOARD_USB_SOF_OUT_LABEL                             "J4[4]/A1-ADC0_SE14"   /*!< Label */
#define BOARD_USB_SOF_OUT_NAME                                     "USB_SOF_OUT"   /*!< Identifier name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitUSB(void);

/* PORTC3 (number 46), J2[15]/U10[11]/J28[1]/INT1_ACCEL */
#define BOARD_INT1_ACCEL_GPIO                                              GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_INT1_ACCEL_PORT                                              PORTC   /*!< PORT device name: PORTC */
#define BOARD_INT1_ACCEL_GPIO_PIN                                             3U   /*!< PORTC pin index: 3 */
#define BOARD_INT1_ACCEL_PIN_NAME                                           PTC3   /*!< Pin name */
#define BOARD_INT1_ACCEL_LABEL                "J2[15]/U10[11]/J28[1]/INT1_ACCEL"   /*!< Label */
#define BOARD_INT1_ACCEL_NAME                                       "INT1_ACCEL"   /*!< Identifier name */
#define BOARD_INT1_ACCEL_DIRECTION                       kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTC2 (number 45), J3[15]/U10[9]/J27[1]/UART1_TX/INT2_ACCEL */
#define BOARD_INT2_ACCEL_GPIO                                              GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_INT2_ACCEL_PORT                                              PORTC   /*!< PORT device name: PORTC */
#define BOARD_INT2_ACCEL_GPIO_PIN                                             2U   /*!< PORTC pin index: 2 */
#define BOARD_INT2_ACCEL_PIN_NAME                                           PTC2   /*!< Pin name */
#define BOARD_INT2_ACCEL_LABEL        "J3[15]/U10[9]/J27[1]/UART1_TX/INT2_ACCEL"   /*!< Label */
#define BOARD_INT2_ACCEL_NAME                                       "INT2_ACCEL"   /*!< Identifier name */
#define BOARD_INT2_ACCEL_DIRECTION                       kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTD6 (number 63), J2[18]/J24[1]/D14-I2C1_SDA */
#define BOARD_ACCEL_I2C1_SDA_PERIPHERAL                                     I2C1   /*!< Device name: I2C1 */
#define BOARD_ACCEL_I2C1_SDA_SIGNAL                                          SDA   /*!< I2C1 signal: SDA */
#define BOARD_ACCEL_I2C1_SDA_PIN_NAME                                   I2C1_SDA   /*!< Pin name */
#define BOARD_ACCEL_I2C1_SDA_LABEL                  "J2[18]/J24[1]/D14-I2C1_SDA"   /*!< Label */
#define BOARD_ACCEL_I2C1_SDA_NAME                               "ACCEL_I2C1_SDA"   /*!< Identifier name */

/* PORTD7 (number 64), J2[20]/J23[1]/D15-I2C1_SCL */
#define BOARD_ACCEL_I2C1_SCL_PERIPHERAL                                     I2C1   /*!< Device name: I2C1 */
#define BOARD_ACCEL_I2C1_SCL_SIGNAL                                          SCL   /*!< I2C1 signal: SCL */
#define BOARD_ACCEL_I2C1_SCL_PIN_NAME                                   I2C1_SCL   /*!< Pin name */
#define BOARD_ACCEL_I2C1_SCL_LABEL                  "J2[20]/J23[1]/D15-I2C1_SCL"   /*!< Label */
#define BOARD_ACCEL_I2C1_SCL_NAME                               "ACCEL_I2C1_SCL"   /*!< Identifier name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitACCEL_I2C(void);

/* PORTD7 (number 64), J2[20]/J23[1]/D15-I2C1_SCL */
#define BOARD_MAG_I2C1_SCL_PERIPHERAL                                       I2C1   /*!< Device name: I2C1 */
#define BOARD_MAG_I2C1_SCL_SIGNAL                                            SCL   /*!< I2C1 signal: SCL */
#define BOARD_MAG_I2C1_SCL_PIN_NAME                                     I2C1_SCL   /*!< Pin name */
#define BOARD_MAG_I2C1_SCL_LABEL                    "J2[20]/J23[1]/D15-I2C1_SCL"   /*!< Label */
#define BOARD_MAG_I2C1_SCL_NAME                                   "MAG_I2C1_SCL"   /*!< Identifier name */

/* PORTD6 (number 63), J2[18]/J24[1]/D14-I2C1_SDA */
#define BOARD_MAG_I2C1_SDA_PERIPHERAL                                       I2C1   /*!< Device name: I2C1 */
#define BOARD_MAG_I2C1_SDA_SIGNAL                                            SDA   /*!< I2C1 signal: SDA */
#define BOARD_MAG_I2C1_SDA_PIN_NAME                                     I2C1_SDA   /*!< Pin name */
#define BOARD_MAG_I2C1_SDA_LABEL                    "J2[18]/J24[1]/D14-I2C1_SDA"   /*!< Label */
#define BOARD_MAG_I2C1_SDA_NAME                                   "MAG_I2C1_SDA"   /*!< Identifier name */

/* PORTC2 (number 45), J3[15]/U10[9]/J27[1]/UART1_TX/INT2_ACCEL */
#define BOARD_INT1_MAG_GPIO                                                GPIOC   /*!< GPIO device name: GPIOC */
#define BOARD_INT1_MAG_PORT                                                PORTC   /*!< PORT device name: PORTC */
#define BOARD_INT1_MAG_GPIO_PIN                                               2U   /*!< PORTC pin index: 2 */
#define BOARD_INT1_MAG_PIN_NAME                                             PTC2   /*!< Pin name */
#define BOARD_INT1_MAG_LABEL          "J3[15]/U10[9]/J27[1]/UART1_TX/INT2_ACCEL"   /*!< Label */
#define BOARD_INT1_MAG_NAME                                           "INT1_MAG"   /*!< Identifier name */
#define BOARD_INT1_MAG_DIRECTION                         kPIN_MUX_DirectionInput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitMAGNET_I2C(void);

/* PORTA1 (number 23), J1[2]/J25[1]/D0-UART0_RX */
#define BOARD_DEBUG_UART0_RX_PERIPHERAL                                  LPUART0   /*!< Device name: LPUART0 */
#define BOARD_DEBUG_UART0_RX_SIGNAL                                           RX   /*!< LPUART0 signal: RX */
#define BOARD_DEBUG_UART0_RX_PIN_NAME                                 LPUART0_RX   /*!< Pin name */
#define BOARD_DEBUG_UART0_RX_LABEL                    "J1[2]/J25[1]/D0-UART0_RX"   /*!< Label */
#define BOARD_DEBUG_UART0_RX_NAME                               "DEBUG_UART0_RX"   /*!< Identifier name */

/* PORTA2 (number 24), J1[4]/J26[1]/D1-UART0_TX */
#define BOARD_DEBUG_UART0_TX_PERIPHERAL                                  LPUART0   /*!< Device name: LPUART0 */
#define BOARD_DEBUG_UART0_TX_SIGNAL                                           TX   /*!< LPUART0 signal: TX */
#define BOARD_DEBUG_UART0_TX_PIN_NAME                                 LPUART0_TX   /*!< Pin name */
#define BOARD_DEBUG_UART0_TX_LABEL                    "J1[4]/J26[1]/D1-UART0_TX"   /*!< Label */
#define BOARD_DEBUG_UART0_TX_NAME                               "DEBUG_UART0_TX"   /*!< Identifier name */
#define BOARD_DEBUG_UART0_TX_DIRECTION                  kPIN_MUX_DirectionOutput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UART(void);

/* PORTE22 (number 11), THER_A */
#define BOARD_THER_A_GPIO                                                  GPIOE   /*!< GPIO device name: GPIOE */
#define BOARD_THER_A_PORT                                                  PORTE   /*!< PORT device name: PORTE */
#define BOARD_THER_A_GPIO_PIN                                                22U   /*!< PORTE pin index: 22 */
#define BOARD_THER_A_PIN_NAME                                              PTE22   /*!< Pin name */
#define BOARD_THER_A_LABEL                                              "THER_A"   /*!< Label */
#define BOARD_THER_A_NAME                                               "THER_A"   /*!< Identifier name */
#define BOARD_THER_A_DIRECTION                           kPIN_MUX_DirectionInput   /*!< Direction */

/* PORTE23 (number 12), THER_B */
#define BOARD_THER_B_GPIO                                                  GPIOE   /*!< GPIO device name: GPIOE */
#define BOARD_THER_B_PORT                                                  PORTE   /*!< PORT device name: PORTE */
#define BOARD_THER_B_GPIO_PIN                                                23U   /*!< PORTE pin index: 23 */
#define BOARD_THER_B_PIN_NAME                                              PTE23   /*!< Pin name */
#define BOARD_THER_B_LABEL                                              "THER_B"   /*!< Label */
#define BOARD_THER_B_NAME                                               "THER_B"   /*!< Identifier name */
#define BOARD_THER_B_DIRECTION                           kPIN_MUX_DirectionInput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTHER(void);

/* PORTA18 (number 32), EXTAL_32KHZ */
#define BOARD_EXTAL0_PERIPHERAL                                             OSC0   /*!< Device name: OSC0 */
#define BOARD_EXTAL0_SIGNAL                                               EXTAL0   /*!< OSC0 signal: EXTAL0 */
#define BOARD_EXTAL0_PIN_NAME                                             EXTAL0   /*!< Pin name */
#define BOARD_EXTAL0_LABEL                                         "EXTAL_32KHZ"   /*!< Label */
#define BOARD_EXTAL0_NAME                                               "EXTAL0"   /*!< Identifier name */

/* PORTA19 (number 33), XTAL_32KHZ */
#define BOARD_XTAL0_PERIPHERAL                                              OSC0   /*!< Device name: OSC0 */
#define BOARD_XTAL0_SIGNAL                                                 XTAL0   /*!< OSC0 signal: XTAL0 */
#define BOARD_XTAL0_PIN_NAME                                               XTAL0   /*!< Pin name */
#define BOARD_XTAL0_LABEL                                           "XTAL_32KHZ"   /*!< Label */
#define BOARD_XTAL0_NAME                                                 "XTAL0"   /*!< Identifier name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitOSC(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/
