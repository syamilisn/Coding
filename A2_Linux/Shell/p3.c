#include "head1.h"
int main (){
	int fd;
	char buf1[20];
	fd=open("IP.txt",O_RDONLY);
	if(fd == -1){
		perror("Message");
		exit(1);
	}
	read(fd, buf1, 12);
	printf("%s\n", buf1);
	return 0;
}
