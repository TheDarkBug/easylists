CC = g++
CFLAGS = -O2
LDFLAGS =
LIB_NAME = lists
PLATFORM = $(shell uname)
.PHONY: examples

ifeq ($(PLATFORM), Linux)
install: shared
	cp lib$(LIB_NAME).so /usr/lib
	cp lib$(LIB_NAME).a /usr/lib
endif

shared:
	$(CC) $(CFLAGS) -c -fpic $(LIB_NAME).cpp
	$(CC) $(CFLAGS) -shared -o lib$(LIB_NAME).so $(LIB_NAME).o

examples:
	$(CC) $(CFLAGS) $(LDFLAGS) -o example example.cpp -llists
	./example