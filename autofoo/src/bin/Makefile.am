MAINTAINERCLEANFILES = Makefile.in

bin_PROGRAMS = efl_hello_world

efl_hello_world_CPPFLAGS = -I. \
-DPACKAGE_BIN_DIR=\"$(bindir)\" -DPACKAGE_LIB_DIR=\"$(libdir)\" \
-DPACKAGE_DATA_DIR=\"$(pkgdatadir)\" @AUTOFOO_CFLAGS@

efl_hello_world_LDADD = @AUTOFOO_LIBS@

efl_hello_world_SOURCES = \
efl_hello_world.c

