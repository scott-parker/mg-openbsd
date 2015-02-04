#include_next <limits.h>

#ifndef MG_COMPAT_LIMITS_H
#define MG_COMPAT_LIMITS_H

#if defined(__APPLE__)
#define LOGIN_NAME_MAX	MAXLOGNAME
#endif

#endif
