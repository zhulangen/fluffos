#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([FluffOS],[v3.0-alpha7.4])
AC_CONFIG_MACRO_DIR([m4])

AC_CANONICAL_TARGET

AC_LANG(C++)

# Checks for programs.
AC_PROG_CXX
AC_PROG_YACC
AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Check C++11 support.
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
AX_CHECK_LINK_FLAG([-flto], [AX_APPEND_COMPILE_FLAGS([-flto])])
F_SUPPORT_CXX11([], [AC_MSG_ERROR([
  [You compiler version is too old! FluffOS need g++ 4.6+ or clang 3.0+.]])])

# Checks for header files.
AC_FUNC_ALLOCA
AC_HEADER_RESOLV
AC_HEADER_DIRENT
AC_HEADER_MAJOR
AC_CHECK_HEADERS([arpa/inet.h arpa/telnet.h crypt.h execinfo.h fcntl.h float.h inttypes.h libintl.h limits.h locale.h malloc.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h sys/crypt.h sys/ioctl.h sys/param.h sys/resource.h sys/rusage.h sys/socket.h sys/stat.h sys/time.h sys/wait.h time.h unistd.h values.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN # needed by crypt.c
AC_TYPE_INT64_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_TYPE_UINT32_T

# FIXME: remove these two, this is currently needed by macro.h
AC_CHECK_SIZEOF([int])
AC_CHECK_SIZEOF([char *])

# Checks for library functions.
AC_SEARCH_LIBS([sqrt], [m])
AC_SEARCH_LIBS([crypt], [crypt])
AC_SEARCH_LIBS([malloc], [malloc])

AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_FUNC_WAIT3

AC_CHECK_FUNCS([atexit drand48 doprnt dup2 floor getcwd gethostname gettimeofday getpagesize memchr memmove memset mkdir munmap pow putenv regcomp rmdir setlocale socket sqrt strcasecmp strchr strcspn strerror strncasecmp strpbrk strrchr strstr strtol strtoul tzset utime])

AC_CHECK_FUNCS([getrusage])

# This check must before all F_HAVE_PREDEFINE checks.
# Checks local_options exist, use a grauntee exist predefine.
F_HAVE_PREDEFINE([__cplusplus], [], [AC_MSG_ERROR([[You must have local_options file, see options.h.]])])

# FluffOS need libevent 2.0+
AX_LIB_EVENT([2.0])
F_HAVE_PREDEFINE([HAVE_LIBEVENT], [],
  [AC_MSG_ERROR([[Fail to find libevent (2.0+) header/library, install libevent-dev or change --with_libevent]])])

# Checking local_options related libraries
F_HAVE_PREDEFINE([HAVE_ZLIB], [AC_SEARCH_LIBS([gzread], [z])])
F_HAVE_PREDEFINE([GCMALLOC], [AC_SEARCH_LIBS([GC_init], [gc])])
F_HAVE_PREDEFINE([PACKAGE_ASYNC], [AC_SEARCH_LIBS([pthread_create], [pthread])])
F_HAVE_PREDEFINE([POSIX_TIMERS], [AC_SEARCH_LIBS([timer_create], [rt])])

# iconv has redirect on CYGWIN.
F_HAVE_PREDEFINE([USE_ICONV], [AC_SEARCH_LIBS([iconv_open], [iconv])])
F_HAVE_PREDEFINE([USE_ICONV], [AC_SEARCH_LIBS([libiconv_open], [iconv])])

F_HAVE_PREDEFINE([USE_MSQL], [AC_SEARCH_LIBS([msqlConnect], [msql])])

F_HAVE_PREDEFINE([USE_MYSQL], [AX_LIB_MYSQL()])
F_HAVE_PREDEFINE([USE_MYSQL], [F_HAVE_PREDEFINE([HAVE_MYSQL], [],
  [AC_MSG_ERROR([[Fail to find MYSQL header/library, try changing --with_mysql flag]])])])

F_HAVE_PREDEFINE([USE_POSTGRES], [AX_LIB_POSTGRESQL()])
F_HAVE_PREDEFINE([USE_POSTGRES], [F_HAVE_PREDEFINE([HAVE_POSTGRESQL], [],
  [AC_MSG_ERROR([[Fail to find POSTGRESQL header/library, try changing --with_postgresql flag.]])])])

F_HAVE_PREDEFINE([USE_SQLITE3], [AX_LIB_SQLITE3()])
F_HAVE_PREDEFINE([USE_SQLITE3], [F_HAVE_PREDEFINE([HAVE_SQLITE3], [],
  [AC_MSG_ERROR([[Fail to find SQLITE3 header/library, try changing --with_sqlite3 flag.]])])])

F_HAVE_PREDEFINE([PACKAGE_CRYPTO], [AX_CHECK_OPENSSL([],
  [AC_MSG_ERROR([[Fail to find OPENSSL header/library, try changing --with_openssl flag.]])])])

F_HAVE_PREDEFINE([PACKAGE_PCRE], [AX_PATH_LIB_PCRE([],
  [AC_MSG_ERROR([[Fail to find PCRE header/library, try changing --with_pcre flag.]])])])

AC_SUBST([ARCH])
AC_SUBST([DRIVER_BIN])
AC_SUBST([OPTIMIZE])

AC_CONFIG_HEADERS([configure.h])
AC_CONFIG_FILES([Makefile packages/Makefile])

AC_OUTPUT
