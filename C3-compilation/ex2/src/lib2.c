#include <stdio.h>
#include <string.h>

size_t nb_chars= 0;

void mylib_puts(char* s)
{
	nb_chars += strlen(s);
	printf("Hello from libcustom2\n");
	puts(s);
}

//size_t mylib_getnbchars(void)
//{
//	printf("LIB2: nb_chars : %d\n", nb_chars);
//}
