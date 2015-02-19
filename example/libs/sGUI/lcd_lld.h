#ifndef __LCD_LLD_H__
#define __LCD_LLD_H__
/**
 *****************************************************************************
 * @addtogroup	sGUI
 * @{
 * @addtogroup	LCD
 * @{
 *
 * @file		lcd_lld.h
 * @version		1.0
 * @date		2013-10-04
 * @author		rct1
 *
 * @brief		Simple graphic library controller communication interface.
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
#include "ssd1963.h"				/* SSD1963 Graphic-Controller			*/

/*----- Macros -------------------------------------------------------------*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief		Initialize the interface, controller and the display.
 */
static inline void LCD_Init(void) {
	SSD1963_Init();
}

/**
 * @brief		Fill a specified area on the display with the same color.
 * @param[in]	x1		start column from the left.
 * @param[in]	y1		start row from the top.
 * @param[in]	x2		end column from the left.
 * @param[in]	y2		end row from the top.
 * @param[in]	color	Color in format of 16-Bit in the RGB 5-6-5 format.
 */
static inline void LCD_FillArea(uint16_t x1, uint16_t y1, uint16_t x2,
                                uint16_t y2, uint16_t color) {
	SSD1963_FillArea(x1, y1, x2, y2, color);
}

/**
 * @brief		Write an array of data to a specified area on the display.
 * @param[in]	x1		start column from the left.
 * @param[in]	y1		start row from the top.
 * @param[in]	x2		end column from the left.
 * @param[in]	y2		end row from the top.
 * @param[in]	pData	Pointer to the array of pixels in format of 16-Bit
 *						color value in the RGB 5-6-5 format.
 */
static inline void LCD_WriteArea(uint16_t x1, uint16_t y1, uint16_t x2,
                                 uint16_t y2, uint16_t *pData) {
	SSD1963_WriteArea(x1, y1, x2, y2, pData);
}

/**
 * @brief		Write one pixel to the display.
 * @param[in]	x		start column from the left.
 * @param[in]	y		start row from the top.
 * @param[in]	pixel	Color in format of 16-Bit in the RGB 5-6-5 format.
 */
static inline void LCD_WritePixel(uint16_t x, uint16_t y, uint16_t pixel) {
	SSD1963_WritePixel(x, y, pixel);
}

/*----- EOF ----------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 */

/**
 * @}
 */

#endif /* __LCD_LLD_H__ */
