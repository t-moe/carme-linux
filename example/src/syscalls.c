/**
 *****************************************************************************
 * @addtogroup	CARME
 * @{
 * @addtogroup	USART
 * @{
 *
 * @file		syscalls.c
 *
 * @brief		Atollic TrueSTUDIO Minimal System calls file\n
 *				For more information about which c-functions need which of
 *				these lowlevel functions please consult the Newlib
 *				libc-manual.
 *
 *****************************************************************************
 * @copyright
 * @{
 *
 * The file is distributed as is, without any warranty of any kind.
 *
 * &copy; Copyright Atollic AB.
 * You may use this file as-is or modify it according to the needs of your
 * project. This file may only be built (assembled or compiled and linked)
 * using the Atollic TrueSTUDIO(R) product. The use of this file together
 * with other tools than Atollic TrueSTUDIO(R) is not permitted.
 *
 * @}
 *****************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----- Header-Files -------------------------------------------------------*/
#include <stdint.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include <stm32f4xx.h>

/*----- Macros -------------------------------------------------------------*/
#ifndef SYSCALL_USART
#define SYSCALL_USART	USART1		/**< The IO USART to use in syscall		*/
#endif

/*----- Data types ---------------------------------------------------------*/

/*----- Function prototypes ------------------------------------------------*/
void initialise_monitor_handles(void);
int _getpid(void);
int _kill(int32_t pid, int32_t sig);
void _exit(int32_t status);
int _write(int fd, char *str, int len);
caddr_t _sbrk(int32_t incr);
int _close(int32_t file);
int _fstat(int32_t file, struct stat *st);
int _isatty(int32_t file);
int _lseek(int32_t file, int32_t ptr, int32_t dir);
int _read(int32_t file, uint8_t *ptr, int32_t len);
int _open(uint8_t *path, int32_t flags, ...);
int _wait(int32_t *status);
int _unlink(uint8_t *name);
int _times(struct tms *buf);
int _stat(uint8_t *file, struct stat *st);
int _link(uint8_t *old, uint8_t *new);
int _fork(void);
int _execve(uint8_t *name, uint8_t **argv, uint8_t **env);

/*----- Data ---------------------------------------------------------------*/
#undef errno
extern int32_t errno;

uint8_t *__env[1] = { 0 };
uint8_t **environ = __env;

/*----- Implementation -----------------------------------------------------*/
void initialise_monitor_handles(void) {
}

int _getpid(void) {
	return 1;
}

int _kill(int32_t pid, int32_t sig) {
	errno = EINVAL;
	return -1;
}

void _exit(int32_t status) {
	_kill(status, -1);
	while (1) {
		/* Make sure we hang here */
	}
}

int _write(int fd, char *str, int len) {

	uint8_t i = 0U;

	if (str == NULL) {
		return -1;
	}

	for (i = 0U; i < len; i++) {
		while (USART_GetFlagStatus(SYSCALL_USART, USART_FLAG_TC) == RESET) {
		}
		USART_SendData(SYSCALL_USART, (uint16_t) *str);
		str++;
	}

	return len;
}

caddr_t _sbrk(int32_t incr) {

	extern uint32_t _Min_Heap_Size; /* _Min_Heap_Size symbol defined in the linker script. */
	extern uint8_t end asm("end");
	const uint8_t *max_heap = (uint8_t*) ((uint32_t) &end
			+ (uint32_t) &_Min_Heap_Size);
	static uint8_t *heap_end;
	uint8_t *prev_heap_end;

	if (heap_end == 0) {
		heap_end = &end;
	}

	prev_heap_end = heap_end;
	if ((heap_end + incr) > max_heap) {
/*
		write(1, "Heap and stack collision\n", 25);
		abort();
*/
		errno = ENOMEM;
		return (caddr_t) -1;
	}

	heap_end += incr;

	return (caddr_t) prev_heap_end;
}

int _close(int32_t file) {
	return -1;
}

int _fstat(int32_t file, struct stat *st) {
	st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int32_t file) {
	return 1;
}

int _lseek(int32_t file, int32_t ptr, int32_t dir) {
	return 0;
}

int _read(int32_t file, uint8_t *ptr, int32_t len) {

	uint32_t i = 0U;
	uint16_t res = 0U;

	if (ptr == NULL) {
		return -1;
	}

	for (i = 0U; i < len; i++) {

		if (USART_GetFlagStatus(SYSCALL_USART, USART_FLAG_RXNE) == SET) {
			res = USART_ReceiveData(SYSCALL_USART);
			if (res <= 0xFF) {
				*ptr = (uint8_t) (res & 0xFF);
				ptr++;
			}
		}
		else {
			break;
		}
	}

	return (int) i;
}

int _open(uint8_t *path, int32_t flags, ...) {
	/* Pretend like we always fail */
	return -1;
}

int _wait(int32_t *status) {
	errno = ECHILD;
	return -1;
}

int _unlink(uint8_t *name) {
	errno = ENOENT;
	return -1;
}

int _times(struct tms *buf) {
	return -1;
}

int _stat(uint8_t *file, struct stat *st) {
	st->st_mode = S_IFCHR;
	return 0;
}

int _link(uint8_t *old, uint8_t *new) {
	errno = EMLINK;
	return -1;
}

int _fork(void) {
	errno = EAGAIN;
	return -1;
}

int _execve(uint8_t *name, uint8_t **argv, uint8_t **env) {
	errno = ENOMEM;
	return -1;
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

/**
 * @}
 * @}
 */
