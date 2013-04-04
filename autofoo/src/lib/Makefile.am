MAINTAINERCLEANFILES = Makefile.in

AM_CPPFLAGS = -I. \
   -I$(top_srcdir) \
   -I$(top_srcdir)/src/lib \
   -DPACKAGE_BIN_DIR=\"$(bindir)\" \
   -DPACKAGE_LIB_DIR=\"$(libdir)\" \
   -DPACKAGE_DATA_DIR=\"$(datadir)/$(PACKAGE)\" \
   @ELEMENTARY_CFLAGS@ \
   @EVIL_CFLAGS@

includes_HEADERS = efl_hello_world.h
includesdir = $(includedir)/efl_hello_world-@VMAJ@

lib_LTLIBRARIES = libeflhelloworld.la

libeflhelloworld_la_SOURCES = efl_hello_world.c
libeflhelloworld_la_LIBADD = @ELEMENTARY_LIBS@ @EVIL_LIBS@ -lm
libeflhelloworld_la_LDFLAGS = -no-undefined @lt_enable_auto_import@ -version-info @version_info@ @release_info@

