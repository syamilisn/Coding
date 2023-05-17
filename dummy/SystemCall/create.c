#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char buffer[100] = "I am shyam";
	int count = strlen(buffer);
	int fd = open("foo.txt", 666);
	printf("fd = %d\n", fd);
	if(fd < 0){
		perror("open");
		exit(1);
	}

	if(write(fd, buffer, count) < 0){
		perror("write");
		exit(1);
	}
	if(close(fd) < 0){	
		perror("write");
		exit(1);
	}
}
