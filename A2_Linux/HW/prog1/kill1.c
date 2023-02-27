/*
* Date       : 24-02-2023
* Program    : kill
* Description: simulate KILL command
*/


#include "../run/headers.h"
int main(int argc, char *argv[]) {
   if (argc != 2) {
      printf("Usage: %s <pid>\n", argv[0]);
      exit(1);
   }
   
   int pid = atoi(argv[1]);
   int signal_num = SIGTERM; // Terminate the process

   if (kill(pid, signal_num) == -1) {
      perror("kill");
      exit(1);
   }

   printf("Process %d killed\n", pid);
   return 0;
}
