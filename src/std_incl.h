#if !defined(STD_INCL_H) && !defined(_FUNC_SPEC_)
#define STD_INCL_H

#ifndef EDIT_SOURCE
#  include "configure.h"
#endif

#ifdef INCL_STDLIB_H
#  include <stdlib.h>
#endif
#ifdef INCL_UNISTD_H
#  include <unistd.h>
#endif

#include <sys/types.h>
#include <stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <math.h>
#include <ctype.h>
#include <errno.h>
#ifdef INCL_FCNTL_H
#  include <fcntl.h>
#endif

#ifdef INCL_TIME_H
#  include <time.h>
#endif
#ifdef INCL_SYS_TIME_H
#  include <sys/time.h>
#endif
#ifdef INCL_DOS_H
#  include <dos.h>
#endif
#ifdef INCL_SYS_TIMES_H
#  include <sys/times.h>
#endif
#ifdef INCL_USCLKC_H
#  include <usclkc.h>
#endif

#ifdef LATTICE
#  undef VOID
#endif

#ifndef _AUX_SOURCE
/* supposedly, memmove is in here, but not defined in any lib */
#  include <string.h>
#endif

#ifndef NO_SOCKETS
#  ifdef INCL_NETINET_IN_H
#    include <netinet/in.h>
#  endif
#  ifdef INCL_ARPA_INET_H
#    include <arpa/inet.h>
#  endif
#endif
#if defined(LATTICE) || defined(__SASC)
#  include "amiga/amiga.h"
#  include "amiga/nsignal.h"
#  include "amiga/socket.h"
#endif

#if defined(LATTICE) || defined(OS2)
#define link(x,y) { \
    char link_cmd[100]; \
    sprintf(link_cmd, "copy %s %s", x, y); \
    system(link_cmd); \
}
#endif

#ifdef NeXT
#  include <libc.h>
#endif

#ifdef OS2
#  include <sys/timeb.h>
#endif

#if !defined(NeXT) && !defined(LATTICE)
#  include <sys/param.h>
#endif

#ifdef OLD_ULTRIX
#  include <stddef.h>
#  define size_t unsigned
#endif

#ifdef NeXT
#  include <mach.h>
#endif

#ifdef sun
#  include <alloca.h>
#endif

#ifdef HAS_STDARG_H
#  include <stdarg.h>
#else
#  include <varargs.h>
#endif

#endif