CC?=gcc
AR?=ar

all:first program

first:
	mkdir -p ./build/lib/lib1/ ./build/lib/lib2/ ./build/include

libcustom.so: src/lib.c include/custom.h
	$(CC) -shared -fPIC -o build/lib/lib1/libcustom.so $<

libcustom2.so: src/lib2.c include/custom.h
	$(CC) -shared -fPIC -o build/lib/lib2/libcustom.so $<

program: src/main.c include/custom.h libcustom.so libcustom2.so
	$(CC) -o build/$@_dyn $< -I./include -L./build/lib/lib1 -lcustom

clean:
	rm -rf ./build/ 

.PHONY: libcustom.so libcustom2.so program
