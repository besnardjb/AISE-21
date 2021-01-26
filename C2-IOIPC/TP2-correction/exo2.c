#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


#if 0
PARENT =====> FORK ====(CHILD1)=== DUP2 ===> EXEC ============||
              ||                      (W)\___________         ||
              ||                                     \ (R)    ||
              ||===(PARENT)==FORK==(CHILD2)===> DUP2 === EXEC=||===||
                             ||==(PARENT)=====================WAIT WAIT
#endif 



int main(int argc, char const *argv[])
{
    int pipefd[2];
    /* 0: R 1 : W 
    
       [0] (READ) <================ [1] (WRITE)
    
    */
    pipe(pipefd);   
 

    /* PARENT */
    printf("PARENT ONLY \n");

    pid_t child = fork();

    printf("Hello from %ld (%ld child)\n", getpid(), child);


    if(child == 0)
    {
        /* In CHILD */

        /* Replace STDOUT with write end of the pipe */
        dup2(pipefd[1], STDOUT_FILENO);
        /* STDOUT is the PIPE ! printf -> PIPE */
        close(pipefd[0]);
        close(pipefd[1]);

        fprintf(stderr, "COUCOU LES GARS\n");
        printf("8+4\n");

    }
    else
    {
        /* IN PARENT */
         pid_t child2 = fork();

        if(child2 == 0)
        {
            /* Second child */
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);

            char * bc[] = {"bc",NULL};
            execvp(bc[0], bc);
        }
        else
        {
            close(pipefd[0]);
            close(pipefd[1]);
            /* Parent */
            wait(NULL);
            wait(NULL);
        }

    }


    return 0;
}
