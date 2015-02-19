#ifndef __I2C_H__
#define __I2C_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_I2C
 * @{
 *
 * @file		i2c.h
 * @version		1.0
 * @date		2013-01-31
 * @author		rct1
 *
 * @brief		I2C board support package for the CARME module.
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
#define CARME_I2C_BOARD				I2C2	/**< I2C on board and external	*/
#define CARME_I2C_AUDIO				I2C3	/**< I2C to audio codec			*/

#define CARME_I2C_SPEED				100000	/**< I2C speed in Hz			*/
#define CARME_I2C_ADDR_BOARD		0xA0	/**< I2C Address of master on the
											 *   I2C board bus				*/
#define CARME_I2C_ADDR_AUDIO		0x33	/**< I2C Address of master on the
											 *   I2C audio bus				*/

#define CARME_ERROR_I2C_TIMEOUT		CARME_ERROR_I2C_BASE + 0	/**< I2C timeout */

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
extern void CARME_I2C_Init(I2C_TypeDef *I2Cx);
ERROR_CODES CARME_I2C_Write(I2C_TypeDef *I2Cx, uint8_t addr, uint16_t reg,
		uint8_t twoByte, uint8_t *pdata, uint16_t count);
ERROR_CODES CARME_I2C_Read(I2C_TypeDef *I2Cx, uint8_t addr, uint16_t reg,
		uint8_t twoByte, uint8_t *pdata, uint16_t count);

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __I2C_H__ */
