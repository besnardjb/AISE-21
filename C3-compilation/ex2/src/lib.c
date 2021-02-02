#include <stdio.h>
#include <string.h>

size_t nb_chars= 0;

void mylib_puts(char* s)
{
	nb_chars += strlen(s);
	puts(s);
}

size_t mylib_getnbchars(void)
{
	printf("nb_chars : %d\n", nb_chars);
}
