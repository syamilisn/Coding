/*
* Author     : Syamili S N
* Program    : p10_links
* Description: find link type
*/


#include "run/headers.h"
#include <stdlib.h>
#include <sys/stat.h>


int main(int argc,char *argv[])
{
	struct stat file1,file2;

	if(argc!=3)
	{
		printf("Usage %s file1 file2",argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
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
		
		if(file1.st_dev == file2.st_dev && file1.st_ino==file2.st_ino)
		{
			printf("%s and %s are hard linked file\n",argv[1],argv[2]);
		}
		else if(file1.st_mode == file2.st_mode && file1.st_ino == file2.st_ino)
		{
			printf("%s and %s are soft linked file\n",argv[1],argv[2]);
		}
		else 
		{
			printf("%s and %s are not linked file\n",argv[1],argv[2]);
		}	
	}
	
	return 0;
}
