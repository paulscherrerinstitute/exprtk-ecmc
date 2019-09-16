TOP=../..
include $(TOP)/configure/CONFIG

OPT_CXXFLAGS_YES = -O3


LIBRARY_IOC += exprtkSupport

INC += exprtkWrap.h
INC += exprtkIF.h

exprtkSupport_SRCS += exprtkIF.cpp
exprtkSupport_SRCS += exprtkImp.cpp
exprtkSupport_SRCS += exprtkWrap.cpp


exprtkSupport_LIBS += $(EPICS_BASE_IOC_LIBS)



#=============================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

