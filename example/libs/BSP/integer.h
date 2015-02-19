#ifndef _FF_INTEGER
#define _FF_INTEGER
/**
 *****************************************************************************
 * \addtogroup 	FatFs FatFs
 * \{
 * \addtogroup 	Integer Integer
 * \{
 *
 * \brief		Integer type definitions for FatFs module.
 *
 * \file		integer.h
 * \version		R0.10
 * \date		2013-10-02
 * \author		ChaN
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

#ifdef _WIN32					/* FatFs development platform				*/

#include <windows.h>
#include <tchar.h>

#else			/* Embedded platform */

/* This type MUST be 8 bit */
typedef unsigned char	BYTE;

/* These types MUST be 16 bit */
typedef short			SHORT;
typedef unsigned short	WORD;
typedef unsigned short	WCHAR;

/* These types MUST be 16 bit or 32 bit */
typedef int				INT;
typedef unsigned int	UINT;

/* These types MUST be 32 bit */
typedef long			LONG;
typedef unsigned long	DWORD;

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * \}
 * \}
 */

#endif /* _FF_INTEGER */
