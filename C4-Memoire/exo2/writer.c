#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#include <signal.h>
#include <string.h>
#include <stdio.h>

void func(int sig)
{
	printf("SIG %d\n", sig);
	if(sig != SIGUSR1)
	{
		printf("func() (handler)\n");
		abort();
	}
}

int main(int argc, char *argv[])
{
	pid_t pid = getpid();

	int fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd < 0)
	{
		printf("open(): %s\n",strerror(errno) );
		abort();
	}

	if(ftruncate(fd, 64) < 0)
	{
		printf("ftruncate(): %s\n", strerror(errno));
		abort();
	}

	void* p = mmap(NULL, 4096, PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		printf("mmap(): %s\n", strerror(errno));
	}

	memcpy(p+1024, &pid, sizeof(pid_t));

	if(signal(SIGUSR1, func) == SIG_ERR)
	{
		printf("Error w/ signal()\n");
		abort();
	}

	printf("Pause\n");
	pause();
	munmap(p, 64);
	close(fd);
	return 0;
}
