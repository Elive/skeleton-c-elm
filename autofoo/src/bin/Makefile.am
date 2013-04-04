MAINTAINERCLEANFILES = Makefile.in

bin_PROGRAMS = efl_hello_world efl_hello_world_ql

AM_CPPFLAGS = -I. \
   -I$(top_srcdir) \
   -I$(top_srcdir)/src/lib \
   -DPACKAGE_BIN_DIR=\"$(bindir)\" \
   -DPACKAGE_LIB_DIR=\"$(libdir)\" \
   -DPACKAGE_DATA_DIR=\"$(datadir)/$(PACKAGE)\" \
   @ELEMENTARY_CFLAGS@ \
   @EVIL_CFLAGS@

efl_hello_world_SOURCES = \
   efl_hello_world.c

efl_hello_world_LDADD = \
   $(top_builddir)/src/lib/libeflhelloworld.la \
   @ELEMENTARY_LIBS@ \
   @EVIL_LIBS@

efl_hello_world_CFLAGS = @ELEMENTARY_CFLAGS@
efl_hello_world_LDFLAGS =

# QuickLaunch
efl_hello_world_qldir = $(libdir)
efl_hello_world_ql_LTLIBRARIES = efl_hello_world_ql.la

efl_hello_world_ql_la_SOURCES = $(efl_hello_world_SOURCES)
efl_hello_world_ql_la_LIBADD = $(efl_hello_world_LDADD)
efl_hello_world_ql_la_CFLAGS =
efl_hello_world_ql_la_LDFLAGS = -module -avoid-version -no-undefined

efl_hello_world_ql_SOURCES = $(efl_hello_world_SOURCES)
efl_hello_world_ql_LDADD = $(efl_hello_world_LDADD)
efl_hello_world_ql_CFLAGS = -DELM_LIB_QUICKLAUNCH=1
efl_hello_world_ql_LDFLAGS =


