#include "headers.h"
int main(){
	char *args[] = {"./p2", NULL};
	//execvp(args[0], args);
	execv(args[0], args);

	printf("Ending----");
	return 0;
}
