CC?=gcc
AR?=ar

all:first dynamic program

first:
	mkdir -p ./build/lib

dynamic: src/lib.c 
	$(CC) -shared -fPIC -o build/lib/libmymalloc.so $< -ldl

program: src/main.c
	$(CC) -o build/$@ $<

clean:
	rm -rf ./build/ 

.PHONY: dynamic program
