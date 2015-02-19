#ifndef __UART_H__
#define __UART_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	USART
 * @{
 *
 * @file		uart.h
 * @version		1.0
 * @date		2013-01-10
 * @author		rct1
 *
 * @brief		The CARME UART Module provides a function to initialize the
 *				GPIOs for the CARME UART ports.
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
#define CARME_UART0		USART1		/**< CARME UART Port 0					*/
#define CARME_UART1		USART3		/**< CARME UART Port 1					*/

/* CARME error codes */
#define CARME_ERROR_UART_NO_DATA	(CARME_ERROR_UART_BASE+0)	/**< No data to receive	*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
extern void CARME_UART_Init(USART_TypeDef *UARTx,
                            USART_InitTypeDef *pUSART_InitStruct);
extern void CARME_UART_GPIO_Init(void);
extern void CARME_UART_SendChar(USART_TypeDef *UARTx, char c);
extern void CARME_UART_SendString(USART_TypeDef *UARTx, char *pStr);
extern ERROR_CODES CARME_UART_ReceiveChar(USART_TypeDef *UARTx, char *pc);
extern ERROR_CODES CARME_UART_ReceiveString(USART_TypeDef *UARTx, char *pc,
                                            uint8_t count);

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __UART_H__ */
