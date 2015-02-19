
/***
 * Led Blinker
 *
 * Lektion 1 :)
 *
 * Lang
 * 16.2.2015
 *
 */


#include <stm32f4xx.h>				/* Processor STM32F407IG				*/
#include <carme.h>					/* CARME Module							*/
#include <stdbool.h>
#include <lcd_lld.h>
#include <lcd.h>


volatile unsigned char* LED = (volatile unsigned char*)0x6C000200;
volatile unsigned char* SWITCH = (volatile unsigned char*)0x6C000400;

long i;
unsigned char a;
bool upwards;

int main(void) {


	LCD_Init();



	a=1;
	upwards=true;

	for (;;) {

		if(*SWITCH&0x01 ) {
			a<<=1;
		}

		if(*SWITCH&0x02) {
			a>>=1;
		}

		if(a==0) a=1;

		if(*SWITCH&0x04) {

		   if(upwards) {
			   a<<=1;
			   if(a==0x80) upwards = false;
		   }
		   else  {
			   a>>=1;
			   if(a==0x01)upwards = true;
		   }

		}

		*LED=a;

		if(upwards){
			LCD_Clear(GUI_COLOR_YELLOW);

		} else {
			LCD_Clear(GUI_COLOR_BROWN);

		}
		LCD_DrawCircleF(50,50,15,GUI_COLOR_RED);


		for( i=0; i<1000000; i++);



	}

	return 0U;
}


