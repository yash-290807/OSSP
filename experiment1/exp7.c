#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
    {
        printf("Child executing ls...\n");
        execl("/bin/ls","ls","-l",NULL);
    }
    else
    {
        printf("Parent Waiting...\n");
    }

    return 0;
}
