#include_next <stdio.h>

#ifndef MG_COMPAT_STDIO_H
#define MG_COMPAT_STDIO_H

#if defined(__linux__)
char	*fgetln(FILE *, size_t *);
#endif

#endif
