#include "header.h"
void main(){
	char string[20];
	int fd_source=open("file.txt", O_WRONLY);
	write(fd_source, "my name is shyam", 16);
	int fd_target=creat("file2.txt", O_RDONLY);
	link("file.txt", "file2.txt");
	read(fd_source, "my name is shyam", 16);
	read(fd_target, string, 16);
	close(fd_source);
	close(fd_target);
}
