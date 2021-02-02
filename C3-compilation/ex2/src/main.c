#include "custom.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	mylib_puts("Hello");
	mylib_puts(" guys!\n");

	printf("nb_chars = %lu\n", mylib_getnbchars());
	
	return 0;
}
