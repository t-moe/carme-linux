/*****************************************************************************
 * Copyright &copy; 2013, Bern University of Applied Sciences.
 * All rights reserved.
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
 *****************************************************************************/
#include <stm32f4xx.h>				// Processor STM32F407IG
#include <carme.h>					// CARME Module
#include <lcd.h>
#include <lcd_lld.h>
#include <color.h>
#include <stm32f4xx_adc.h>

#define LED 	((volatile unsigned char*)(0x6C000200))
#define SWITCH 	((volatile unsigned char*)(0x6C000400))
#define SPEED	500000

uint16_t colors[12] = {
	GUI_COLOR_BLACK,
	GUI_COLOR_WHITE,
	GUI_COLOR_LIGHT_GRAY,
	GUI_COLOR_DARK_GREY,
	GUI_COLOR_RED,
	GUI_COLOR_YELLOW,
	GUI_COLOR_ORANGE,
	GUI_COLOR_BROWN,
	GUI_COLOR_GREEN,
	GUI_COLOR_CYAN,
	GUI_COLOR_BLUE,
	GUI_COLOR_PINK,
	GUI_COLOR_MAGENTA
};

int main(void)
{
	int i = 0, j = 0, m = 0;
	unsigned char *led = LED;

	*led = 0b00000001;

	LCD_Init();
	LCD_Clear(GUI_COLOR_RED);

	while(1){

		for(m = 0; (m <= 12); m++){

			LCD_Clear(colors[m]);

			for(i = 0; i < 7; i++){
				*led<<=1;
				for(j = 0; j < SPEED; j++);
			}

			for(i = 7; i > 0; i--){
				*led>>=1;
				for(j = 0; j < SPEED; j++);
			}
		}
	}

	return 0;
}

