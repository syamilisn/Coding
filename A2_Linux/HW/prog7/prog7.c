/*
* Date       : 24-02-2023
* Program    : prog7
* Description: perform new and old action
*/


#include "../run/headers.h"

void handle_signal(int signal) {
    printf("Caught signal %d.\n", signal);
}

int main() {
    struct sigaction new_action, old_action;

    // Set up the new action for SIGINT (Ctrl+C)
    new_action.sa_handler = handle_signal;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;

    // Install the new action
    if (sigaction(SIGINT, &new_action, &old_action) < 0) {
        perror("sigaction");
        exit(1);
    }

    printf("New signal handler installed. Press Ctrl+C to trigger.\n");

    // Wait for a signal to arrive
    pause();

    // Restore the old action
    if (sigaction(SIGINT, &old_action, NULL) < 0) {
        perror("sigaction");
        exit(1);
    }

    printf("Old signal handler restored. Press Ctrl+C to trigger again.\n");

    // Wait for another signal to arrive
    pause();

    return 0;
}
