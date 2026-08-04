#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    fork();

    printf("PID = %d\n", getpid());

    return 0;
}
