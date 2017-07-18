# Makefile created by monomake, Søn 19 Feb 2017 16:11:54 CET
# Project: simpletemp

MONO_PATH=$(subst \,/,$(shell monomake path --bare))
include $(MONO_PATH)/predefines.mk

TARGET=simpletemp

include $(MONO_PATH)/mono.mk
