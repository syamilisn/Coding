#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char* argv[]){
    struct stat file1, file2;
    if (argc != 3) {
        printf("Usage %s file1 file2",argv[0]);
    }
    else{
        if(stat(argv[1],&file1)<0)
		{
			perror("File1 : ");
			exit(EXIT_FAILURE);
		}
		if(stat(argv[2],&file2)<0)
		{
			perror("File2 : ");
			exit(EXIT_FAILURE);
		}
        printf("              f1    f2\n");
        printf("inode       : %ld %ld\n", file1.st_ino, file2.st_ino);
        printf("dev         : %ld %ld\n", file1.st_dev, file2.st_dev);
        printf("mode        : %d %d\n", file1.st_mode, file2.st_mode);
        printf("#ohardlinks : %ld %ld\n", file1.st_nlink, file2.st_nlink);

        if(file1.st_ino == file2.st_ino){
            printf("%s and %s are same files (SOFTLINKED)\n",argv[1],argv[2]);
        }
        else if(file1.st_ino != file2.st_ino){
            printf("%s and %s are same files (HARDLINKED)\n",argv[1],argv[2]);
        }
        else 
		{
			printf("%s and %s are not linked file\n",argv[1],argv[2]);
		}	
    }
    return 0;
}