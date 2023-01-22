#include <sys/stat.h>
#include "header.h"
void main(){
	int fd1, fd2, fd3;
	struct stat bufstat1, bufstat2;
	char buf1[20], buf2[20];
	printf("======\n");
	fd1 = open("/etc/passwd", O_RDONLY);
	fd2 = open("./p9.c", O_RDONLY);
	fstat(fd1, &bufstat1);
	fstat(fd2, &bufstat2);
	printf("fd1=%d inode no=%ld block size=%ld blocks=%ld\n", fd1, bufstat1.st_ino, bufstat1.st_blksize, bufstat1.st_blocks);
	printf("fd2=%d inode no=%ld block size=%ld blocks=%ld\n", fd2, bufstat2.st_ino, bufstat2.st_blksize, bufstat2.st_blocks);
	printf("======\n");
}
