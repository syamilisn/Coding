#include "head1.h"
int main (){
	int FD1, FD2;
	FD1=open("/home/ee213031/Desktop/Coding/A2_Linux/emp.csv", O_RDONLY);
	FD2=open("ppp.log", O_RDONLY);
	printf("FD1: ");
	print(FD1);
	printf("FD2: ");
	print(FD2);

	if(FD2 == -1)
		perror("Message");
	return 0;
}
