#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define READ 0
#define WRITE 1
int main(){
        printf("*******************************************************************\n");
        int fd[2];
        pid_t process = fork();
        int status = pipe(fd);
        char buffer[100] = "hello world i am in a pipe";
        char buffer_out[100];
        char size = 100;
        if(process == 0){
                //      Step2: child reads from pipe
                printf("[child~%d] child executing ...\n", process);
                close(fd[WRITE]);
                read(fd[READ], buffer_out, size);
        printf("[%d] pipe_output = %s\n", process, buffer_out);
                close(fd[READ]);
//              exit(EXIT_SUCCESS);
        }
        else{
                //      Step1: Parent first writes to pipe and closes it
                printf("[parent~%d] parent executing ...\n", process);
                close(fd[READ]);
                write(fd[WRITE], buffer, size);
                close(fd[WRITE]);
                wait(NULL);
//              exit(EXIT_SUCCESS);

        }

        printf("[%d] pipe_status = %d; returns pipe() value; 0 - success, -1 - failure\n", process, status);
        printf("[%d] pipe_input = %s\n", process, buffer);
        printf("[%d] pipe_output = %s\n", process, buffer_out);
        return 0;
}

