/*
* Author     : Syamili S N
* Program    : p3_alarm
* Description: set an alarm for delivering of a signal including sleep
*/


#include "run/headers.h"

void handler(int signum) {
    printf("Alarm signal received!\n");
}

int main() {
    int num_alarms = 0;
    int alarm_times[4];
    signal(SIGALRM, handler);
    
    printf("Enter up to four alarm times in seconds (0 to stop):\n");
    
    // Read alarm times from user input
    for (int i = 0; i < 4; i++) {
        int time;
        printf("Alarm %d time (in seconds): ", i+1);
        scanf("%d", &time);
        if (time == 0) {
            break;
        }
        alarm_times[i] = time;
        num_alarms++;
    }
    
    // Set alarms using alarm() and sleep()
    for (int i = 0; i < num_alarms; i++) {
        printf("Setting alarm for %d seconds...\n", alarm_times[i]);
        alarm(alarm_times[i]);
        sleep(10); // Sleep for some time to allow the alarm to trigger
    }
    
    printf("Exiting program.\n");
    return 0;
}
