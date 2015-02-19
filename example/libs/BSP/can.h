#ifndef __CAN_H__
#define __CAN_H__
/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	CARME_CAN_EXT
 * @{
 *
 * @file		can.h
 * @version		1.0
 * @date		2007-04-13
 * @author		M. Muehlemann
 *
 * @brief		Drivers for the CAN interface. Uses the SJA1000 CAN controller
 *				on the CARME motherboard.
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
#include <stm32f4xx.h>				/* Processor STM32F407IG				*/
#include <carme.h>					/* CARME Module							*/
#include <can_sja1000.h>			/* CAN Controller SJA1000 defines		*/

/*----- Macros -------------------------------------------------------------*/
#define CARME_CAN_nCAN_INT_PORT	GPIOI			/**< CAN Interrupt Line Port*/
#define CARME_CAN_nCAN_INT_PIN	GPIO_Pin_8		/**< CAN Interrupt Line Pin	*/
#define CARME_CAN_nCAN_IRQn_CH	EXTI9_5_IRQn	/**< Used NVIC channel		*/

/* baudrates */
#define CARME_CAN_BAUD_125K			125000		/**< Baudrade 125K			*/
#define CARME_CAN_BAUD_250K			250000		/**< Baudrade 250K			*/
#define CARME_CAN_BAUD_500K			500000		/**< Baudrade 500K			*/
#define CARME_CAN_BAUD_1M			1000000		/**< Baudrade 1M			*/

/* error codes */
#define	CARME_ERROR_CAN							CARME_ERROR_CAN_BASE + 0	/**< Common CAN error		*/
#define CARME_ERROR_CAN_INVALID_BAUDRATE		CARME_ERROR_CAN_BASE + 1	/**< Invalid baudrate		*/
#define CARME_ERROR_CAN_RXFIFO_EMPTY			CARME_ERROR_CAN_BASE + 2	/**< RxFIFO empty			*/
#define CARME_ERROR_CAN_INVALID_MODE			CARME_ERROR_CAN_BASE + 3	/**< Invalid mode			*/
#define CARME_ERROR_CAN_INVALID_OPMODE			CARME_ERROR_CAN_BASE + 4	/**< Invalid opmode			*/
#define CARME_ERROR_CAN_INVALID_ACCEPTANCE_MODE	CARME_ERROR_CAN_BASE + 5	/**< Invalid acceptance mode*/
#define CARME_ERROR_CAN_ERROR_STATUS			CARME_ERROR_CAN_BASE + 6	/**< Status error			*/

/* interrupt enable flags */
#define CARME_CAN_INT_BUSERR		(SJA1000_IER_BEIE)	/**< Bus Error Interrupt Enable			*/
#define CARME_CAN_INT_ARBIT_LOST	(SJA1000_IER_ALIE)	/**< Arbitration Lost Interrupt Enable	*/
#define CARME_CAN_INT_PASSIVE		(SJA1000_IER_EPIE)	/**< Error Passive Interrupt Enable		*/
#define CARME_CAN_INT_WAKEUP		(SJA1000_IER_WUIE)	/**< Wake-up Interrupt Enable			*/
#define CARME_CAN_INT_OVERRUN		(SJA1000_IER_DOIE)	/**< Data overrun Interrupt Enable		*/
#define CARME_CAN_INT_ERROR			(SJA1000_IER_EIE)	/**< Error Warning Interrupt Enable		*/
#define CARME_CAN_INT_TX			(SJA1000_IER_TIE)	/**< Transmit Interrupt Enable			*/
#define CARME_CAN_INT_RX			(SJA1000_IER_RIE)	/**< Receive Interrupt Enable			*/

/* driver flags */
#define CARME_CAN_DF_RESET			0x00	/**< RM-Bit in MOD register set		*/
#define CARME_CAN_DF_NORMAL			0x01	/**< RM-Bit in MOD register cleared	*/
#define CARME_CAN_DF_LISTEN_ONLY	0x02	/**< LOM-Bit in MOD register set	*/
//#define CARME_CAN_DF_SLEEP		0x04

/*----- Data types ---------------------------------------------------------*/
/**
 * @brief	Interrupt sources of the CAN-Controller
 */
enum CARME_CAN_IRQ_CALLBACKS {
	CARME_CAN_IRQID_RX_INTERRUPT = 0,			/**< Telegram received Interrupt							*/
	CARME_CAN_IRQID_TX_INTERRUPT,				/**< Telegram transmitted Interrupt							*/
	CARME_CAN_IRQID_ERROR_INTERRUPT,			/**< Error warning Interrupt								*/
	CARME_CAN_IRQID_DATAOVERFLOW_INTERRUPT,		/**< Overflow Interrupt										*/
	CARME_CAN_IRQID_WAKEUP_INTERRUPT,			/**< Wakeup Interrupt Occurs when the sleep mode is left	*/
	CARME_CAN_IRQID_PASSIVE_INTERRUPT,			/**< Passive Interrupt										*/
	CARME_CAN_IRQID_ARITRATION_LOST_INTERRUPT,	/**< Arbitration Lost Interrupt								*/
	CARME_CAN_IRQID_BUS_ERROR_INTERRUPT,		/**< Bus Error Interrupt									*/

	CARME_CAN_IRQID_COUNT						/**< this must be the last entry (used for array size)		*/
};

/**
 * @brief	This struct encapsulates a CAN message.
 */
typedef struct _CARME_CAN_MESSAGE {
	uint32_t id;		/**< standard or extended Identifier						*/
	uint8_t ext;		/**< Frame format:
							 @arg 0: Standard Frame Format (SFF)
							 @arg 1: Extended Frame Format (EFF)					*/
	uint8_t rtr;		/**< If 1 the RTR Bit was set in the received CAN message	*/
	uint8_t dlc;		/**< Number of data-bytes in the received CAN message		*/
	uint8_t data[8];	/**< Array with received databytes							*/
} CARME_CAN_MESSAGE;

/**
 * @brief	Acceptance filter modes
 * @see		@ref CARME_CAN_SetAcceptaceFilter()
 */
enum CARME_CAN_ACCEPTANCE_FILTER_MODE {
	MODE_SINGLE = 1,	/**< single acceptance filter option is enabled
							 (one filter with the length of 32 bits)		*/
	MODE_DUAL = 2		/**< dual acceptance filter option is enabled
							 (two filters with the length of 16 bits)		*/
};

/**
 * @brief	Information about the acceptance filter.
 * @see		@ref CARME_CAN_SetAcceptaceFilter()
 */
typedef struct _CARME_CAN_ACCEPTANCE_FILTER {
	uint8_t acr[4];		/**< Content of the 4 Accept Filter Code Register	*/
	uint8_t amr[4];		/**< Content of the 4 Accept Filter Mask Register	*/
	enum CARME_CAN_ACCEPTANCE_FILTER_MODE afm; /**< acceptance filter mode	*/
} CARME_CAN_ACCEPTANCE_FILTER;

/**
 * @brief	Pointer to a function.
 */
typedef void (*IRQ_CALLBACK)();

/*----- Function prototypes ------------------------------------------------*/
extern void CARME_CAN_Init(uint32_t baud, uint8_t flags);
extern void CARME_CAN_InitI(uint32_t baud, uint8_t flags, uint32_t interrupts);
extern ERROR_CODES CARME_CAN_Write(CARME_CAN_MESSAGE* txMsg);
extern ERROR_CODES CARME_CAN_Read(CARME_CAN_MESSAGE* rxMsg);

extern void CARME_CAN_Interrupt_Handler(void);
extern void CARME_CAN_RegisterIRQCallback(enum CARME_CAN_IRQ_CALLBACKS id,
                                          IRQ_CALLBACK pIRQCallback);
extern void CARME_CAN_UnregisterIRQCallback(enum CARME_CAN_IRQ_CALLBACKS id);

extern ERROR_CODES CARME_CAN_SetMode(uint8_t flags);
extern ERROR_CODES CARME_CAN_SetBaudrate(uint32_t baud);
extern ERROR_CODES CARME_CAN_SetAcceptaceFilter(
        CARME_CAN_ACCEPTANCE_FILTER* af);
extern ERROR_CODES CARME_CAN_GetAcceptaceFilter(
        CARME_CAN_ACCEPTANCE_FILTER* af);
#ifdef CARME_CAN_DEBUG
/* debug functions */
extern void CARME_CAN_PrintRegisters();
extern void CARME_CAN_GetRegisterString(char* pStr);
#endif

/*----- Data ---------------------------------------------------------------*/
static __IO uint8_t *SJA1000_CMD = (__IO uint8_t *) (FSMC_CAN_BASE);
static __IO uint8_t *SJA1000_DATA = (__IO uint8_t *) (FSMC_CAN_BASE + 8);

/*----- Implementation -----------------------------------------------------*/
/**
 * @brief		Write a value in a SJA1000 register.
 * @param[in]	registerAddress		Address from the SJA1000 register.
 * @param[in]	val					Value to write.
 */
static void CARME_CAN_Write_Register(uint8_t registerAddress, uint8_t val) {
	*SJA1000_CMD = registerAddress;		/* write address					*/
	*SJA1000_DATA = val;				/* write data						*/
}

/**
 * @brief		Reads a value from a SJA1000 register.
 * @param[in]	registerAddress		Address from the SJA1000 register.
 * @return		error code
 */
static uint8_t CARME_CAN_Read_Register(uint8_t registerAddress) {
	*SJA1000_CMD = registerAddress;		/* write address					*/
	return *SJA1000_DATA;				/* read data						*/
}

/**
 * @brief		Returns 1 if the CAN Controller is involved in bus
 *				activities\n
 *				The Function checks the BS-bit in the status register of the
 *				SJA1000.
 * @return		1 on bus-on
 */
static inline uint8_t CARME_CAN_IsBusOn(void) {
	return (CARME_CAN_Read_Register(SJA1000_SR) & SJA1000_SR_BS) == 0;
}

/**
 * @brief		Returns 1 if an data overrun occurred
 *				The Function checks the DOS-bit in the status register of the
 *				SJA1000.
 * @return		1 on data overrun
 */
static inline uint8_t CARME_CAN_IsDataOverrun(void) {
	return (CARME_CAN_Read_Register(SJA1000_SR) & SJA1000_SR_DOS)
	        == SJA1000_SR_DOS;
}

/**
 * @brief		Returns 1 if at least one of the error counters has reached
 * 				or exceeded the value in the Error Warning Limit Register. \n
 *				The Function checks the ES-bit in the status register of the
 *				SJA1000.
 * @return		1 on error
 */
static inline uint8_t CARME_CAN_IsError(void) {
	return (CARME_CAN_Read_Register(SJA1000_SR) & SJA1000_SR_ES)
			== SJA1000_SR_ES;
}

/**
 * @brief		Clear Data-Overrun-Bit in the status register of the SJA1000
 */
static inline void CARME_CAN_ClearDataOverrun(void) {
	CARME_CAN_Write_Register(SJA1000_CMR, SJA1000_CMR_CDO);	// set CDO-bit
}

/**
 * @brief		Cancel a pending transmission request.
 */
static inline void CARME_CAN_AbortTransmisssion(void) {

	CARME_CAN_Write_Register(SJA1000_CMR, SJA1000_CMR_AT);	// set At-bit
}

/**
 * @brief		Set the value of the Error Warning Limit Register. The content
 * 				can only be changed in reset mode.
 * @param[in]	limit	The new content of the Error Warning Limit Register
 * @return		Error code
 */
static inline ERROR_CODES CARME_CAN_SetErrorWarningLimit(uint8_t limit) {
	ERROR_CODES err = CARME_NO_ERROR;

	if (!(CARME_CAN_Read_Register(SJA1000_MOD) & SJA1000_MOD_RM)) {
		err = CARME_ERROR_CAN_INVALID_OPMODE;
	}
	CARME_CAN_Write_Register(SJA1000_EWL, limit);

	return err;
}

/**
 * @brief		Get the value of the Error Warning Limit Register.
 * @param[in]	limit	Pointer to a variable which will contain the content
 *						of the Error Warning Limit Register
 */
static inline void CARME_CAN_GetErrorWarningLimit(uint8_t* limit) {
	*limit = CARME_CAN_Read_Register(SJA1000_EWL);
}

/**
 * @brief		Get the value of the RX Error Count Register.
 * @param[in]	count	Pointer to a variable which will contain the content
 *						of the RX Error Count Register
 */
static inline void CARME_CAN_GetRxErrCount(uint8_t* count) {
	*count = CARME_CAN_Read_Register(SJA1000_RXERR);
}

/**
 * @brief		Get the value of the TX Error Count Register.
 * @param[in]	count	Pointer to a variable which will contain the content
 *						of the TX Error Count Register.
 */
static inline void CARME_CAN_GetTxErrCount(uint8_t* count) {

	*count = CARME_CAN_Read_Register(SJA1000_TXERR);
}

/**
 * @brief		Get the value of the TX Error Count Register.
 * @param[in]	alc		Pointer to a variable which will contain the content
 *						of the Arbitration Lost Capture Register.
 */
static inline void CARME_CAN_GetArbitrationLostCapture(uint8_t* alc) {
	*alc = CARME_CAN_Read_Register(SJA1000_ALC);
}

/**
 * @brief		Get the value of the TX Error Count Register.
 * @param[in]	ecc		Pointer to a variable which will contain the content
 *						of the Error Code Capture Register.
 */
static inline void CARME_CAN_GetErrorCodeCapture(uint8_t* ecc) {

	*ecc = CARME_CAN_Read_Register(SJA1000_ECC);
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */

#endif /* __CAN_H__ */
