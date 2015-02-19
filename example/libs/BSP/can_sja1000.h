#ifndef __CAN_SJA1000_H__
#define __CAN_SJA1000_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_CAN_EXT
 * @{
 * @addtogroup	CARME_CAN_EXT_Ctrl
 * @{
 *
 * @file		can_sja1000.h
 * @version		1.0
 * @date		2007-04-13
 * @author		M. Muehlemann
 *
 * @brief		SJA1000 specific declarations.
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
#include <carme.h>					/* CARME Module							*/

/*----- Macros -------------------------------------------------------------*/
/*****************************************************************************
 * 								REGISTERS (PeliCAN Mode)
 ****************************************************************************/
#define	SJA1000_MOD			0x00	/**< mode register						*/
#define	SJA1000_CMR			0x01	/**< command register					*/
#define	SJA1000_SR			0x02	/**< status register					*/
#define	SJA1000_IR			0x03	/**< interrupt register					*/
#define SJA1000_IER			0x04	/**< interrupt enable register			*/
/* reserved					0x05	*/
#define	SJA1000_BTR0		0x06	/**< bus timing 0						*/
#define	SJA1000_BTR1		0x07	/**< bus timing 1						*/
#define	SJA1000_OCR			0x08	/**< output control						*/
/* test					    0x09	*/
/* reserved					0x0a	*/
#define SJA1000_ALC			0x0b	/**< Arbitration Lost Capture			*/
#define SJA1000_ECC			0x0c	/**< Error Code Capture					*/
#define SJA1000_EWL			0x0d	/**< Error Warning Limit				*/
#define SJA1000_RXERR		0x0e	/**< RX Error Counter Register			*/
#define SJA1000_TXERR		0x0f	/**< TX Error Counter Register			*/
#define SJA1000_RMC			0x1d	/**< RX Buffer Message Counter Register	*/
#define SJA1000_RBSA		0x1e	/**< RX Buffer Start Address Register	*/
#define SJA1000_CDR			0x1f	/**< clock divider register				*/
#define SJA1000_ACR(_n_)	(0x10 +_n_)	/**< Acceptance Code n				*/
#define SJA1000_AMR(_n_)	(0x14 +_n_)	/**< Acceptance Code n				*/
#define SJA1000_RX_BUF(_n_)	(0x10 +_n_)	/**< RX Buffer						*/
#define SJA1000_TX_BUF(_n_)	(0x10 +_n_)	/**< TX Buffer						*/

/*****************************************************************************
 * 								FLAGS  (PeliCAN Mode)
 ****************************************************************************/
/* mode register */
#define SJA1000_MOD_SM			(1<<4)	/**< Sleep Mode						*/
#define SJA1000_MOD_AFM			(1<<3)	/**< Acceptance Filter Mode			*/
#define SJA1000_MOD_STM			(1<<2)	/**< Self Test Mode					*/
#define SJA1000_MOD_LOM			(1<<1)	/**< Listen Only Mode				*/
#define SJA1000_MOD_RM			(1<<0)	/**< Reset Mode						*/
/* command register */
#define SJA1000_CMR_SRR			(1<<4)	/**< Self Reception Request			*/
#define SJA1000_CMR_CDO			(1<<3)	/**< Clear Data Overrun				*/
#define SJA1000_CMR_RRB			(1<<2)	/**< Release Receive Buffer			*/
#define SJA1000_CMR_AT			(1<<1)	/**< Abort Transmission				*/
#define SJA1000_CMR_TR			(1<<0)	/**< Transmission Request			*/
/* interrupt register */
#define SJA1000_IR_BEI			(1<<7)	/**< Bus Error Interrupt			*/
#define SJA1000_IR_ALI			(1<<6)	/**< Arbitration Lost Interrupt		*/
#define SJA1000_IR_EPI			(1<<5)	/**< Error Passive Interrupt		*/
/* additional declarations are below */

/* interrupt enable register */
#define SJA1000_IER_BEIE		(1<<7)	/**< Bus Error Interrupt Enable		*/
#define SJA1000_IER_ALIE		(1<<6)	/**< Arbitration Lost Interrupt Enable */
#define SJA1000_IER_EPIE		(1<<5)	/**< Error Passive Interrupt Enable	*/
#define SJA1000_IER_WUIE		(1<<4)	/**< Wake-up Interrupt Enable		*/
#define SJA1000_IER_DOIE		(1<<3)	/**< Data overrun Interrupt Enable	*/
#define SJA1000_IER_EIE			(1<<2)	/**< Error Warning Interrupt Enable	*/
#define SJA1000_IER_TIE			(1<<1)	/**< Transmit Interrupt Enable		*/
#define SJA1000_IER_RIE			(1<<0)	/**< Receive Interrupt Enable		*/
/* Frame information */
#define SJA1000_FRAMEINFO_FF	(1<<7)	/**< Frame Format					*/
#define SJA1000_FRAMEINFO_RTR	(1<<6)	/**< Remote transmission Request	*/
/* status register */
#define SJA1000_SR_BS			(1<<7)	/**< bus status						*/
#define SJA1000_SR_ES			(1<<6)	/**< error status					*/
#define SJA1000_SR_TS			(1<<5)	/**< transmit status				*/
#define SJA1000_SR_RS			(1<<4)	/**< receive status					*/
#define SJA1000_SR_TCS			(1<<3)	/**< transmission complete status	*/
#define SJA1000_SR_TBS			(1<<2)	/**< transmit buffer status			*/
#define SJA1000_SR_DOS			(1<<1)	/**< data overrun status			*/
#define SJA1000_SR_RBS			(1<<0)	/**< receive buffer status			*/
/* interrupt register */
#define SJA1000_IR_WUI			(1<<4)	/**< wake-up interrupt				*/
#define SJA1000_IR_DOI			(1<<3)	/**< data overrun interrupt			*/
#define SJA1000_IR_EI			(1<<2)	/**< error interrupt				*/
#define SJA1000_IR_TI			(1<<1)	/**< transmit interrupt				*/
#define SJA1000_IR_RI			(1<<0)	/**< receive interrupt				*/
/* clock divider register (CDR) */
#define SJA1000_CDR_CANMODE		(1<<7)	/**< can mode (BasicCAN or PeliCAN)	*/
#define SJA1000_CDR_CBP			(1<<6)	/**< input bypass					*/
#define SJA1000_CDR_RXINTEN		(1<<5)	/**< TX1 as receive interrupt output*/
#define SJA1000_CDR_CLOCK_OFF	(1<<3)	/**< disable CLKOUT pin				*/

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/

/*----- Data ---------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 * @}
 */

#endif /* __CAN_SJA1000_H__ */
