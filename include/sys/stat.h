#include_next <sys/stat.h>

#ifndef MG_COMPAT_SYS_STAT_H
#define MG_COMPAT_SYS_STAT_H

#if defined(__linux__)
#define st_mtimespec	st_mtim
#endif

#endif
