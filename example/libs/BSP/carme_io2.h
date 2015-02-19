#ifndef __CARME_IO2_H__
#define __CARME_IO2_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_IO2
 * @{
 *
 * @file		carme_io2.h
 * @version		1.0
 * @date		2013-01-09
 * @author		rct1
 *
 * @brief		CARME IO2 extension module board support package.
 *
 *****************************************************************************
 * @copyright
 * @{
 *
 * This software can be used by students and other personal of the Bern
 * University of Applied Sciences under the terms of the MIT license.
 * For other persons this software is under the terms of the GNU General
 * Public License version 2.
 *
 * Copyright &copy; 2013, Bern University of Applied Sciences.
 * All rights reserved.
 *
 *
 * ##### MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 * ##### GNU GENERAL PUBLIC LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.
 *
 * @}
 *****************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----- Header-Files -------------------------------------------------------*/
#include <stm32f4xx.h>				/* Processor STM32F407IG				*/
#include <carme.h>					/* CARME Module							*/

/*----- Macros -------------------------------------------------------------*/
#define CARME_ERROR_IO2_NO_DATA				(CARME_ERROR_IO2_BASE + 0)	/**< No data available		*/
#define CARME_ERROR_IO2_PWM_WRONG_CHANNEL	(CARME_ERROR_IO2_BASE + 1)	/**< Wrong PWM channel		*/

#define CARME_IO2_GPIO_OUT_PIN0		0x1		/**< GPIO Out Pin 0				*/
#define CARME_IO2_GPIO_OUT_PIN1		0x2		/**< GPIO Out Pin 1				*/
#define CARME_IO2_GPIO_OUT_PIN2		0x4		/**< GPIO Out Pin 2				*/

/* LTC2622 DAC Commands */
#define CARME_IO2_LTC2622_CMD_W		0x00	/**< Write to Input Register n							*/
#define CARME_IO2_LTC2622_CMD_Un	0x01	/**< Update (Power Up) DAC Register n					*/
#define CARME_IO2_LTC2622_CMD_WUa	0x02	/**< Write to Input registers, Update (Power Up) All n	*/
#define CARME_IO2_LTC2622_CMD_WUn	0x03	/**< Write to and Update (Power Up) n					*/
#define CARME_IO2_LTC2622_CMD_Off	0x04	/**< Power Down n										*/
#define CARME_IO2_LTC2622_CMD_None	0xFF	/**< No Operation										*/

/* LTC2622 DAC Addresses */
#define CARME_IO2_LTC2622_ADDR_A	0x00	/**< DAC A						*/
#define CARME_IO2_LTC2622_ADDR_B	0x01	/**< DAC B						*/
#define CARME_IO2_LTC2622_ADDR_ALL	0xFF	/**< All DACs					*/

/*----- Data types ---------------------------------------------------------*/
/**
 * @brief	ADC port names.
 */
typedef enum _CARME_IO2_ADC_CHANNEL {
	CARME_IO2_ADC_PORT0 = 0,			/**< Port 0, Poti					*/
	CARME_IO2_ADC_PORT1 = 1,			/**< Port 1							*/
	CARME_IO2_ADC_PORT2 = 2				/**< Port 2							*/
} CARME_IO2_ADC_CHANNEL;

/**
 * @brief	GPIO Out mode definitions.
 */
typedef enum _CARME_IO2_GPIO_OUT_MODE {
	CARME_IO2_GPIO_OUT_MODE_GPIO = GPIO_Mode_OUT,	/**< GPIO Out mode as
													 *	 GPIO				*/
	CARME_IO2_GPIO_OUT_MODE_PWM = GPIO_Mode_AF		/**< GPIO Out mode as
													 *	 PWM				*/
} CARME_IO2_GPIO_OUT_MODE;

/**
 * @brief	DAC port names.
 */
typedef enum _CARME_IO2_DAC_CHANNEL {
	CARME_IO2_DAC_OUT0 = CARME_IO2_LTC2622_ADDR_A,	/**< DAC Out 0			*/
	CARME_IO2_DAC_OUT1 = CARME_IO2_LTC2622_ADDR_B,	/**< DAC Out 1			*/
	CARME_IO2_DAC_OUT_BOTH = CARME_IO2_LTC2622_ADDR_ALL	/**< DAC Out both	*/
} CARME_IO2_DAC_CHANNEL;

/**
 * @brief	ADC port names.
 */
typedef enum _CARME_IO2_SPI_CHANNEL {
	CARME_IO2_nPSC0 = 0,				/**< DAC, SPI0						*/
	CARME_IO2_nPSC1 = 1					/**< External, SPI1					*/
} CARME_IO2_SPI_CHANNEL;

/**
 * @brief	PWM port names.
 */
typedef enum _CARME_IO2_PWM_CHANNEL {
	CARME_IO2_PWM0,						/**< PWM0							*/
	CARME_IO2_PWM1,						/**< PWM1							*/
	CARME_IO2_PWM2,						/**< PWM2							*/
	CARME_IO2_PWM3						/**< PWM3, Motor Out				*/
} CARME_IO2_PWM_CHANNEL;

/**
 * @brief	DC motor direction.
 */
typedef enum _CARME_IO2_PWM_PHASE {
	CARME_IO2_PWM_NORMAL_DIRECTION,		/**< Forward						*/
	CARME_IO2_PWM_OPPOSITE_DIRECTION	/**< Backward						*/
} CARME_IO2_PWM_PHASE;

/*----- Function prototypes ------------------------------------------------*/
extern void CARME_IO2_Init(void);
extern void CARME_IO2_GPIO_OUT_Settings(uint8_t pin,
                                        CARME_IO2_GPIO_OUT_MODE mode);
extern void CARME_IO2_ADC_Get(CARME_IO2_ADC_CHANNEL channel, uint16_t *pValue);
extern void CARME_IO2_DAC_Set(CARME_IO2_DAC_CHANNEL channel, uint16_t Value);
extern void CARME_IO2_SPI_Select(CARME_IO2_SPI_CHANNEL select);
extern void CARME_IO2_SPI_CS_Out(uint8_t cs);
extern void CARME_IO2_SPI_Send(uint16_t data);
extern void CARME_IO2_SPI_Receive(uint16_t *pValue);
extern void CARME_IO2_PWM_Settings(
        TIM_TimeBaseInitTypeDef *pTIM_TimeBaseStruct);
extern ERROR_CODES CARME_IO2_PWM_Set(CARME_IO2_PWM_CHANNEL channel,
                                     uint16_t value);
extern void CARME_IO2_PWM_Phase(CARME_IO2_PWM_PHASE dir);
extern void CARME_IO2_GPIO_IN_Get(uint8_t *pStatus);
extern void CARME_IO2_GPIO_OUT_Set(uint8_t Status);
extern void CARME_IO2_OPTO_IN_Get(uint8_t *pStatus);
extern void CARME_IO2_OPTO_OUT_Set(uint8_t Status);

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __CARME_IO2_H__ */
