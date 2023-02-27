#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal) {
  // Do nothing
}

int main() {
  // Disable Ctrl+C and Ctrl+\ signals
  signal(SIGINT, signal_handler);
  signal(SIGQUIT, signal_handler);
	
  int i=1;
  // Wait for 10 seconds
  while(1)
  {
	if(i==10)
	{
		signal(SIGINT,SIG_DFL);
		signal(SIGQUIT,SIG_DFL);
	}	
      printf("Hello\n");
	sleep(1);      
	i++;
  }

  // Restore default signal handlers
 // signal(SIGINT, SIG_DFL);
 // signal(SIGQUIT, SIG_DFL);

  // Do other work here
  printf("Signals enabled again.\n");

  return 0;
}

