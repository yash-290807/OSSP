#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int i;

    printf("Parent Process PID : %d\n\n", getpid());

    for(i = 1; i <= 3; i++)
    {
        pid_t pid = fork();

        if(pid == 0)
        {
            printf("Child %d Created\n", i);
            printf("PID  : %d\n", getpid());
            printf("PPID : %d\n", getppid());

            sleep(i + 1);

            printf("Child %d Finished\n\n", i);
            exit(0);
        }
    }

    printf("Parent waiting for all child processes...\n\n");

    for(i = 1; i <= 3; i++)
    {
        wait(NULL);
        printf("One child process completed.\n");
    }

    printf("\nAll Child Processes Completed.\n");

    return 0;
}
