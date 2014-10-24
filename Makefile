# $PostgreSQL $

MODULE_big = hammingnn
OBJS = hammingnn.o hammingcheck16.o hammingcheck32.o
DATA_built = hammingnn.sql
DATA = uninstall_hammingnn.sql

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/hammingnn
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
