/*
* Date       : 24-02-2023
* Program    : prog8
* Description: perform no change
*/


#include "../run/headers.h"

void signal_handler(int signal) {
printf("Signal %d received. No action taken.\n", signal);
}

int main() {
struct sigaction sa;
sa.sa_handler = &signal_handler;

if (sigaction(SIGINT, &sa, NULL) == -1) {
    printf("Error setting up signal handler.\n");
    return 1;
}

printf("Signal handler set up successfully. Waiting for signals...\n");

while (1) {
    sleep(1);
}

return 0;
}
