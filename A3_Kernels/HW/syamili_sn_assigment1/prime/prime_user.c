#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>


struct prime_drv_data {
    int start;
    int end;
    int flags;
};

#define WR_VALUE _IOW('a','a',struct prime_drv_data*)
#define RD_VALUE _IOR('a','b',struct prime_drv_data*)
 

char read_buf[1024];


int main()
{
        int fd;
        int prev=0,curr;
        struct prime_drv_data  number;
 
        printf("\nOpening Driver\n");
        fd = open("/dev/etx_device", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }
 
        printf("Enter the Value to send\n");
        scanf("%d",&number.start);
        scanf("%d",&number.end);
        number.flags=0;
        printf("Writing Value to Driver\n");
        ioctl(fd, WR_VALUE, &number); 
 
        /*printf("Reading Value from Driver\n");
        ioctl(fd, RD_VALUE, (int32_t*) &value);
        printf("Value is %d\n", value);*/
 	for(int i=number.start;i<number.end;i++)
 	{
 		read(fd, read_buf, 1024);
 		curr = atoi(read_buf);
 		if(prev==curr)
 			break;
 		prev=curr;
 		read_buf[1024]='\0';
        	printf("Data = %s\n", read_buf);
 	}
 	
 	
 	
        printf("Closing Driver\n");
        close(fd);
}
