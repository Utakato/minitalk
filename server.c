#include "minitalk.h"


void signal_handler(int signum)
{
    if (signum == SIGUSR1)
        write(1, "0", 1);
    else if (signum == SIGUSR2)
        write(1, "1", 1);
}

int main (void) 
{
    pid_t pid;

    pid = getpid();
    printf("the process id oasdasdf the server is: %u\n" , pid);

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
        continue;
    
    return (0);
}
