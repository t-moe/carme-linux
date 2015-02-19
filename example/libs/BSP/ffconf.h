#ifndef _FFCONF
#define _FFCONF 80960		/**< Revision ID								*/
/**
 *****************************************************************************
 * \addtogroup 	FatFs FatFs
 * \{
 * \defgroup 	Conf Configuration
 * \brief		FatFs configuration
 * \{
 *
 * \brief		FAT file system module configuration file
 *
 * \file		ffconf.h
 * \version		R0.10
 * \date		2013-10-02
 * \author		ChaN
 *
 * \attention
 * CAUTION! Do not forget to make clean the project after any changes to
 * the configuration options.
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

/**
 * \defgroup 	FatFs_Core_Conf_FuncBuff Functions and Buffer
 * \brief		Functions and Buffer Configurations
 * \{
 */

/**
 * \brief	When _FS_TINY is set to 1, FatFs uses the sector buffer in the
 *			file system object instead of the sector buffer in the individual
 *			file object for file data transfer. This reduces memory
 *			consumption 512 bytes each file object.
 *
 * Value:
 * \arg 0:	Normal
 * \arg 1:	Tiny
 */
#define	_FS_TINY		0

/**
 * \brief	Setting _FS_READONLY to 1 defines read only configuration. This
 *			removes writing functions, f_write(), f_sync(), f_unlink(),
 *			f_mkdir(), f_chmod(), f_rename(), f_truncate() and useless
 *			f_getfree().
 *
 * Value:
 * \arg 0:	Read/Write
 * \arg 1:	Read only
 */
#define _FS_READONLY	0

/**
 * \brief	The _FS_MINIMIZE option defines minimization level to remove API
 *			functions.
 *
 * Value:
 * \arg 0:	All basic functions are enabled.
 * \arg 1:	f_stat(), f_getfree(), f_unlink(), f_mkdir(), f_chmod(),
 *			f_utime(), f_truncate() and f_rename() function are removed.
 * \arg 2:	f_opendir(), f_readdir() and f_closedir() are removed in
 *			addition to 1.
 * \arg 3:	f_lseek() function is removed in addition to 2.
 */
#define _FS_MINIMIZE	0

/**
 * \brief	To enable string functions, set _USE_STRFUNC to 1 or 2.
 *
 * Value:
 * \arg 0:	Disable
 * \arg 1:	Enable
 * \arg 2:	Enable
 */
#define	_USE_STRFUNC	1

/**
 * \brief	To enable f_mkfs() function, set _USE_MKFS to 1 and set
 *			#_FS_READONLY to 0.
 *
 * Value:
 * \arg 0:	Disable
 * \arg 1:	Enable
 */
#define	_USE_MKFS		1

/**
 * \brief	To enable fast seek feature, set _USE_FASTSEEK to 1.
 *
 * Value:
 * \arg 0:	Disable
 * \arg 1:	Enable
 */
#define	_USE_FASTSEEK	0

/**
 * \brief	To enable volume label functions, set _USE_LABEL to 1.
 *
 * Value:
 * \arg 0:	Disable
 * \arg 1:	Enable
 */
#define _USE_LABEL		0

/**
 * \brief	To enable f_forward() function, set _USE_FORWARD to 1 and set
 *			_FS_TINY to 1.
 *
 * Value:
 * \arg 0:	Disable
 * \arg 1:	Enable
 */
#define	_USE_FORWARD	0

/**
 * \}
 */

/**
 * \defgroup 	FatFs_Core_Conf_LocalNamespace Locale and Namespace
 * \brief		Locale and Namespace Configurations
 * \{
 */

/**
 * \brief	The _CODE_PAGE specifies the OEM code page to be used on the
 *			target system. Incorrect setting of the code page can cause a
 *			file open failure.
 *
 * Value:
 * \arg 932:	Japanese Shift-JIS (DBCS, OEM, Windows)
 * \arg 936:	Simplified Chinese GBK (DBCS, OEM, Windows)
 * \arg 949:	Korean (DBCS, OEM, Windows)
 * \arg 950:	Traditional Chinese Big5 (DBCS, OEM, Windows)
 * \arg 1250:	Central Europe (Windows)
 * \arg 1251:	Cyrillic (Windows)
 * \arg 1252:	Latin 1 (Windows)
 * \arg 1253:	Greek (Windows)
 * \arg 1254:	Turkish (Windows)
 * \arg 1255:	Hebrew (Windows)
 * \arg 1256:	Arabic (Windows)
 * \arg 1257:	Baltic (Windows)
 * \arg 1258:	Vietnam (OEM, Windows)
 * \arg 437:	U.S. (OEM)
 * \arg 720:	Arabic (OEM)
 * \arg 737:	Greek (OEM)
 * \arg 775:	Baltic (OEM)
 * \arg 850:	Multilingual Latin 1 (OEM)
 * \arg 858:	Multilingual Latin 1 + Euro (OEM)
 * \arg 852:	Latin 2 (OEM)
 * \arg 855:	Cyrillic (OEM)
 * \arg 866:	Russian (OEM)
 * \arg 857:	Turkish (OEM)
 * \arg 862:	Hebrew (OEM)
 * \arg 874:	Thai (OEM, Windows)
 * \arg 1:		ASCII (Valid for only non-LFN cfg.)
 */
#define _CODE_PAGE		1252


/**
 * \brief	The _USE_LFN option switches the LFN feature.
 *
 * Value:
 * \arg 0:	Disable LFN feature. _MAX_LFN has no effect.
 * \arg 1:	Enable LFN with static working buffer on the BSS. Always NOT
 *			reentrant.
 * \arg 2:	Enable LFN with dynamic working buffer on the STACK.
 * \arg 3:	Enable LFN with dynamic working buffer on the HEAP.
 *
 * \note
 * To enable LFN feature, Unicode handling functions ff_convert() and
 * ff_wtoupper() function must be added to the project.
 * The LFN working buffer occupies (#_MAX_LFN + 1) * 2 bytes. When use stack
 * for the working buffer, take care on stack overflow. When use heap memory
 * for the working buffer, memory management functions, ff_memalloc() and
 * ff_memfree(), must be added to the project.
 */
#define	_USE_LFN		0

/**
 * \brief	Maximum LFN length to handle
 *
 * Value:
 * \arg 12 to 255
 */
#define	_MAX_LFN		255


/**
 * \brief	To switch the character encoding on the FatFs API to Unicode,
 *			enable LFN feature and set _LFN_UNICODE to 1.
 *
 * Value:
 * \arg 0:	ANSI/OEM
 * \arg 1:	Unicode
 */
#define	_LFN_UNICODE	0


/**
 * \brief	When Unicode API is enabled, character encoding on the all FatFs
 *			API is switched to Unicode. This option selects the character
 *			encoding on the file to be read/written via string functions,
 *			f_gets(), f_putc(), f_puts and f_printf().\n
 *			This option has no effect when _LFN_UNICODE is 0.
 *
 * Value:
 * \arg 0:	ANSI/OEM
 * \arg 1:	UTF-16LE
 * \arg 2:	UTF-16BE
 * \arg 3:	UTF-8
 */
#define _STRF_ENCODE	3


/**
 * \brief	The _FS_RPATH option configures relative path feature.
 *
 * Value:
 * \arg 0:	Disable relative path feature and remove related functions.
 * \arg 1:	Enable relative path. f_chdrive() and f_chdir() function are
 *			available.
 * \arg 2:	f_getcwd() function is available in addition to 1.
 *
 * \note
 * Note that output of the f_readdir() function is affected by this option.
 */
#define _FS_RPATH		0

/**
 * \}
 */

/**
 * \defgroup 	FatFs_Core_Conf_DriveVolume Drive/Volume
 * \brief		Drive/Volume Configurations
 * \{
 */

/**
 * \brief	Number of volumes (logical drives) to be used.
 */
#define _VOLUMES		1


/**
 * \brief	When set to 0, each volume is bound to the same physical drive
 *			number and it can mount only first primaly partition. When it is
 *			set to 1, each volume is tied to the partitions listed in
 *			VolToPart[].
 *
 * Value:
 * \arg 0:	Single partition
 * \arg 1:	Enable multiple partition
 */
#define	_MULTI_PARTITION	0


/**
 * \brief	Maximum sector size to be handled.
 *			Always set 512 for memory card and hard disk but a larger value
 *			may be required for on-board flash memory, floppy disk and optical
 *			disk.\n
 *			When _MAX_SS is larger than 512, it configures FatFs to variable
 *			sector size and GET_SECTOR_SIZE command must be implemented to the
 *			disk_ioctl() function.
 *
 * Value:
 * \arg 512
 * \arg 1024
 * \arg 2048
 * \arg 4096
 */
#define	_MAX_SS		512


/**
 * \brief	To enable sector erase feature, set _USE_ERASE to 1. Also
 *			CTRL_ERASE_SECTOR command should be added to the disk_ioctl()
 *			function.
 *
 * Value:
 * \arg 0:	Disable
 * \arg 1:	Enable
 */
#define	_USE_ERASE	0


/**
 * \brief	If you need to know the correct free space on the FAT32 volume,
 *			set this option to 1 and f_getfree() function at first time after
 *			volume mount will force a full FAT scan.
 *
 * Value:
 * \arg 0:	Load all informations in the FSINFO if available.
 * \arg 1:	Do not trust free cluster count in the FSINFO.
 */
#define _FS_NOFSINFO	0

/**
 * \}
 */

/**
 * \defgroup 	FatFs_Core_Conf_System System
 * \brief		System Configurations
 * \note
 * A header file that defines sync object types on the O/S, such as
 * windows.h, ucos_ii.h and semphr.h, must be included prior to ff.h.
 * \{
 */

/**
 * \brief	The _WORD_ACCESS option is an only platform dependent option. It
 *			defines which access method is used to the word data on the FAT
 *			volume.
 *
 * Value:
 * \arg 0:	Byte-by-byte access. Always compatible with all platforms.
 * \arg 1:	Word access. Do not choose this unless under both the following
 *			conditions.
 *
 * \note
 * \arg Byte order on the memory is little-endian.
 * \arg Address miss-aligned word access is always allowed for all
 *		instructions.
 *
 * \note
 * If it is the case, _WORD_ACCESS can also be set to 1 to improve performance
 * and reduce code size.
 */
#define _WORD_ACCESS	0

/**
 * \brief	The _FS_REENTRANT option switches the re-entrancy (thread safe)
 *			of the FatFs module.
 *
 * Value:
 * \arg 0:	Disable re-entrancy. _SYNC_t and _FS_TIMEOUT have no effect.
 * \arg 1:	Enable re-entrancy. Also user provided synchronization handlers,
 *			#ff_req_grant(), ff_rel_grant(), ff_del_syncobj() and
 *			#ff_cre_syncobj() function must be added to the project.
 */
#define _FS_REENTRANT	1

/**
 * \brief	Timeout period in unit of time ticks
 */
#define _FS_TIMEOUT		1000

/**
 * \brief	O/S dependent type of sync object. e.g. HANDLE, OS_EVENT*, ID
 *			and etc..
 */
#define	_SYNC_t			void *

/**
 * \brief	To enable file lock control feature, set _FS_LOCK to 1 or greater.
 *			The value defines how many files can be opened simultaneously.
 *
 * Value:
 * \arg 0:		Disable
 * \arg >=1:	Enable
 */
#define	_FS_LOCK	8

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * \}
 */

/**
 * \}
 * \}
 */

#endif /* _FFCONFIG */
