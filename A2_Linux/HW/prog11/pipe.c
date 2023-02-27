/*
* Date       : 24-02-2023
* Program    : pipe
* Description: demo pipe
*/


#include "../run/headers.h"

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
    char write_msg[BUFFER_SIZE] = "Hello, world!";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        fprintf(stderr,"Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if (pid > 0) {  // parent process
        close(fd[READ_END]);  // close unused read end of the pipe

        write(fd[WRITE_END], write_msg, strlen(write_msg)+1);  // write message to the pipe

        close(fd[WRITE_END]);  // close write end of the pipe

        printf("Parent wrote '%s' to the pipe\n", write_msg);
    }
    else {  // child process
        close(fd[WRITE_END]);  // close unused write end of the pipe

        read(fd[READ_END], read_msg, BUFFER_SIZE);  // read message from the pipe

        printf("Child read '%s' from the pipe\n", read_msg);

        close(fd[READ_END]);  // close read end of the pipe
    }

    return 0;
}

