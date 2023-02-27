/*
* Date       : 24-02-2023
* Program    : isr
* Description: send pause and raise signal
*/


#include "../run/headers.h"

volatile int is_paused = 0; // global flag to indicate if the ISR is paused

// Interrupt Service Routine (ISR)
void isr(int signal) {
    printf("ISR started.\n");
    while (1) {
        if (!is_paused) {
            // ISR code goes here
            printf("ISR running.\n");
        } else {
            printf("ISR paused.\n");
        }
        sleep(1); // simulate some work being done by the ISR
    }
}

int main() {
    // Register the ISR to handle SIGUSR1 and SIGUSR2 signals
    signal(SIGUSR1, isr);
    signal(SIGUSR2, isr);

    printf("Program started.\n");

    // Send SIGUSR1 signal to pause the ISR
    printf("Sending pause signal.\n");
    raise(SIGUSR1);
    is_paused = 1;

    // Wait for 5 seconds
    sleep(5);

    // Send SIGUSR2 signal to resume the ISR
    printf("Sending resume signal.\n");
    raise(SIGUSR2);
    is_paused = 0;

    // Wait for 5 more seconds
    sleep(5);

    // Exit the program
    printf("Program finished.\n");
    return 0;
}
