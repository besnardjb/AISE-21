#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int fd = open("file.txt", O_RDONLY);
	if(fd < 0)
	{
		printf("open(): %s\n", strerror(errno));
		abort();
	}

	void *p = mmap(NULL, 64, PROT_READ, MAP_FILE | MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		printf("mmap(): %s\n", strerror(errno));
	}

	int pid = -1;
	memcpy(&pid, p, sizeof(pid_t));

	kill(pid, SIGUSR1);
	munmap(p, 64);
	close(fd);
	return 0;
}
