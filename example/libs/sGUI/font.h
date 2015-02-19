#ifndef __FONT_H__
#define __FONT_H__
/**
 *****************************************************************************
 * @addtogroup	sGUI
 * @{
 * @addtogroup	Font
 * @{
 *
 * @file		font.h
 * @version		1.0
 * @date		2013-06-07
 * @author		rct1
 *
 * @brief		Simple graphic library font data.
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
#define FONT_4x6					/**< Use font 4x6						*/
#define FONT_5x7					/**< Use font 5x7						*/
#define FONT_5x7W					/**< Use font 5x7 Wide					*/
#define FONT_5x8					/**< Use font 5x8						*/
#define FONT_6x9					/**< Use font 6x9						*/
#define FONT_6x10					/**< Use font 6x10						*/
#define FONT_6x12					/**< Use font 6x12						*/
#define FONT_6x13					/**< Use font 6x13						*/
#define FONT_6x13B					/**< Use font 6x13 Bold					*/
#define FONT_6x13O					/**< Use font 6x13 Oblique				*/
#define FONT_7x13					/**< Use font 7x13						*/
#define FONT_7x13B					/**< Use font 7x13 Bold					*/
#define FONT_7x13O					/**< Use font 7x13 Oblique				*/
#define FONT_7x14					/**< Use font 7x14						*/
#define FONT_7x14B					/**< Use font 7x14 Bold					*/
#define FONT_8x8					/**< Use font 8x8						*/
#define FONT_8x13					/**< Use font 8x13						*/
#define FONT_8x13B					/**< Use font 8x13 Bold					*/
#define FONT_8x13O					/**< Use font 8x13 Oblique				*/
#define FONT_8x16					/**< Use font 8x16						*/
#define FONT_8x16B					/**< Use font 8x16 Bold					*/
#define FONT_9x15					/**< Use font 9x15						*/
#define FONT_9x15B					/**< Use font 9x15 Bold					*/

#define FONT_MIN_HEIGHT		6		/**< Minimal font width over all fonts	*/
#define FONT_MIN_WIDTH		4		/**< Minimal font height over all fonts	*/
#define FONT_MAX_HEIGHT		16		/**< Maximal font width over all fonts	*/
#define FONT_MAX_WIDTH		9		/**< Maximal font height over all fonts	*/

/*----- Data types ---------------------------------------------------------*/
/**
 * @brief	This struct encapsulates the parameters of a font.
 */
typedef struct _FONT_T {
	uint8_t width;			/**< Font width in pixel		*/
	uint8_t height;			/**< Font height in pixel		*/
	uint8_t datasize;		/**< Font datasize in bytes		*/
	void *data;				/**< Pointer to the data buffer	*/
} FONT_T;

/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/
#ifdef FONT_4x6
/* -Misc-Fixed-Medium-R-Normal--6-60-75-75-C-40-ISO10646-1					*/
extern FONT_T font_4x6;
#endif /* FONT_4x6 */

#ifdef FONT_5x7
/* -Misc-Fixed-Medium-R-Normal--7-70-75-75-C-50-ISO10646-1					*/
extern FONT_T font_5x7;
#endif /* FONT_5x7 */

#ifdef FONT_5x7W
extern FONT_T font_5x7W;
#endif /* FONT_5x7W */

#ifdef FONT_5x8
/* -Misc-Fixed-Medium-R-Normal--8-80-75-75-C-50-ISO10646-1					*/
extern FONT_T font_5x8;
#endif /* FONT_5x8 */

#ifdef FONT_6x9
/* -Misc-Fixed-Medium-R-Normal--9-90-75-75-C-60-ISO10646-1					*/
extern FONT_T font_6x9;
#endif /* FONT_6x9 */

#ifdef FONT_6x10
/* -Misc-Fixed-Medium-R-Normal--10-100-75-75-C-60-ISO10646-1				*/
extern FONT_T font_6x10;
#endif /* FONT_6x10 */

#ifdef FONT_6x12
/* -Misc-Fixed-Medium-R-SemiCondensed--12-110-75-75-C-60-ISO10646-1			*/
extern FONT_T font_6x12;
#endif /* FONT_6x12 */

#ifdef FONT_6x13
/* -Misc-Fixed-Medium-R-SemiCondensed--13-120-75-75-C-60-ISO10646-1			*/
extern FONT_T font_6x13;
#endif /* FONT_6x13 */

#ifdef FONT_6x13B
/* -Misc-Fixed-Bold-R-SemiCondensed--13-120-75-75-C-60-ISO10646-1			*/
extern FONT_T font_6x13B;
#endif /* FONT_6x13B */

#ifdef FONT_6x13O
/* -Misc-Fixed-Medium-O-SemiCondensed--13-120-75-75-C-60-ISO10646-1			*/
extern FONT_T font_6x13O;
#endif /* FONT_6x13O */

#ifdef FONT_7x13
/* -Misc-Fixed-Medium-R-Normal--13-120-75-75-C-70-ISO10646-1				*/
extern FONT_T font_7x13;
#endif /* FONT_7x13 */

#ifdef FONT_7x13B
/* -Misc-Fixed-Bold-R-Normal--13-120-75-75-C-70-ISO10646-1					*/
extern FONT_T font_7x13B;
#endif /* FONT_7x13B */

#ifdef FONT_7x13O
/* -Misc-Fixed-Medium-O-Normal--13-120-75-75-C-70-ISO10646-1				*/
extern FONT_T font_7x13O;
#endif /* FONT_7x13O */

#ifdef FONT_7x14
/* -Misc-Fixed-Medium-R-Normal--14-130-75-75-C-70-ISO10646-1				*/
extern FONT_T font_7x14;
#endif /* FONT_7x14 */

#ifdef FONT_7x14B
/* -Misc-Fixed-Bold-R-Normal--14-130-75-75-C-70-ISO10646-1					*/
extern FONT_T font_7x14B;
#endif /* FONT_7x14B */

#ifdef FONT_8x8
extern FONT_T font_8x8;
#endif /* FONT_8x8 */

#ifdef FONT_8x13
/* -Misc-Fixed-Medium-R-Normal--13-120-75-75-C-80-ISO10646-1				*/
extern FONT_T font_8x13;
#endif /* FONT_8x13 */

#ifdef FONT_8x13B
/* -Misc-Fixed-Bold-R-Normal--13-120-75-75-C-80-ISO10646-1					*/
extern FONT_T font_8x13B;
#endif /* FONT_8x13B */

#ifdef FONT_8x13O
/* -Misc-Fixed-Medium-O-Normal--13-120-75-75-C-80-ISO10646-1				*/
extern FONT_T font_8x13O;
#endif /* FONT_8x13O */

#ifdef FONT_8x16
/* -Sony-Fixed-Medium-R-Normal--16-120-100-100-C-80-ISO8859-1				*/
extern FONT_T font_8x16;
#endif /* FONT_8x16 */

#ifdef FONT_8x16B
extern FONT_T font_8x16B;
#endif /* FONT_8x16B */

#ifdef FONT_9x15
/* -Misc-Fixed-Medium-R-Normal--15-140-75-75-C-90-ISO10646-1				*/
extern FONT_T font_9x15;
#endif /* FONT_9x15 */

#ifdef FONT_9x15B
/* -Misc-Fixed-Bold-R-Normal--15-140-75-75-C-90-ISO10646-1					*/
extern FONT_T font_9x15B;
#endif /* FONT_9x15B */

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

#endif /* __FONT_H__ */
