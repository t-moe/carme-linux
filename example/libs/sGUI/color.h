#ifndef __COLOR_H__
#define __COLOR_H__
/**
 *****************************************************************************
 * @addtogroup	sGUI
 * @{
 * @addtogroup	Color
 * @{
 *
 * @file		color.h
 * @version		1.0
 * @date		2013-10-03
 * @author		rct1
 *
 * @brief		Simple graphic library color definitions.
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

/*----- Macros -------------------------------------------------------------*/
#define GUI_COLOR_BLACK			0x0000		/**< Black screen color			*/
#define GUI_COLOR_WHITE			0xFFFF		/**< White screen color			*/
#define GUI_COLOR_LIGHT_GRAY	0xBDF7		/**< Light Gray screen color	*/
#define GUI_COLOR_DARK_GREY		0x7BEF		/**< Dark Gray screen color		*/
#define GUI_COLOR_RED			0xF800		/**< Red screen color			*/
#define GUI_COLOR_YELLOW		0xFFE0		/**< Yellow screen color		*/
#define GUI_COLOR_ORANGE		0xFBE0		/**< Orange screen color		*/
#define GUI_COLOR_BROWN			0x79E0		/**< Brown screen color			*/
#define GUI_COLOR_GREEN			0x07E0		/**< Green screen color			*/
#define GUI_COLOR_CYAN			0x07FF		/**< Cyan screen color			*/
#define GUI_COLOR_BLUE			0x001F		/**< Blue screen color			*/
#define GUI_COLOR_PINK			0xF81F		/**< Pink screen color			*/
#define GUI_COLOR_MAGENTA		0xF81F		/**< Magenta screen color		*/

/*----- Data types ---------------------------------------------------------*/
/**
 * @brief	Data type for a color definition.
 */
typedef uint16_t LCDCOLOR;

/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/

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

#endif /* __COLOR_H__ */
