#ifndef _DISKIO_DEFINED
#define _DISKIO_DEFINED
/**
 *****************************************************************************
 * @addtogroup 	FatFs FatFs
 * @{
 * @defgroup	FatFs_DiskIO Disk IO
 * @brief		Low level disk I/O module skeleton for FatFs
 * @{
 *
 * \file		diskio.c
 * \version		R0.10
 * \date		2013-10-02
 * \author		ChaN
 *
 * @brief		Low level disk I/O module skeleton for FatFs
 * @note		If a working storage control module is available, it should
 *				be attached to the FatFs via a glue function rather than
 *				modifying it.\n
 *				This is an example of glue functions to attach various
 *				exsisting storage control module to the FatFs module with a
 *				defined API.
 *
 *****************************************************************************
 * @copyright
 * @{
 *
 * Copyright &copy; 2013, ChaN, all right reserved.
 *
 * FatFs module is a generic FAT file system module for small embedded
 * systems.
 * This is a free software that opened for education, research and commercial
 * developments under license policy of following terms.
 *
 * * The FatFs module is a free software and there is NO WARRANTY.
 * * No restriction on use. You can use, modify and redistribute it for
 *   personal, non-profit or commercial products UNDER YOUR RESPONSIBILITY.
 * * Redistributions of source code must retain the above copyright notice.
 *
 * @}
 *****************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----- Header-Files -------------------------------------------------------*/
#include "integer.h"

/*----- Macros -------------------------------------------------------------*/
#define _USE_WRITE	1			/**< 1: Enable disk_write function			*/
#define _USE_IOCTL	1			/**< 1: Enable disk_ioctl function			*/

/* Disk Status Bits (DSTATUS) */
#define STA_NOINIT		0x01	/**< Drive not initialized					*/
#define STA_NODISK		0x02	/**< No medium in the drive					*/
#define STA_PROTECT		0x04	/**< Write protected						*/

/* Command code for disk_ioctrl fucntion */

/* Generic command (used by FatFs) */
#define CTRL_SYNC			0	/**< Flush disk cache (for write functions)	*/
#define GET_SECTOR_COUNT	1	/**< Get media size (for only f_mkfs())		*/
#define GET_SECTOR_SIZE		2	/**< Get sector size (for multiple sector
									 size (_MAX_SS >= 1024))				*/
#define GET_BLOCK_SIZE		3	/**< Get erase block size (for only
									 f_mkfs())								*/
#define CTRL_ERASE_SECTOR	4	/**< Force erased a block of sectors (for
									 only _USE_ERASE)						*/

/* Generic command (not used by FatFs) */
#define CTRL_POWER			5	/**< Get/Set power status					*/
#define CTRL_LOCK			6	/**< Lock/Unlock media removal				*/
#define CTRL_EJECT			7	/**< Eject media							*/
#define CTRL_FORMAT			8	/**< Create physical format on the media	*/

/* MMC/SDC specific ioctl command */
#define MMC_GET_TYPE		10		/**< Get card type						*/
#define MMC_GET_CSD			11		/**< Get CSD							*/
#define MMC_GET_CID			12		/**< Get CID							*/
#define MMC_GET_OCR			13		/**< Get OCR							*/
#define MMC_GET_SDSTAT		14		/**< Get SD status						*/

/* ATA/CF specific ioctl command */
#define ATA_GET_REV			20		/**< Get F/W revision					*/
#define ATA_GET_MODEL		21		/**< Get model name						*/
#define ATA_GET_SN			22		/**< Get serial number					*/


/* MMC card type flags (MMC_GET_TYPE) */
#define CT_MMC		0x01			/**< MMC ver 3							*/
#define CT_SD1		0x02			/**< SD ver 1							*/
#define CT_SD2		0x04			/**< SD ver 2							*/
#define CT_SDC		(CT_SD1|CT_SD2)	/**< SD									*/
#define CT_BLOCK	0x08			/**< Block addressing					*/

/*----- Data types ---------------------------------------------------------*/
/**
 * \brief	Status of Disk Functions
 * \typedef	DSTATUS
 */
typedef BYTE	DSTATUS;

/**
 * \brief	Results of Disk Functions
 * \typedef	DRESULT
 */
typedef enum {
	RES_OK = 0,		/**< 0: Successful			*/
	RES_ERROR,		/**< 1: R/W Error			*/
	RES_WRPRT,		/**< 2: Write Protected		*/
	RES_NOTRDY,		/**< 3: Not Ready			*/
	RES_PARERR		/**< 4: Invalid Parameter	*/
} DRESULT;

/*----- Function prototypes ------------------------------------------------*/
DSTATUS disk_initialize (BYTE drv);
DSTATUS disk_status (BYTE drv);
DRESULT disk_read (BYTE drv, BYTE*buff, DWORD sector, UINT count);
#if _USE_WRITE
DRESULT disk_write(BYTE drv, const BYTE *buff, DWORD sector, BYTE count);
#endif /* _USE_WRITE */
#if _USE_IOCTL
DRESULT disk_ioctl (BYTE drv, BYTE cmd, void* buff);
#endif /* _USE_IOCTL */

/*----- Data ---------------------------------------------------------------*/

/*----- Implementation -----------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * \}
 * \}
 */

#endif /* _DISKIO_DEFINED */
