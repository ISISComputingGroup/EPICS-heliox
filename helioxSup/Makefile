TOP=..
include $(TOP)/configure/CONFIG
#=======================================

LIBRARY_IOC = HELIOX
DBD += heliox.dbd

HELIOX_DBD += asyn.dbd
HELIOX_DBD += asubFunctions.dbd

include $(GSL)/gsl_flags.mak

HELIOX_SRCS += line_of_best_fit.c

HELIOX_LIBS += $(EPICS_BASE_IOC_LIBS)
HELIOX_LIBS += asyn utilities
HELIOX_LIBS += asubFunctions
HELIOX_LIBS += gsl

DATA += heliox.proto
DATA += heliox_v.proto

DB += heliox.db
DB += heliox_channels.db
DB += heliox_regeneration.db

#=======================================
include $(TOP)/configure/RULES
