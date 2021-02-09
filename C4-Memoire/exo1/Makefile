all: main

libmystring.so: string.c mystring.h
	gcc -o $@ $< -shared -fPIC

main: main.c libmystring.so
	gcc -o $@ $< -I. -L. -lmystring  
