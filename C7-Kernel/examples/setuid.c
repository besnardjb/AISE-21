#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	fprintf(stderr, "BEFORE my uid %d\n", getuid());

	if( setuid(0) < 0)
	{
		perror("setuid");
	}

	fprintf(stderr, "AFTER my uid %d\n", getuid());

	return 0;
}
