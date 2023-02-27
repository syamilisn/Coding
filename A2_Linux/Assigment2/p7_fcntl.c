/*
* Author     : Syamili S N
* Program    : p7_fcntl
* Description: demonstrate fcntl() call and use as a locking mechanism
*/


#include "run/headers.h"
#include <fcntl.h>

int main(int argc, char* argv[]){
	struct flock lock;
	char *file = argv[1];
	int fd;
	if(argc != 2){
		printf("Usage: Enter filename (sample.txt)\nThe file can't be locked again if it is already locked in another terminal.\n");
		return 1;
	}

	printf("Opening file %s\n", file);
	fd = open(file, O_WRONLY);
	printf("Locking %s file\n", file);
	memset(&lock, 0, sizeof(lock));
	lock.l_type = F_WRLCK;
	fcntl(fd, F_SETLKW, &lock);
	printf("File locked successfully!!\nPress enter to unlock:\n");
	getchar();
	printf("Unlocking %s file\n", file);
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLKW, &lock);
	close(fd);
	return 0;
}
