#ifndef MG_COMPAT_ARC4RANDOM_H
#define MG_COMPAT_ARC4RANDOM_H

#include <sys/param.h>

#if defined(__linux__)
#include "arc4random_linux.h"
#else
#error "No arc4random hooks defined for this platform."
#endif

#endif
