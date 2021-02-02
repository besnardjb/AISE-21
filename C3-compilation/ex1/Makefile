CC?=gcc
AR?=ar

all:first static dynamic program

first:
	mkdir -p ./build/lib ./build/include

static: src/lib.c include/custom.h
	$(CC) -c $< -o build/lib.o
	$(AR) rcs build/lib/libcustom.a build/lib.o

dynamic: src/lib.c include/custom.h
	$(CC) -shared -fPIC -o build/lib/libcustom.so $<

program: src/main.c include/custom.h static dynamic
	$(CC) -o build/$@_dyn $< -I./include -L./build/lib -lcustom
	$(CC) -o build/$@_static -static $< -I./include -L./build/lib -lcustom

clean:
	rm -rf ./build/ 

.PHONY: static dynamic program
