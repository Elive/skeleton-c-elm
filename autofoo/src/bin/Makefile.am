MAINTAINERCLEANFILES = Makefile.in

bin_PROGRAMS = efl_hello_world efl_hello_world_ql

AM_CPPFLAGS = -DPACKAGE_BIN_DIR=\"$(bindir)/$(PACKAGE)\" \
              -DPACKAGE_LIB_DIR=\"$(libdir)/$(PACKAGE)\" \
              -DPACKAGE_DATA_DIR=\"$(datadir)/$(PACKAGE)\" \
              @AUTOFOO_CFLAGS@

efl_hello_world_SOURCES = \
efl_hello_world.c

# QuickLaunch
efl_hello_world_ql_SOURCES = $(efl_hello_world_SOURCES)
efl_hello_world_ql_LTLIBRARIES = efl_hello_world_ql.la
efl_hello_world_ql_CFLAGS = -DELM_LIB_QUICKLAUNCH=1
efl_hello_world_ql_LDFLAGS = @AUTOFOO_LIBS@

efl_hello_world_qldir = $(libdir)
efl_hello_world_ql_la_LIBADD = @AUTOFOO_LIBS@
efl_hello_world_ql_la_CFLAGS =
efl_hello_world_ql_la_LDFLAGS = -module -avoid-version -no-undefined
efl_hello_world_ql_la_SOURCES = $(efl_hello_world_SOURCES)

efl_hello_world_LDADD = @AUTOFOO_LIBS@
efl_hello_world_LDFLAGS = $(LTLIBINTL)

