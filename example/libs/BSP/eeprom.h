#ifndef __EEPROM_H__
#define __EEPROM_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_EEPROM
 * @{
 *
 * @file		eeprom.h
 * @version		1.0
 * @date		2013-11-27
 * @author		zif1
 *
 * @brief		EEPROM board support package for the CARME module.
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
#include <i2c.h>					/* CARME I2C definitions				*/

/*----- Macros -------------------------------------------------------------*/
#define CARME_ERROR_EEPROM_OVERFLOW	CARME_ERROR_EEPROM_BASE + 0	/**< There are more than 64 Bytes to write,
																	 or the end of the addressrange will be
																	 reached 0x07FF							*/
#define CARME_ERROR_EEPROM_BUSY		CARME_ERROR_EEPROM_BASE + 1	/**< The EEPROM is busy at the moment		*/

#define CARME_EEPROM_WRITE_DELAY	10		/**< Delay on write				*/
#define CARME_EEPROM_READ_DELAY		10		/**< Delay on read				*/

#define CARME_ERROR_EEPROM_OVERFLOW			CARME_ERROR_EEPROM_BASE + 0 ///< The end of the address range will be reached 0x07FF
#define CARME_ERROR_EEPROM_BUSY				CARME_ERROR_EEPROM_BASE + 1 ///< The EEPROM is busy at the moment

#define CARME_EEPROM_I2C_ADDRESS	0xA0	/**< I2C Address of the Eeprom	*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
ERROR_CODES CARME_EEPROM_Write(uint8_t *data, uint8_t nbrOfChar,
                               uint8_t startAddress);
ERROR_CODES CARME_EEPROM_Read(uint8_t *recdata, uint8_t nbrOfChar,
                              uint8_t startAddress);

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __EEPROM_H__ */
