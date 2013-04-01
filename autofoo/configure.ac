dnl Process this file with autoconf to produce a configure script.

# get rid of that stupid cache mechanism
rm -f config.cache

AC_INIT([autofoo], [0.0.1], [jeremy@asynk.ch])
AC_PREREQ([2.65])
AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([autofoo_config.h])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST

AM_INIT_AUTOMAKE([1.10 dist-bzip2])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# this will speed up libtool checks
LT_PREREQ([2.2])
LT_INIT([win32-dll])

AC_PROG_CC
AM_PROG_CC_C_O
EFL_ATTRIBUTE_VECTOR
EFL_ATTRIBUTE_ALWAYS_INLINE

# Checks for header files.
EFL_CHECK_PATH_MAX

requirements_autofoo="\
   eina >= 1.7.0 \
   eet >= 1.7.0 \
   evas >= 1.7.0 \
   ecore >= 1.7.0 \
   edje >= 1.7.0 \
   elementary >= 1.7.0 \
   "
PKG_CHECK_MODULES([AUTOFOO], [${requirements_autofoo}])

# Check edje_cc
EFL_WITH_BIN([edje], [edje-cc], [edje_cc])

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

with_max_log_level="EINA_LOG_LEVEL_ERR"
AC_ARG_WITH(maximum-log-level,
   [AC_HELP_STRING([--with-maximum-log-level=NUMBER],
                   [limit autofoo log level to the given number, any call to EINA_LOG() with values greater than this will be compiled out, ignoring runtime settings, but saving function calls.])],
   [
    if test "x${withval}" != "xno"; then
       if echo "${withval}" | grep -E '^[[0-9]]+$' >/dev/null 2>/dev/null; then
          AC_MSG_NOTICE([ignoring any EINA_LOG() with level greater than ${withval}])
          with_max_log_level="${withval}"
       else
          AC_MSG_ERROR([--with-maximum-log-level takes a decimal number, got "${withval}" instead.])
       fi
    fi
    ], [:])

AC_DEFINE_UNQUOTED(EINA_LOG_LEVEL_MAXIMUM, ${with_max_log_level}, [if set, logging is limited to this amount.])

AM_GNU_GETTEXT_VERSION([0.18])

EFL_CHECK_COMPILER_FLAGS([AUTOFOO], [-Wall -Wshadow -Wextra -Wpointer-arith -Wno-missing-field-initializers -fvisibility=hidden -fdata-sections -ffunction-sections])
EFL_CHECK_LINKER_FLAGS([AUTOFOO], [-fvisibility=hidden -fdata-sections -ffunction-sections -Wl,--gc-sections -fno-strict-aliasing -Wl,--as-needed -Wl,--no-copy-dt-needed-entries])

AC_CONFIG_FILES([
Makefile
src/Makefile
src/bin/Makefile
])

AC_OUTPUT

#####################################################################
## Info

echo
echo
echo
echo "------------------------------------------------------------------------"
echo "$PACKAGE $VERSION"
echo "------------------------------------------------------------------------"
echo
echo "Configuration Options Summary:"
echo "  EINA_LOG() max level.....: $with_max_log_level"
echo
echo "Compilation................: make (or gmake)"
echo "  CPPFLAGS.................: $CPPFLAGS"
echo "  CFLAGS...................: $CFLAGS"
echo "  LDFLAGS..................: $LDFLAGS"
echo
echo "Installation...............: make install (as root if needed, with 'su' or 'sudo')"
echo "  prefix...................: $prefix"
echo
