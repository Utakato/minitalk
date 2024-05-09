#include "minitalk.h"
#include <stdlib.h>

// 01100001 = a
void check_bits(char letter, int pid) {
    int is_one;
    int i = 0;
    
    printf("letter is: %i \n", letter);
    while (i < 7)
    {
        is_one = letter & '@';
        if (is_one == '@')
        {   
            printf("sent 1\n");
            kill(pid, SIGUSR1);
        }
        else {
            printf("sent 0\n");
            kill(pid, SIGUSR2);
        }
        letter = letter << 1;
        i++;
        // usleep(100);
    }
    
}


int main (int argc,char * argv[] ) {
    int pid ;
    int i;
    char *message ;

    if (argc != 3)
    {
        write(1, "Usage: ./client [PID] [message]\n", 32);
        return (1);
    }

    i = 0;
    pid = atoi(argv[1]);
    message = argv[2];

    printf("%s\n", message);
    while (message[i])
    {
        check_bits(message[i], pid);
        i++;
    }

    return (0);
}

