#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

#define SIZE 1024

int main(int argc, char *argv[])
{
	int fd = open("libsquare.o", O_RDONLY);
	if(fd < 0)
	{
		printf("open(): %s\n", strerror(errno));
		abort();
	}

	void *p = mmap(NULL, 1024, PROT_READ|PROT_EXEC, MAP_FILE | MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		printf("mmap(): %s\n", strerror(errno));
	}

	size_t (*func)(int) = NULL;
	func = (size_t(*)(int))p;

	int i = 4;
	printf("square of %d: %lu\n", i, func(i) );

	munmap(p, SIZE);
	close(fd);
	return 0;
}
