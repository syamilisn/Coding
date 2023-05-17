#include <stdio.h>

void main(){
	if(fork() == 0)
		if(fork() == 0)
			if(fork() == 0)
			if(fork() == 0)
			if(fork() == 0)
				printf("[%d] hello\n", getpid());
}
