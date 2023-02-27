/*
* Date       : 24-02-2023
* Program    : fifopipe
* Description: demo fifo pipe
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define FIFO_NAME "myfifo"

int main()
{
pid_t pid;
char message[BUFFER_SIZE];

scss
Copy code
// Create a FIFO pipe
if (mkfifo(FIFO_NAME, 0666) < 0)
{
    perror("Error creating FIFO pipe");
    exit(EXIT_FAILURE);
}

// Fork a child process
pid = fork();

if (pid < 0)
{
    perror("Error forking child process");
    exit(EXIT_FAILURE);
}
else if (pid == 0)
{
    // Child process - read from FIFO pipe
    int fd = open(FIFO_NAME, O_RDONLY);
    read(fd, message, BUFFER_SIZE);
    printf("Child process received message: %s\n", message);
    close(fd);
}
else
{
    // Parent process - write to FIFO pipe
    int fd = open(FIFO_NAME, O_WRONLY);
    printf("Enter message to send to child process: ");
    fgets(message, BUFFER_SIZE, stdin);
    write(fd, message, strlen(message)+1);
    close(fd);

    // Wait for child process to finish
    wait(NULL);

    // Remove the FIFO pipe
    unlink(FIFO_NAME);
}

return 0;
}
