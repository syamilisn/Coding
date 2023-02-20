#include <stdio.h>
#define CAP

void main(){
#ifndef CAP
	printf("CAP is defined.\n");
#else
	printf("CAP not defined.\n");
#endif
}
