#ifndef __LCD_CONF_H__
#define __LCD_CONF_H__
/**
 *****************************************************************************
 * @addtogroup	sGUI
 * @{
 * @addtogroup	Configuration
 * @{
 *
 * @file		lcd_conf_template.h
 * @version		1.0
 * @date		2013-10-03
 * @author		rct1
 *
 * @brief		Simple graphic library configuration.
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

#define TFT320x240
/* #define TFT800x480	*/
/* #define TFT640x480	*/
/* #define TFTCUSTOM	*/

#define TFT_FPS 50ULL

#ifdef TFTCUSTOM
#define TFT_WIDTH				0ULL
#define TFT_HSYNC_BACK_PORCH	0ULL
#define TFT_HSYNC_FRONT_PORCH	0ULL
#define TFT_HSYNC_PULSE			0ULL

#define TFT_HEIGHT				0ULL
#define TFT_VSYNC_BACK_PORCH	0ULL
#define TFT_VSYNC_FRONT_PORCH	0ULL
#define TFT_VSYNC_PULSE			0ULL
#endif

#ifdef TFT320x240
#define TFT_WIDTH				320ULL
#define TFT_HSYNC_BACK_PORCH	40ULL
#define TFT_HSYNC_FRONT_PORCH	20ULL
#define TFT_HSYNC_PULSE			28ULL

#define TFT_HEIGHT				240ULL
#define TFT_VSYNC_BACK_PORCH	17ULL
#define TFT_VSYNC_FRONT_PORCH	4ULL
#define TFT_VSYNC_PULSE			3ULL
#endif

#ifdef TFT800x480
#define TFT_WIDTH				800ULL
#define TFT_HSYNC_BACK_PORCH	30LL
#define TFT_HSYNC_FRONT_PORCH	0ULL
#define TFT_HSYNC_PULSE			0ULL

#define TFT_HEIGHT				480ULL
#define TFT_VSYNC_BACK_PORCH	10ULL
#define TFT_VSYNC_FRONT_PORCH	0ULL
#define TFT_VSYNC_PULSE			0ULL
#endif

#ifdef TFT640x480

#define TFT_WIDTH				640ULL
#define TFT_HSYNC_BACK_PORCH	56ULL
#define TFT_HSYNC_FRONT_PORCH	8ULL
#define TFT_HSYNC_PULSE			96ULL

#define TFT_HEIGHT				480ULL
#define TFT_VSYNC_BACK_PORCH	41ULL
#define TFT_VSYNC_FRONT_PORCH	2ULL
#define TFT_VSYNC_PULSE			2ULL
#endif

#define	TFT_HSYNC_PERIOD		(TFT_HSYNC_PULSE + TFT_HSYNC_BACK_PORCH +	\
       	                		 TFT_WIDTH  + TFT_HSYNC_FRONT_PORCH)
#define	TFT_VSYNC_PERIOD		(TFT_VSYNC_PULSE + TFT_VSYNC_BACK_PORCH +	\
       	                		 TFT_HEIGHT + TFT_VSYNC_FRONT_PORCH)
#define TFT_PCLK				(TFT_HSYNC_PERIOD * TFT_VSYNC_PERIOD *		\
                				 TFT_FPS)
#define LCD_FPR					((TFT_PCLK * 1048576)/100000000)

#define WR_HIGH_BYTE(x)			(x >> 8)
#define WR_LOW_BYTE(x)			(x & 0xFF)

#define USE_16BIT_PMP

/**
 * Overview: Horizontal and vertical display resolution
 *			 (from the glass datasheet).
 */
#define LCD_HOR_RESOLUTION		320ULL
#define LCD_VER_RESOLUTION		240ULL

/**
 * Overview: Horizontal synchronization timing in pixels
 *			 (from the glass datasheet).
 */
#define LCD_HOR_PULSE_WIDTH		64ULL		/* 64 */
#define LCD_HOR_BACK_PORCH		96ULL	  	/* 96	*/
#define LCD_HOR_FRONT_PORCH		48ULL	  	/* 48 */

/**
 * Overview: Vertical synchronization timing in lines
 *			 (from the glass datasheet).
 */
#define LCD_VER_PULSE_WIDTH		2ULL		/* 2 */
#define LCD_VER_BACK_PORCH		34ULL	  	/* 34 */
#define LCD_VER_FRONT_PORCH		11ULL	  	/* 11 */

/**
 * Define horizontal timing
 * HT  - horizontal period
 * HPS - hsync width + front porch
 * HPW - horizontal sync pulse width
 * LPS - horizontal sync pulse location
 */
#define HT	(LCD_HOR_RESOLUTION + LCD_HOR_PULSE_WIDTH + LCD_HOR_BACK_PORCH + LCD_HOR_FRONT_PORCH)
#define HPS (LCD_HOR_PULSE_WIDTH + LCD_HOR_BACK_PORCH)

/**
 * Define vertical timing
 * VT - vertical period
 * VPS - vsync width + front porch
 * VPW - vertical sync pulse width
 * FPS - vertical sync pulse location
 */
#define VT	(LCD_VER_PULSE_WIDTH + LCD_VER_BACK_PORCH + LCD_VER_FRONT_PORCH + LCD_VER_RESOLUTION)
#define VSP (LCD_VER_PULSE_WIDTH + LCD_VER_BACK_PORCH)

/* LCD screen and bitmap image array constants */
#define X_BYTES			40
#define Y_BYTES			30
#define SCRN_LEFT		0
#define SCRN_TOP		0
#define SCRN_RIGHT		LCD_HOR_RESOLUTION-1
#define SCRN_BOTTOM		LCD_VER_RESOLUTION-1

#define CCW				-1
#define CW				1

#define DOTS_PER_CM_X	64
#define DOTS_PER_CM_Y	60

#define INCR			1
#define DECR			-1
#define PREDX			1
#define PREDY			0

/**
 * 1.5 pixels for 1 mm
 * when width[mm] = 2.0mm then width[pixels] = 2*1.5 = 3 pixels
 */
#define COEFF_PIXELS_MM 		1.5

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 */

/**
 * @}
 */

#endif /* __LCD_CONF_H__ */
