#include_next <unistd.h>

#ifndef MG_COMPAT_UNISTD_H
#define MG_COMPAT_UNISTD_H

#if defined(__linux__)
int	getentropy(void *, size_t);
#endif

#endif
