/* This file contains functions which implement those POSIX and Linux functions
 * that VxWorks don't provide. The implementations contain just enough
 * functionality to support fio.
 */

#include "../os-vxworks.h"
#include <stdio.h>
#include <sys/mman.h>
#include <log.h>
#include <taskLibCommon.h>

#define VXFIO_SHM_NAME      "vxFioShm"
#define VXFIO_MAX_NAME_LEN  100

/*
 * the least significant 9 bits of shmflg specify the permissions granted to 
 * the owner, group, and others
 */

#define VXFIO_PERM_MASK     0x1F

int shmget(key_t key, size_t size, int shmflg)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

void *shmat(int shmid, const void *shmaddr, int shmflg)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return NULL;
}

int shmdt(const void *shmaddr)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

int shmctl(int shmid, int cmd, struct shmid_ds *buf)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

int fork(void)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

pid_t setsid(void)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

int nice(int incr)
{
    if (incr < 1) {
        incr = 1;
    } else if (incr > 255) {
        incr = 255;
    }
    return taskPrioritySet (taskIdSelf(), incr);
}

int posix_madvise(void *addr, size_t len, int advice)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

ssize_t pwrite(int fildes, const void *buf, size_t nbyte, off_t offset)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

ssize_t pread(int fildes, void *buf, size_t nbyte, off_t offset)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

int pclose(FILE *stream)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return -1;
}

FILE *popen(const char *command, const char *type)
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return NULL;
}

int execvp(const char *file, char *const argv[])
{
    log_err("%s is not implemented\n", __func__);
    errno = ENOSYS;
    return NULL;
}