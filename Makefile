TOP=..
include $(TOP)/configure/CONFIG

OPT_CXXFLAGS_YES = -O3

CXXFLAGS += -pedantic-errors
CXXFLAGS += -Wextra -Werror
CXXFLAGS += -Wno-long-long

LIBRARY_IOC += exprtkSupport

INC += exprtkWrap.h
INC += exprtkIF.h

exprtkSupport_SRCS += exprtkIF.cpp
exprtkSupport_SRCS += exprtkImp.cpp
exprtkSupport_SRCS += exprtkWrap.cpp


#=============================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

