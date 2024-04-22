#include "minitalk.h"
#include <stdlib.h>

int main (int argc,char * argv[] ) {
    int pid ;
    char *message ;

    if (argc != 3)
    {
        write(1, "Usage: ./client [PID] [message]\n", 32);
        return (1);
    }

    pid = atoi(argv[1]);
    message = argv[2];

    printf("%s\n", message);

    kill(pid, SIGUSR1);
    kill(pid, SIGUSR2);

    return (0);
}
