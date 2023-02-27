/*
* Author     : Syamili S N
* Program    : p12_fifopipe
* Description: demo fifo pipe
read operation first
*/

#include "../run/headers.h"
#include<fcntl.h>


int main()
{
	int file_d;
	char read_d[50],write_d[50];
	
	while(1)
	{
		printf("Reading file\n");
		file_d = open("test1",O_RDONLY);
		
		read(file_d,read_d,20);
		printf("Data has been read and data = %s\n",read_d);
		close(file_d);
		
		file_d = open("test1",O_WRONLY);
		printf("Enter data to send \n");
		fgets(write_d,20,stdin);
		
		write(file_d,write_d,strlen(write_d)+1);
		printf("Data has been written\n");
		close(file_d);
		
		
	}
}


