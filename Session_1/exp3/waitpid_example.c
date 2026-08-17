#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t child[3];
    int i;

    printf("Parent PID : %d\n\n", getpid());

    for(i = 0; i < 3; i++)
    {
        child[i] = fork();

        if(child[i] == 0)
        {
            printf("Child %d\n", i + 1);
            printf("PID  : %d\n", getpid());
            printf("PPID : %d\n", getppid());

            sleep(i + 2);

            printf("Child %d Completed\n\n", i + 1);
            exit(0);
        }
    }

    printf("Parent waiting using waitpid()\n\n");

    for(i = 0; i < 3; i++)
    {
        waitpid(child[i], NULL, 0);

        printf("Child with PID %d terminated.\n", child[i]);
    }

    printf("\nAll Child Processes Finished.\n");

    return 0;
}
