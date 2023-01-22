#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
main(){
	int fd1;
	char *buf1 = "I am a string\n";
	char *buf2 = "Second line\n";
	printf("======\n");
	fd1 = creat("./testCreat.txt", O_WRONLY);
	write(fd1, buf1, 20);
	write(fd1, buf2, 30);
	printf("fd1=%d buf1=%s\n", fd1, buf1);
	close(fd1);
	chmod("./testCreat.txt", 0666);
	printf("======\n");
}

