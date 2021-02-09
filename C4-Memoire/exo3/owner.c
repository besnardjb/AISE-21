#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#include <signal.h>
#include <string.h>
#include <stdio.h>

size_t square(int n)
{
	return n * n;
}
void end_square() {}

int main(int argc, char *argv[])
{
	int fd = open("libsquare.o", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd < 0)
	{
		printf("open(): %s\n",strerror(errno) );
		abort();
	}
	
	size_t size_to_copy = (char*)end_square - (char*)square;
	if(ftruncate(fd, size_to_copy) <0)
	{
		printf("ftruncate(): %s\n",strerror(errno) );
		abort();
	}

	void* p = mmap(NULL, size_to_copy, PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		printf("mmap(): %s\n", strerror(errno));
		abort();
	}

	memcpy(p, (void*)square, size_to_copy);

	munmap(p, 64);
	close(fd);
	return 0;
}
