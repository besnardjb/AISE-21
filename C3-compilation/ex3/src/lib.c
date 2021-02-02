#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
size_t alloc_count = 0;
size_t byte_count = 0;

void* (*funcname)(size_t)= NULL;
void *malloc(size_t size)
{
	alloc_count++;
	byte_count+=size;

	if(funcname == NULL)
	{
		write(1, "coucou\n", 7);
		funcname = (void*(*)(size_t))dlsym(RTLD_NEXT, "malloc");
		if(!funcname)
			abort();
	}
	return funcname(size);
}

__attribute((destructor))
void finalize()
{
	printf("byte_count: %d (with %d calls)\n", byte_count, alloc_count);
}
