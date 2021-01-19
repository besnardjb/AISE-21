CC=gcc

all: main main_rpath

main: main.c libfoo.so
	$(CC)  main.c -lfoo -L. -o $@

main_rpath: main.c libfoo.so
	$(CC)  main.c -lfoo -Wl,-rpath $(PWD) -L. -o $@

libfoo.so: lib.c
	$(CC) -shared -fpic $^ -o $@

clean:
	rm -f ./main ./main_rpath ./libfoo.so
