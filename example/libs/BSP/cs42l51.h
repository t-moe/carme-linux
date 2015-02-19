#ifndef __CS42L51_H__
#define __CS42L51_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_Sound
 * @{
 *
 * @file		cs42l51.h
 * @version		1.0
 * @date		2013-03-11
 * @author		rct1
 *
 * @brief		CS42L51 codec support functions.
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
#define CODEC_I2C					CARME_I2C_AUDIO	/**< I2C bus to codec	*/
#define CODEC_I2S					SPI2			/**< I2S bus to codec	*/
#define CODEC_I2S_EXT				I2S2ext			/**< I2Sext to codec	*/
#define CODEC_I2S_CLK				RCC_APB1Periph_SPI2	/**< I2S RCC		*/
#define CODEC_ADDRESS				0x94	/**< I2C address of codec		*/

#define CHIP_ID						0x01	/**< Cmd Chip ID				*/
#define POWER_CONTROL				0x02	/**< Cmd Power ctrl				*/
#define MIC_POWER_AND_SPEED			0x03	/**< Cmd Mic power and speed	*/
#define INTERFACE_CONTROL			0x04	/**< Cmd Interface ctrl			*/
#define MIC_CONTROL					0x05	/**< Cmd Mic ctrl				*/
#define ADC_CONTROL					0x06	/**< Cmd ADC ctrl				*/
#define ADC_CONFIGURE				0x07	/**< Cmd ADC cfg				*/
#define DAC_OUTPUT_CONTROL			0x08	/**< Cmd DAC output ctrl		*/
#define DAC_CONTROL					0x09	/**< Cmd DAC ctrl				*/
#define ALCA_AND_PGAA_CONTROL		0x0A	/**< Cmd ALCA and PGAA ctrl		*/
#define ALCB_AND_PGAB_CONTROL		0x0B	/**< Cmd ALCB and PGAB ctrl		*/
#define ADCX_ATTENUATOR				0x0D	/**< Cmd ADCx attenuator		*/
#define ADCX_MIXER_VOLUME_CONTROL	0x0F	/**< Cmd ADCx mixer volume ctrl	*/
#define PCMA_MIXER_VOLUME_CONTROL	0x10	/**< Cmd PCMA mixer volume ctrl	*/
#define PCMB_MIXER_VOLUME_CONTROL	0x11	/**< Cmd PCMB mixer volume ctrl	*/
#define BEEP_FREQUENCY_AND_TIMING	0x12	/**< Cmd Beep freq and timing	*/
#define BEEP_OFF_TIME_AND_VOLUME	0x13	/**< Cmd Beep off time and vol	*/
#define BEEP_AND_TONE_CONFIGURATION	0x14	/**< Cmd Beep and tone cfg		*/
#define TONE_CONTROL				0x15	/**< Cmd Tone ctrl				*/
#define AOUTA_VOLUME_CONTROL		0x16	/**< Cmd AOutA vol ctrl			*/
#define AOUTB_VOLUME_CONTROL		0x17	/**< Cmd AOutB vol ctrl			*/
#define PCM_CHANNEL_MIXER			0x18	/**< Cmd PCM channel mixer		*/
#define LIMITER_THRESHOLD			0x19	/**< Cmd Limiter threshold		*/
#define LIMITER_RELEASE				0x1A	/**< Cmd Limiter release		*/
#define LIMITER_ATTACK				0x1B	/**< Cmd Limiter attack			*/
#define ALC_ENABLE_AND_ATTACK		0x1C	/**< Cmd ALC enable and attack	*/
#define ALC_RELEASE					0x1D	/**< Cmd ALC release			*/
#define ALC_THRESHOLD				0x1E	/**< Cmd ALC threshold			*/
#define NOISE_GATE					0x1F	/**< Cmd Noise gate				*/
#define STATUS_REGISTER				0x20	/**< Cmd Status register		*/
#define CHARGE_PUMP_FREQUENCY		0x21	/**< Cmd Charge pump freq		*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
extern uint8_t CS42L51_Init(int8_t Volume);
extern uint8_t CS42L51_Status(void);
extern void CS42L51_VolumeOutCtrl(int8_t Volume);
extern void CS42L51_Mute(uint8_t on);

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
 }
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __CS42L51_H__ */
