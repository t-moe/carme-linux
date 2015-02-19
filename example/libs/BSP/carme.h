#ifndef __CARME_H__
#define __CARME_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_Core
 * @{
 *
 * @file		carme.h
 * @version		1.0
 * @date		2013-01-09
 * @author		rct1
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

/*----- Macros -------------------------------------------------------------*/
/* FSMC base addresses for each block */
#define FSMC_NOR_PSRAM_CS_ADDR(n)	(0x60000000 + ((n) - 1)	\
											* 0x4000000)		/**< address formula	*/
#define FSMC_FLASH_BASE				FSMC_NOR_PSRAM_CS_ADDR(1)	/**< External flash			*/
#define FSMC_PSRAM_BASE				FSMC_NOR_PSRAM_CS_ADDR(2)	/**< External ram			*/
#define FSMC_LCD_SSD1963_BASE		FSMC_NOR_PSRAM_CS_ADDR(3)	/**< LCD SSD1963 controller	*/
#define FSMC_IO_BASE				FSMC_NOR_PSRAM_CS_ADDR(4)	/**< External IO			*/
#define FSMC_CARME_EXTENSION1_BASE	(FSMC_IO_BASE + 0x0000000)	/**< CARME Extension 1		*/
#define FSMC_CARME_EXTENSION2_BASE	(FSMC_IO_BASE + 0x1000000)	/**< CARME Extension 2		*/
#define FSMC_CAN_BASE				(FSMC_IO_BASE + 0x2000000)	/**< CAN controller SJA1000	*/

/* AGPIO list */
#define CARME_AGPIO_9				GPIOI, GPIO_Pin_5	/**< Additional GPIO 9				*/
#define CARME_AGPIO_13				GPIOG, GPIO_Pin_15	/**< Additional GPIO 13				*/
#define CARME_AGPIO_21				GPIOI, GPIO_Pin_4	/**< Additional GPIO 21				*/
#define CARME_AGPIO_22				GPIOH, GPIO_Pin_2	/**< Additional GPIO 22				*/
#define CARME_AGPIO_90				GPIOF, GPIO_Pin_11	/**< Additional GPIO 90				*/
#define CARME_AGPIO_91				GPIOF, GPIO_Pin_10	/**< Additional GPIO 91				*/
#define CARME_AGPIO_93				GPIOF, GPIO_Pin_9	/**< Additional GPIO 93				*/
#define CARME_AGPIO_94				GPIOF, GPIO_Pin_8	/**< Additional GPIO 94				*/
#define CARME_AGPIO_96				GPIOF, GPIO_Pin_7	/**< Additional GPIO 96				*/
#define CARME_AGPIO_97				GPIOF, GPIO_Pin_6	/**< Additional GPIO 97				*/
#define CARME_AGPIO_99				GPIOC, GPIO_Pin_7	/**< Additional GPIO 99				*/
#define CARME_AGPIO_101				GPIOB, GPIO_Pin_15	/**< Additional GPIO 101			*/
#define CARME_AGPIO_102				GPIOB, GPIO_Pin_14	/**< Additional GPIO 102			*/
#define CARME_AGPIO_103				GPIOI, GPIO_Pin_0	/**< Additional GPIO 103			*/
#define CARME_AGPIO_105				GPIOB, GPIO_Pin_8	/**< Additional GPIO 105			*/
#define CARME_AGPIO_108				GPIOB, GPIO_Pin_6	/**< Additional GPIO 108			*/
#define CARME_AGPIO_115				GPIOB, GPIO_Pin_2	/**< Additional GPIO 115			*/
#define CARME_AGPIO_116				GPIOB, GPIO_Pin_1	/**< Additional GPIO 116			*/
#define CARME_LED_GREEN				GPIOI, GPIO_Pin_6	/**< Green LED on module			*/
#define CARME_LED_RED				GPIOI, GPIO_Pin_7	/**< Red LED on module				*/

/* AGPIO Pin list */
#define CARME_AGPIO_PIN_116			((uint32_t)0x00001)	/**< Additional GPIO 116 Pin		*/
#define CARME_AGPIO_PIN_115			((uint32_t)0x00002)	/**< Additional GPIO 115 Pin		*/
#define CARME_AGPIO_PIN_108			((uint32_t)0x00004)	/**< Additional GPIO 108 Pin		*/
#define CARME_AGPIO_PIN_105			((uint32_t)0x00008)	/**< Additional GPIO 105 Pin		*/
#define CARME_AGPIO_PIN_103			((uint32_t)0x00010)	/**< Additional GPIO 103 Pin		*/
#define CARME_AGPIO_PIN_102			((uint32_t)0x00020)	/**< Additional GPIO 102 Pin		*/
#define CARME_AGPIO_PIN_101			((uint32_t)0x00040)	/**< Additional GPIO 101 Pin		*/
#define CARME_AGPIO_PIN_99			((uint32_t)0x00080)	/**< Additional GPIO 99 Pin			*/
#define CARME_AGPIO_PIN_97			((uint32_t)0x00100)	/**< Additional GPIO 97 Pin			*/
#define CARME_AGPIO_PIN_96			((uint32_t)0x00200)	/**< Additional GPIO 96 Pin			*/
#define CARME_AGPIO_PIN_94			((uint32_t)0x00400)	/**< Additional GPIO 94 Pin			*/
#define CARME_AGPIO_PIN_93			((uint32_t)0x00800)	/**< Additional GPIO 93 Pin			*/
#define CARME_AGPIO_PIN_91			((uint32_t)0x01000)	/**< Additional GPIO 91 Pin			*/
#define CARME_AGPIO_PIN_90			((uint32_t)0x02000)	/**< Additional GPIO 90 Pin			*/
#define CARME_AGPIO_PIN_22			((uint32_t)0x04000)	/**< Additional GPIO 22 Pin			*/
#define CARME_AGPIO_PIN_21			((uint32_t)0x08000)	/**< Additional GPIO 21 Pin			*/
#define CARME_AGPIO_PIN_13			((uint32_t)0x10000)	/**< Additional GPIO 13 Pin			*/
#define CARME_AGPIO_PIN_9			((uint32_t)0x20000)	/**< Additional GPIO 9 Pin			*/
#define CARME_LED_PIN_GREEN			((uint32_t)0x40000)	/**< Green LED Pin					*/
#define CARME_LED_PIN_RED			((uint32_t)0x80000)	/**< Red LED Pin					*/

/* CARME error codes */
#define CARME_NO_ERROR				0x0				/**< No error			*/
#define CARME_ERROR_IO1_BASE		0x10			/**< CARME IO1 errors	*/
#define CARME_ERROR_IO2_BASE		0x20			/**< CARME IO2 errors	*/
#define CARME_ERROR_UART_BASE		0x30			/**< UART errors		*/
#define CARME_ERROR_CAN_BASE		0x40			/**< CAN errors			*/
#define CARME_ERROR_I2C_BASE		0x60			/**< I2C errors			*/
#define CARME_ERROR_AUDIO_BASE		0x80			/**< Audio codec errors	*/
#define CARME_ERROR_ETH_BASE		0xA0			/**< Ethernet errors	*/
#define CARME_ERROR_USB_BASE		0xC0			/**< USB errors			*/
#define CARME_ERROR_EEPROM_BASE		0xE0			/**< EEPROM errors		*/

/**
 * @brief	Get GPIO_PinSourcex from GPIO_Pin_x.
 */
#define CARME_GPIO_PIN_TO_SOURCE(GPIO_PIN)	(								\
		((GPIO_PIN) & GPIO_Pin_0) ? GPIO_PinSource0 :	/* bit 0 is set? */	\
		((GPIO_PIN) & GPIO_Pin_1) ? GPIO_PinSource1 :	/* bit 1 is set? */	\
		((GPIO_PIN) & GPIO_Pin_2) ? GPIO_PinSource2 :	/* bit 2 is set? */	\
		((GPIO_PIN) & GPIO_Pin_3) ? GPIO_PinSource3 :	/* bit 3 is set? */	\
		((GPIO_PIN) & GPIO_Pin_4) ? GPIO_PinSource4 :	/* bit 4 is set? */	\
		((GPIO_PIN) & GPIO_Pin_5) ? GPIO_PinSource5 :	/* bit 5 is set? */	\
		((GPIO_PIN) & GPIO_Pin_6) ? GPIO_PinSource6 :	/* bit 6 is set? */	\
		((GPIO_PIN) & GPIO_Pin_7) ? GPIO_PinSource7 :	/* bit 7 is set? */	\
		((GPIO_PIN) & GPIO_Pin_8) ? GPIO_PinSource8 :	/* bit 8 is set? */	\
		((GPIO_PIN) & GPIO_Pin_9) ? GPIO_PinSource9 :	/* bit 9 is set? */	\
		((GPIO_PIN) & GPIO_Pin_10) ? GPIO_PinSource10 :	/* bit 10 is set? */\
		((GPIO_PIN) & GPIO_Pin_11) ? GPIO_PinSource11 :	/* bit 11 is set? */\
		((GPIO_PIN) & GPIO_Pin_12) ? GPIO_PinSource12 :	/* bit 12 is set? */\
		((GPIO_PIN) & GPIO_Pin_13) ? GPIO_PinSource13 :	/* bit 13 is set? */\
		((GPIO_PIN) & GPIO_Pin_14) ? GPIO_PinSource14 :	/* bit 14 is set? */\
		((GPIO_PIN) & GPIO_Pin_15) ? GPIO_PinSource15 :	/* bit 15 is set? */\
		-1)												/* no bits are set */

/**
 * @brief	Get EXTI_PortSourceGPIOx from GPIOx.
 */
#define CARME_GPIO_TO_EXTIPORTSOURCE(GPIO_PORT)	(							\
		(GPIO_PORT == GPIOA) ? EXTI_PortSourceGPIOA :	/* Port A? */		\
		(GPIO_PORT == GPIOB) ? EXTI_PortSourceGPIOB :	/* Port B? */		\
		(GPIO_PORT == GPIOC) ? EXTI_PortSourceGPIOC :	/* Port C? */		\
		(GPIO_PORT == GPIOD) ? EXTI_PortSourceGPIOD :	/* Port D? */		\
		(GPIO_PORT == GPIOE) ? EXTI_PortSourceGPIOE :	/* Port E? */		\
		(GPIO_PORT == GPIOF) ? EXTI_PortSourceGPIOF :	/* Port F? */		\
		(GPIO_PORT == GPIOG) ? EXTI_PortSourceGPIOG :	/* Port G? */		\
		(GPIO_PORT == GPIOH) ? EXTI_PortSourceGPIOH :	/* Port H? */		\
		(GPIO_PORT == GPIOI) ? EXTI_PortSourceGPIOI :	/* Port I? */		\
		-1)												/* no port is set */

/**
 * @brief	Get EXTI_PinSourcex from GPIO_Pin_x.
 */
#define CARME_GPIO_TO_EXTIPINSOURCE(GPIO_PIN)	(							\
		((GPIO_PIN) & GPIO_Pin_0) ? EXTI_PinSource0 :	/* bit 0 is set? */	\
		((GPIO_PIN) & GPIO_Pin_1) ? EXTI_PinSource1 :	/* bit 1 is set? */	\
		((GPIO_PIN) & GPIO_Pin_2) ? EXTI_PinSource2 :	/* bit 2 is set? */	\
		((GPIO_PIN) & GPIO_Pin_3) ? EXTI_PinSource3 :	/* bit 3 is set? */	\
		((GPIO_PIN) & GPIO_Pin_4) ? EXTI_PinSource4 :	/* bit 4 is set? */	\
		((GPIO_PIN) & GPIO_Pin_5) ? EXTI_PinSource5 :	/* bit 5 is set? */	\
		((GPIO_PIN) & GPIO_Pin_6) ? EXTI_PinSource6 :	/* bit 6 is set? */	\
		((GPIO_PIN) & GPIO_Pin_7) ? EXTI_PinSource7 :	/* bit 7 is set? */	\
		((GPIO_PIN) & GPIO_Pin_8) ? EXTI_PinSource8 :	/* bit 8 is set? */	\
		((GPIO_PIN) & GPIO_Pin_9) ? EXTI_PinSource9 :	/* bit 9 is set? */	\
		((GPIO_PIN) & GPIO_Pin_10) ? EXTI_PinSource10 :	/* bit 10 is set? */\
		((GPIO_PIN) & GPIO_Pin_11) ? EXTI_PinSource11 :	/* bit 11 is set? */\
		((GPIO_PIN) & GPIO_Pin_12) ? EXTI_PinSource12 :	/* bit 12 is set? */\
		((GPIO_PIN) & GPIO_Pin_13) ? EXTI_PinSource13 :	/* bit 13 is set? */\
		((GPIO_PIN) & GPIO_Pin_14) ? EXTI_PinSource14 :	/* bit 14 is set? */\
		((GPIO_PIN) & GPIO_Pin_15) ? EXTI_PinSource15 :	/* bit 15 is set? */\
		-1)												/* no bits are set */

/**
 * @brief	Get EXTI_Linex from GPIO_Pin_x.
 */
#define CARME_GPIO_TO_EXTILINE(GPIO_PIN)	(								\
		((GPIO_PIN) & GPIO_Pin_0) ? EXTI_Line0 :		/* bit 0 is set? */	\
		((GPIO_PIN) & GPIO_Pin_1) ? EXTI_Line1 :		/* bit 1 is set? */	\
		((GPIO_PIN) & GPIO_Pin_2) ? EXTI_Line2 :		/* bit 2 is set? */	\
		((GPIO_PIN) & GPIO_Pin_3) ? EXTI_Line3 :		/* bit 3 is set? */	\
		((GPIO_PIN) & GPIO_Pin_4) ? EXTI_Line4 :		/* bit 4 is set? */	\
		((GPIO_PIN) & GPIO_Pin_5) ? EXTI_Line5 :		/* bit 5 is set? */	\
		((GPIO_PIN) & GPIO_Pin_6) ? EXTI_Line6 :		/* bit 6 is set? */	\
		((GPIO_PIN) & GPIO_Pin_7) ? EXTI_Line7 :		/* bit 7 is set? */	\
		((GPIO_PIN) & GPIO_Pin_8) ? EXTI_Line8 :		/* bit 8 is set? */	\
		((GPIO_PIN) & GPIO_Pin_9) ? EXTI_Line9 :		/* bit 9 is set? */	\
		((GPIO_PIN) & GPIO_Pin_10) ? EXTI_Line10 :		/* bit 10 is set? */\
		((GPIO_PIN) & GPIO_Pin_11) ? EXTI_Line11 :		/* bit 11 is set? */\
		((GPIO_PIN) & GPIO_Pin_12) ? EXTI_Line12 :		/* bit 12 is set? */\
		((GPIO_PIN) & GPIO_Pin_13) ? EXTI_Line13 :		/* bit 13 is set? */\
		((GPIO_PIN) & GPIO_Pin_14) ? EXTI_Line14 :		/* bit 14 is set? */\
		((GPIO_PIN) & GPIO_Pin_15) ? EXTI_Line15 :		/* bit 15 is set? */\
		-1)												/* no bits are set */

#ifndef max
/**
 * @brief	Get the maximum of two numbers.
 */
#define max(a, b)	( ((a) > (b)) ? (a) : (b) )
#endif

#ifndef min
/**
 * @brief	Get the minimum of two numbers.
 */
#define min(a, b)	( ((a) < (b)) ? (a) : (b) )
#endif

/*----- Data types ---------------------------------------------------------*/
/**
 * @brief	CARME port and pin association structure.
 */
typedef struct _CARME_Port_Pin_t {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
	GPIOMode_TypeDef GPIO_Mode;
	uint8_t GPIO_AF;
} CARME_Port_Pin_t;

/**
 * @brief	Error variable
 */
typedef uint8_t ERROR_CODES;

/*----- Function prototypes ------------------------------------------------*/
extern void CARME_Init(void);
extern void CARME_GPIO_Init(CARME_Port_Pin_t *pPortPinAssociation,
                            GPIO_InitTypeDef *pGPIO_InitStruct, uint8_t size);
extern void CARME_AGPIO_Set(uint32_t write, uint32_t mask);
extern void CARME_AGPIO_Get(uint32_t *pStatus);
extern void CARME_LED_Green_Set(void);
extern void CARME_LED_Green_Reset(void);
extern void CARME_LED_Red_Set(void);
extern void CARME_LED_Red_Reset(void);

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __CARME_H__ */
