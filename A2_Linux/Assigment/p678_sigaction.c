/*
* Author     : Syamili S N
* Program    : p678_sigaction.c
* Description: 1. new action, 2. old action, 3. no change
*/


#include "run/headers.h"

void myhandler(int num) {
    printf("signal that is recived= %d\n", num);
}

int main() {
    int ch;
    struct sigaction new_sig, old_sig;
    new_sig.sa_handler = myhandler;
    sigemptyset(&new_sig.sa_mask);
    new_sig.sa_flags = 0;

    while(1)
    {
    	printf("1. Set new signal handler\n");
    	printf("2. Get current signal handler\n");
    	printf("3. Change signal to default state\n");
	printf("4. No change\n");
	printf("Enter the choice to perform\n");
    	scanf("%d", &ch);
	 
   	switch (ch) {
        case 1:
            if (sigaction(SIGINT, &new_sig, &old_sig) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
            }
            printf("New signal handler set.\n");
            break;
        case 2:
            if (sigaction(SIGINT, NULL, &old_sig) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
            }
            if (old_sig.sa_handler == SIG_DFL) {
                printf("Current signal handler is the default behavior.\n");
            } else if (old_sig.sa_handler == SIG_IGN) {
                printf("Current signal handler is to ignore the signal.\n");
            } else {
                printf("Current signal handler is a user-defined function.\n");
            }
            break;
        case 3:
	    signal(SIGINT,SIG_DFL);
            printf("Signal behavior set to default.\n");
            break;
	case 4: 
	    printf("Signal behavior left unchanged\n");
	    break;
        default:
            printf("Invalid choice.\n");
            exit(EXIT_FAILURE);
   	 }
    
	
	
    printf("Waiting for signal...\n");
    pause();
    }

    return 0;
}

