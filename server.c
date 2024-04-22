#include "minitalk.h"

int main (void) 
{
    pid_t pid;

    pid = getpid();
    printf("%u" , pid);
    return (0);
}
