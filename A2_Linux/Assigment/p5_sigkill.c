/*
* Author     : Syamili S N
* Program    : p5_sigkill
* Description: program to limit the life of a process of 5 sec. After 5 sec, the process itself has to terminate by raise the SIGKILL signal
*/


#include "run/headers.h"

void handle_signal(int sig)
{
    if (sig == SIGALRM) {
        printf("Process terminated after 5 seconds\n");
        kill(getpid(), SIGKILL);
    }
}

int main()
{
    struct sigaction sa;
    // Set up signal handler for SIGALRM
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    // Set alarm for 5 seconds
    alarm(5);

    while (1) {
        printf("Process running...\n");
        sleep(1);
    }

    return 0;
}
