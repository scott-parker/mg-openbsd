#include_next <string.h>

#ifndef MG_COMPAT_STRING_H
#define MG_COMPAT_STRING_H

#if defined(__linux__)
void	explicit_bzero(void *, size_t);
size_t	strlcat(char *, const char *, size_t);
size_t	strlcpy(char *, const char *, size_t);
#endif

#endif
