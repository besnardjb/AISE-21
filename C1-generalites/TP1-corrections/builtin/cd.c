#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc == 1)
		return 0;


	chdir(argv[1]);
	

	return 0;
}
