#ifndef __RTC_H__
#define __RTC_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_RTC
 * @{
 *
 * @file		rtc.h
 * @version		1.0
 * @date		2012-10-24
 * @author		rct1
 *
 * @brief		RTC interface.\n
 *				Communication interface to use the RTC from the CARME-M4.
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
/* error codes */
#define	CARME_ERROR_RTC		CARME_ERROR_RTC_BASE + 0	/**< Common RTC error		*/

#ifndef CARME_RTC_USE_WAKEUP_ISR
#define CARME_RTC_USE_WAKEUP_ISR	0	/**< Disable wakeup interrupt		*/
#endif

/*----- Data types ---------------------------------------------------------*/
/**
 * @brief	Structure to store a full date and time.
 */
typedef struct _CARME_RTC_TIME_t {
	uint8_t sec;					/**< Seconds:			range 0-59		*/
	uint8_t min;					/**< Minutes:			range 0-59		*/
	uint8_t hour;					/**< Hours:				range 0-23		*/
	uint8_t day;					/**< Day of Month:		range 1-31		*/
	uint8_t month;					/**< Month:				range 1-12		*/
	uint8_t year;					/**< Year since 2000:	range 0-99		*/
	uint8_t wday;					/**< Day of the week:	range 1-7		*/
} CARME_RTC_TIME_t;

#if CARME_RTC_USE_WAKEUP_ISR==1
/**
 * @brief	Structure to store a full date and time.
 */
typedef enum _CARME_RTC_WAKEUP_t {
	CARME_RTC_WAKEUP_STOP =0,		/**< Wakeup Interrupt disable			*/
	CARME_RTC_WAKEUP_30s,			/**< Timer with 30sec interval			*/
	CARME_RTC_WAKEUP_10s,			/**< Timer with 10sec interval			*/
	CARME_RTC_WAKEUP_5s,			/**< Timer with 5sec interval			*/
	CARME_RTC_WAKEUP_1s,			/**< Timer with 1sec interval			*/
	CARME_RTC_WAKEUP_500ms,			/**< Timer with 500msec interval		*/
	CARME_RTC_WAKEUP_250ms,			/**< Timer with 250msec interval		*/
	CARME_RTC_WAKEUP_125ms			/**< Timer with 125msec interval		*/
} CARME_RTC_WAKEUP_t;
#endif

/*----- Function prototypes ------------------------------------------------*/
void CARME_RTC_Init(void);
ERROR_CODES CARME_RTC_SetTime(CARME_RTC_TIME_t *time);
void CARME_RTC_GetTime(CARME_RTC_TIME_t *time);
uint32_t get_fattime(void);

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __RTC_H__ */
