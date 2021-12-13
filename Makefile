CC = g++
CFLAGS = -O2
LDFLAGS = -L./
LIB_NAME = lists
PLATFORM = $(shell uname)
.PHONY: examples

ifeq ($(PLATFORM), Linux)
install: shared static
	cp lib$(LIB_NAME).so /usr/lib
	cp lib$(LIB_NAME).a /usr/lib
endif

shared:
	$(CC) $(CFLAGS) -c -fpic $(LIB_NAME).cpp
	$(CC) $(CFLAGS) -shared -o lib$(LIB_NAME).so $(LIB_NAME).o

static:
	$(CC) $(CFLAGS) -c $(LIB_NAME).cpp
	ar rcs lib$(LIB_NAME).a $(LIB_NAME).o

examples: static
	$(CC) $(CFLAGS) $(LDFLAGS) -o example example.cpp -l:liblists.a
	./example