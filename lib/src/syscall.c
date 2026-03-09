#include <errno.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/stat.h>
#include <unistd.h>

extern uint8_t __heap_start__[];
extern uint8_t __heap_end__[];

void __attribute__((weak)) _putchar(char ch)
{
    (void)ch;
}

char __attribute__((weak)) _getchar(void)
{
    return 0;
}

int __attribute__((weak)) _fstat(int fd, struct stat *st)
{
    if (fd == STDOUT_FILENO || fd == STDERR_FILENO || fd == STDIN_FILENO) {
        st->st_mode = S_IFCHR;
        return 0;
    }

    errno = EBADF;
    return -1;
}

int __attribute__((weak)) _isatty(int fd)
{
    if (fd == STDOUT_FILENO || fd == STDERR_FILENO || fd == STDIN_FILENO) {
        return 1;
    }

    errno = EBADF;
    return 0;
}

int __attribute__((weak)) _getpid(void)
{
    return 1;
}

int __attribute__((weak)) _kill(int pid, int sig)
{
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

void __attribute__((weak)) _exit(int status)
{
    (void)status;
    while (1) {
    }
}

int __attribute__((weak)) _write(int fd, const char *buf, int nbytes)
{
    if (fd == STDOUT_FILENO || fd == STDERR_FILENO) {
        for (int i = 0; i < nbytes; ++i) {
            _putchar(buf[i]);
        }
        return nbytes;
    }

    errno = EBADF;
    return -1;
}

int __attribute__((weak)) _read(int fd, char *buf, int nbytes)
{
    if (fd == STDIN_FILENO) {
        for (int i = 0; i < nbytes; ++i) {
            buf[i] = _getchar();
        }
        return nbytes;
    }

    errno = EBADF;
    return -1;
}

void *__attribute__((weak)) _sbrk(ptrdiff_t incr)
{
    static uint8_t *heap = NULL;
    uint8_t *prev;

    if (incr < 0) {
        errno = ENOMEM;
        return (void *)-1;
    }

    if (heap == NULL) {
        heap = __heap_start__;
    }

    prev = heap;
    heap += incr;

    if (heap > __heap_end__) {
        heap = prev;
        errno = ENOMEM;
        return (void *)-1;
    }

    return prev;
}

int __attribute__((weak)) _close(int fd)
{
    if (fd == STDOUT_FILENO || fd == STDERR_FILENO || fd == STDIN_FILENO) {
        return 0;
    }

    errno = EBADF;
    return -1;
}

off_t __attribute__((weak)) _lseek(int fd, off_t offset, int whence)
{
    (void)offset;
    (void)whence;

    if (fd == STDOUT_FILENO || fd == STDERR_FILENO || fd == STDIN_FILENO) {
        return 0;
    }

    errno = EBADF;
    return (off_t)-1;
}
