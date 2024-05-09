#include "minitalk.h"


void signal_handler(int signum)
{
    static char letter;
    static int i;

    if (i <= 6) {
        letter = letter << 1;
        if (signum == SIGUSR1)
            letter = letter | 1;
        i++;
    } 
    if (i == 7) {
        write(1, &letter, 1);
        letter = 0;
        i = 0;
    }
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
