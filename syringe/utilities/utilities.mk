INCLUDES = ../include
SOURCES = $(TARGET).c

LIBRARIES = syringe usb-1.0 curl z readline
LDFLAGS = -L../syringe -L/opt/local/lib

include ../common.mk