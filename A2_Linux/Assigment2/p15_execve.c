/*
* Author     : Syamili S N
* Program    : p15_execve
* Description: demo execve()
*/


#include "run/headers.h"

int main(int argc, char* argv[]){
        printf("[parent~PID: %d]\n*******************\n", getpid());
        pid_t pid = fork();
        if(argc != 2){
                printf("Usage: Enter filename to be executed by child process.\n");
                return 1;
        }
        if (pid < 0)
                printf("[parent~PID:%d] fork failed! child not created.\n", getpid());
        else if(pid == 0){
                printf("[child~PID: %d] child running\n", getpid());
                execve(argv[1], argv, NULL);
        }
        else{
                wait();
                printf("[parent~PID: %d] parent running\n", getpid());
        }
        return 0;
}

