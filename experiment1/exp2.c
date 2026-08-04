#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    printf("Hello\n");
    return 0;
}
