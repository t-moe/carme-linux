#ifndef __LCD_H__
#define __LCD_H__
/**
 *****************************************************************************
 * @addtogroup	sGUI
 * @{
 * @addtogroup	LCD
 * @{
 *
 * @file		lcd.h
 * @version		1.0
 * @date		2013-06-07
 * @author		rct1
 *
 * @brief		Simple graphic library main functionality.
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
#include "lcd_conf.h"				/* LCD configuration					*/
#include "color.h"					/* Color definitions					*/
#include "font.h"					/* Fonts definitions					*/
#include "lcd_lld.h"				/* Graphic controller communication		*/

/*----- Macros -------------------------------------------------------------*/

/*----- Data types ---------------------------------------------------------*/
/**
 * @brief	Bitmap header
 */
typedef struct _BMP_Header {
	uint16_t Magic;				/**< Magic identifier: "BM"					*/
	uint32_t FileSize;			/**< Size of the BMP file in bytes			*/
	uint16_t Reserved1;			/**< Reserved								*/
	uint16_t Reserved2;			/**< Reserved								*/
	uint32_t DataOffset;		/**< Offset of image data relative to the
								 *	 file's start							*/
	uint32_t HeaderSize;		/**< Size of the header in bytes			*/
	uint32_t Width;				/**< Bitmap's width							*/
	uint32_t Height;			/**< Bitmap's height						*/
	uint16_t Planes;			/**< Number of color planes in the bitmap	*/
	uint16_t BitsPerPixel;		/**< Number of bits per pixel				*/
	uint32_t CompressionType;	/**< Compression type						*/
	uint32_t ImageDataSize;		/**< Size of uncompressed image's data		*/
	uint32_t HPixelsPerMeter;	/**< Horizontal resolution (pixels per
								 *	 meter)									*/
	uint32_t VPixelsPerMeter;	/**< Vertical resolution (pixels per meter)	*/
	uint32_t ColorsUsed;		/**< Number of color indexes in the color
								 *	 table that are actually used by the
								 *	 bitmap									*/
	uint32_t ColorsRequired;	/**< Number of color indexes that are required
								 *	 for displaying the bitmap				*/
} BMP_Header;

/**
 * @brief	Bitmap image
 */
typedef struct _BMP {
	BMP_Header Header;			/**< Bitmap header							*/
	uint8_t *Data;				/**< Pointer to bitmap data					*/
} BMP;

/**
 * @brief	Error codes
 */
typedef enum _BMP_STATUS
{
	BMP_OK = 0,				/**< No error									*/
	BMP_ERROR,				/**< General error								*/
	BMP_OUT_OF_MEMORY,		/**< Could not allocate enough memory to complete
							 *   the operation								*/
	BMP_IO_ERROR,			/**< General input/output error					*/
	BMP_FILE_NOT_FOUND,		/**< File not found								*/
	BMP_FILE_NOT_SUPPORTED,	/**< File is not a supported BMP variant		*/
	BMP_FILE_INVALID,		/**< File is not a BMP image or is invalid		*/
	BMP_INVALID_ARGUMENT,	/**< An argument is invalid or out of range		*/
	BMP_TYPE_MISMATCH,		/**< The requested action is not compatible with
							 *   the BMP's type								*/
	BMP_ERROR_NUM			/**< Other error								*/
} BMP_STATUS;

/*----- Function prototypes ------------------------------------------------*/
/* Text functionality */
void LCD_SetTextColor(LCDCOLOR Color);
void LCD_SetBackColor(LCDCOLOR Color);
void LCD_SetFont(FONT_T *pFont);
FONT_T* LCD_GetFont(void);
uint8_t LCD_GetLineCount(void);
void LCD_ClearLine(uint8_t Line);
void LCD_DisplayCharXY(uint16_t x, uint16_t y, char Ascii);
void LCD_DisplayCharLine(uint8_t Line, uint8_t Column, char Ascii);
void LCD_DisplayStringXY(uint16_t x, uint16_t y, const char *ptr);
void LCD_DisplayStringLine(uint8_t Line, const char *ptr);
void LCD_DisplayStringCenterLine(uint8_t Line, const char *ptr);

/* Log console functionality */
void LCD_Log_AddMsg(char *ptr);
void LCD_Log_Update(void);

/* Simple geometric functionality */
void LCD_DrawLine(uint16_t Xstart, uint16_t Ystart, uint16_t Xstop,
                  uint16_t Ystop, LCDCOLOR Color);
void LCD_DrawRect(uint16_t Xpos, uint16_t Ypos, uint16_t width,
                  uint16_t height, LCDCOLOR Color);
void LCD_DrawRectF(uint16_t Xpos, uint16_t Ypos, uint16_t width,
                   uint16_t height, LCDCOLOR Color);
void LCD_DrawCircle(uint16_t Xpos, uint16_t Ypos, uint16_t Radius,
                    LCDCOLOR Color);
void LCD_DrawCircleF(uint8_t Xpos, uint16_t Ypos, uint16_t Radius,
        		LCDCOLOR Color);

/* Bitmap functionality */
BMP_STATUS LCD_BMP_DrawBitmap(const char *filename, uint16_t Xpos,
                              uint16_t Ypos);
BMP_STATUS LCD_BMP_ReadFile(BMP *bmp, const char *filename);
uint32_t LCD_BMP_GetWidth(BMP *bmp);
uint32_t LCD_BMP_GetHeight(BMP *bmp);
uint16_t LCD_BMP_GetDepth(BMP *bmp);
BMP_STATUS LCD_BMP_GetPixelRGB(BMP *bmp, uint32_t x, uint32_t y, uint8_t *r,
                               uint8_t *g, uint8_t *b);
const char* LCD_BMP_GetErrorDescription(uint8_t errorcode);

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief		Clears the whole LCD.
 * @param[in]	Color	The background color.
 */
static inline void LCD_Clear(LCDCOLOR Color) {
	LCD_FillArea(SCRN_LEFT, SCRN_TOP, SCRN_RIGHT, SCRN_BOTTOM, Color);
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

#endif /* __LCD_H__ */
