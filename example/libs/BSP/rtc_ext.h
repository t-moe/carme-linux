#ifndef __RTC_EXT_H__
#define __RTC_EXT_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_RTC
 * @{
 * @addtogroup	CARME_RTC_EXT
 * @{
 *
 * @file		rtc_ext.h
 * @version		1.0
 * @date		2012-12-03
 * @author		rct1
 *
 * @brief		Communication interface to use the RTC on the CARME mainboard.
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
#include <rtc.h>					/* CARME RTC definitions				*/

/*----- Macros -------------------------------------------------------------*/
#define CARME_RTC_REG_SEC	0x00	/**< Register address for second		*/
#define CARME_RTC_REG_MIN	0x01	/**< Register address for minute		*/
#define CARME_RTC_REG_HOUR	0x02	/**< Register address for hour			*/
#define CARME_RTC_REG_WDAY	0x03	/**< Register address for day of week	*/
#define CARME_RTC_REG_DAY	0x04	/**< Register address for day			*/
#define CARME_RTC_REG_MONTH	0x05	/**< Register address for month			*/
#define CARME_RTC_REG_YEAR	0x06	/**< Register address for year			*/
#define CARME_RTC_REG_CTRL	0x07	/**< Register address for control		*/

#define CARME_RTC_I2C_ADDR	0xD0	/**< RTC I2C slave address				*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
void CARME_RTC_Ext_Init(void);
void CARME_RTC_Ext_SetTime(CARME_RTC_TIME_t *time);
void CARME_RTC_Ext_GetTime(CARME_RTC_TIME_t *time);

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 * @}
 */

#endif /* __RTC_EXT_H__ */
