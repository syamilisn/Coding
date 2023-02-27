/*
* Date       : 24-02-2023
* Program    : kill
* Description: simulate KILL command
*/


#include "../run/headers.h"
void handler(int sig) {
    printf("Signal %d received\n", sig);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        exit(1);
    }

    int pid = atoi(argv[1]);

    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    if (kill(pid, SIGTERM) == -1) {
        perror("kill");
        exit(1);
    }

    printf("Sent SIGTERM to process %d\n", pid);

    return 0;
}
