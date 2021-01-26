#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main( int argc, char *argv[])
{
    int out = open("./out.dat", O_CREAT | O_WRONLY | O_APPEND, 0600);

    if(out < 0)
    {
        perror("open");
        return 1;
    }

    dup2(out, STDOUT_FILENO);
    close(out);

    int i;
    for(i = 0 ; i < 4096; i++)
    {
        printf("%d\n", i);
    }


    return 0;
} 