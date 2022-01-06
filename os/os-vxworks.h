#ifndef FIO_OS_VXWORKS_H
#define FIO_OS_VXWORKS_H

#define FIO_OS  os_vxworks

#include <vxWorks.h>
#include <stdlib.h>
#include <stdio.h>
#include <sioLib.h>
#include <errno.h>
#include <endian.h>
#include <dlfcn.h>
#include <cpusetCommon.h>
#include "vxworks/posix.h"
#include "../file.h"

#define FIO_HAVE_CPU_AFFINITY
#define FIO_HAVE_CPU_ONLINE_SYSCONF
#define FIO_USE_GENERIC_INIT_RANDOM_STATE

#define OS_MAP_ANON     MAP_ANON

#define fio_swap16(x)   bswap16(x)
#define fio_swap32(x)   bswap32(x)
#define fio_swap64(x)   bswap64(x)

typedef cpuset_t os_cpu_mask_t;

#define fio_cpu_clear(mask, cpu)    (void) CPUSET_CLR((*mask), (cpu))
#define fio_cpu_set(mask, cpu)      (void) CPUSET_SET((*mask), (cpu))
#define fio_cpu_isset(mask, cpu)    (CPUSET_ISSET((*mask), (cpu)) != 0)
#define fio_cpu_count(mask)         CPU_COUNT((mask))

static inline unsigned int cpus_online(void)
{
    return 0;
}

static inline int fio_cpuset_init(os_cpu_mask_t *mask)
{
    return -1;
}

static inline int fio_cpuset_exit(os_cpu_mask_t *mask)
{
    return -1;
}

static inline int fio_setaffinity(int pid, os_cpu_mask_t cpumask)
{
    return -1;
}

static inline int fio_getaffinity(int pid, os_cpu_mask_t *cpumask)
{
    return -1;
}

#define FIO_MAX_CPUS            VX_MAX_SMP_CPUS
#define POSIX_MADV_SEQUENTIAL   0
#define POSIX_MADV_DONTNEED     0
#define POSIX_MADV_RANDOM       0

static inline int blockdev_size(struct fio_file *f, unsigned long long *bytes)
{
    *bytes = 0;
    return errno;
}

static inline int chardev_size(struct fio_file *f, unsigned long long *bytes)
{
    return blockdev_size(f, bytes);
}

static inline int blockdev_invalidate_cache(struct fio_file *f)
{
    return 0;
}

static inline unsigned long long os_phys_mem(void)
{
    return 0;
}

static inline int os_trim(struct fio_file *f, unsigned long long start,
              unsigned long long len)
{
    return -1;
}

#ifdef MADV_FREE
#define FIO_MADV_FREE    MADV_FREE
#endif

#ifdef FIO_HAVE_FS_STAT
static inline unsigned long long get_fs_free_size(const char *path)
{
    return 0;
}
#endif

#ifdef FIO_HAVE_SHM_ATTACH_REMOVED
static inline int shm_attach_to_open_removed(void)
{
    return 0;
}
#endif

#ifndef FIO_HAVE_ODIRECT
#define FIO_OS_DIRECTIO
static inline int fio_set_odirect(struct fio_file *f)
{
    /* Direct return 0 maybe not right */

    return 0;
}
#endif

#endif
