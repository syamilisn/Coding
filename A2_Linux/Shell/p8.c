#include "header.h"
void main(){
	int fd = creat("temp.txt", O_WRONLY);
	if(fd == -1){
		perror("Msg:");
		exit(1);
	}
	write(fd, "Welcome\n", 9);
	//chmod("temp.txt", 0664);
	close(fd);
}
