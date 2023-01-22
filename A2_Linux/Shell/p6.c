#include "head1.h"
int main(){
	int fd1, newfd;
	char buf1[20], buf2[20];
	fd1 = open("IP.txt", O_RDONLY);
	if(fd1 == -1){
		perror("msg");
		exit(1);
	}
	newfd = dup(fd1);
	read(fd1, buf1, 3);
	printf("%s\n", buf1);
	read(newfd, buf2, 3);
	printf("%s\n", buf2);

	return 0;
}
