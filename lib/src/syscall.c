#include <stdio.h>
#include <sys/stat.h>
#include "gd32f4xx_usart.h"
#include <errno.h>
#include <unistd.h>

extern uint32_t __stack_end__;
extern uint32_t __heap_end__;

void __attribute__((weak)) _putchar(char ch)
{
}

char __attribute__((weak)) _getchar()
{
    return 0;
}

int __attribute__((weak)) _fstat(int fd, struct stat *st)
{
    st->st_mode = S_IFCHR;
    return 0;
}

int __attribute__((weak)) _isatty(int fd)
{
    return 1;
}

int __attribute__((weak)) _getpid(void)
{
    return -1;
}

void __attribute__((weak)) _kill(int pid, int sig)
{
    return;
}

void __attribute__((weak)) _exit(int status)
{
    while (1)
    {
    }
}

int __attribute__((weak)) _write(int fd, const char *buf, int nbytes)
{
    if (fd == STDOUT_FILENO || fd == STDERR_FILENO)
    {
        for (int i = 0; i < nbytes; ++i)
        {
            _putchar(buf[i]);
        }
    }
    return nbytes;
}

int __attribute__((weak)) _read(int fd, char *buf, int nbytes)
{
    if (fd == STDIN_FILENO)
    {
        for (int i = 0; i < nbytes; ++i)
        {
            buf[i] = _getchar();
        }
    }

    return 0;
}

char *__attribute__((weak)) _sbrk(int nbytes)
{
    static uint8_t *heap = NULL;
    uint8_t *prev;
    if (!heap)
        heap = (uint8_t *)&__stack_end__;
    prev = heap;
    heap += nbytes;
    if (heap >= (uint8_t *)&__heap_end__)
    {
        heap = prev;
        errno = ENOMEM;
        return (uint8_t *)-1;
    }
    return prev;
}

int __attribute__((weak)) _close(int fd)
{
    return 0;
}

off_t __attribute__((weak)) _lseek(int fd, off_t offset, int whence)
{
    return 0;
}