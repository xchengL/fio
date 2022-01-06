#ifndef FIO_WINDOWS_POSIX_H
#define FIO_WINDOWS_POSIX_H

#ifndef S_ISSOCK
#define    S_ISSOCK(m)    0    /* socket */
#endif

int fork(void);
pid_t setsid(void);

int nice(int incr);
int posix_madvise(void *addr, size_t len, int advice);

ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off_t offset);
ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset);
int pclose(FILE *stream);
FILE *popen(const char *command, const char *type);
int execvp(const char *file, char *const argv[]);

#endif
