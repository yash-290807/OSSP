#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Creating Child Process...\n\n");

    pid = fork();

    if (pid < 0)
    {
        printf("Fork Failed!\n");
        return 1;
    }
    else if (pid == 0)
    {
        printf("========== CHILD PROCESS ==========\n");

        printf("Child PID          : %d\n", getpid());
        printf("Parent PID (PPID)  : %d\n", getppid());
        printf("Process State      : Running\n");

        sleep(5);

        printf("Process State      : Terminated\n");
    }
    else
    {
        printf("========== PARENT PROCESS ==========\n");

        printf("Parent PID         : %d\n", getpid());
        printf("Child PID          : %d\n", pid);
        printf("Process State      : Waiting\n");

        wait(NULL);

        printf("Process State      : Running\n");
        printf("Child Process Completed.\n");
    }

    return 0;
}
