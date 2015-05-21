#include_next <stdlib.h>

#ifndef MG_COMPAT_STDLIB_H
#define MG_COMPAT_STDLIB_H

#include <stdint.h>

#if defined(__linux__)
uint32_t	 arc4random(void);
void		 arc4random_buf(void *, size_t);
uint32_t	 arc4random_uniform(uint32_t);
void		*reallocarray(void *, size_t, size_t);
long long	 strtonum(const char *, long long, long long, const char **);
#elif defined(__APPLE__)
void		*reallocarray(void *, size_t, size_t);
long long	 strtonum(const char *, long long, long long, const char **);
#endif

#endif
