#ifndef MG_COMPAT_UTIL_H
#define MG_COMPAT_UTIL_H

#if defined(__linux__) || defined(__APPLE__)
#define FPARSELN_UNESCESC	0x01
#define FPARSELN_UNESCCONT	0x02
#define FPARSELN_UNESCCOMM	0x04
#define FPARSELN_UNESCREST	0x08
#define FPARSELN_UNESCALL	0x0f

char	*fparseln(FILE *, size_t *, size_t *, const char [3], int);
#endif

#endif
