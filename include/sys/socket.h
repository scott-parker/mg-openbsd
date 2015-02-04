#include_next <sys/socket.h>

#ifndef MG_COMPAT_SYS_SOCKET_H
#define MG_COMPAT_SYS_SOCKET_H

#if defined(__APPLE__)
#define MSG_NOSIGNAL	SO_NOSIGPIPE
#endif

#endif
