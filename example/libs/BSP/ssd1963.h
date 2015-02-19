#ifndef __SSD1963_H__
#define __SSD1963_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_LCD
 * @{
 *
 * @file		ssd1963.h
 * @version		1.0
 * @date		2012-10-10
 * @author		aom1
 *
 * @brief		Driver for the SSD1963 Graphic-Controller.
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
#include <stdint.h>					/* Standard integer formats				*/
#include "ssd1963_lld.h"			/* SSD1963 Graphic-Controller driver	*/
#include "ssd1963_cmd.h"			/* SSD1963 Graphic-Controller commands	*/

/*----- Macros -------------------------------------------------------------*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
void SSD1963_Init(void);
void SSD1963_WritePixel(uint16_t x, uint16_t y, uint16_t color);
uint16_t SSD1963_ReadPixel(uint16_t x, uint16_t y);
void SSD1963_SetArea(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void SSD1963_FillArea(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                      uint16_t color);
void SSD1963_WriteArea(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,
                       uint16_t *pData);
void SSD1963_SetTearingCfg(uint8_t state, uint8_t mode);
void SSD1963_GetDeviceDescriptorBlock(uint16_t *ddb);

/* Low level driver */
void SSD1963_LLD_Init(void);
void SSD1963_WriteCommand(uint16_t cmd);
void SSD1963_WriteData(uint16_t data);
uint16_t SSD1963_ReadData(void);

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief		SSD1963 enters sleep mode.\n
 * Host must wait 5mS after sending before sending next command.
 */
static inline void SSD1963_EnterSleepMode(void) {
	SSD1963_WriteCommand(CMD_ENT_SLEEP);
}

/**
 * @brief		SSD1963 exit sleep mode.
 */
static inline void SSD1963_ExitSleepMode(void) {
	SSD1963_WriteCommand(CMD_EXIT_SLEEP);
}

/**
 * @brief		SSD1963 changes the display state to OFF state.
 */
static inline void SSD1963_DisplayOff(void) {
	SSD1963_WriteCommand(CMD_BLANK_DISPLAY);
}

/**
 * @brief		SSD1963 changes the display state to ON state.
 */
static inline void SSD1963_DisplayOn(void) {
	SSD1963_WriteCommand(CMD_ON_DISPLAY);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __SSD1963_H__ */
