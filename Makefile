CC = g++
CFLAGS = -O2
LDFLAGS = -L./
LIB_NAME = elists
PLATFORM = $(shell uname)
ifeq ($(PLATFORM), Linux)
	INSTALL_PATH = /usr/lib
	INCLUDE_PATH = /usr/include
else ifeq ($(PLATFORM), Darwin)
	INSTALL_PATH = /usr/local/lib
	INCLUDE_PATH = /usr/local/include
endif
.PHONY: examples

shared:
	$(CC) $(CFLAGS) -c -fpic $(LIB_NAME).cpp
	$(CC) $(CFLAGS) -shared -o lib$(LIB_NAME).so $(LIB_NAME).o

static:
	$(CC) $(CFLAGS) -c $(LIB_NAME).cpp
	ar rcs lib$(LIB_NAME).a $(LIB_NAME).o

install: shared static
	cp lib$(LIB_NAME).so $(INSTALL_PATH)
	cp lib$(LIB_NAME).a $(INSTALL_PATH)
	cp $(LIB_NAME).h $(INCLUDE_PATH)

uninstall:
	rm $(INSTALL_PATH)/lib$(LIB_NAME).so
	rm $(INSTALL_PATH)/lib$(LIB_NAME).a
	rm $(INCLUDE_PATH)/$(LIB_NAME).h

examples: static
	$(CC) $(CFLAGS) $(LDFLAGS) -o example example.cpp -l:lib$(LIB_NAME).a
	./example

clean:
	rm *.o *.a *.so example