/*
* Author     : Syamili S N
* Program    : p9_filesize
* Description: find file size without opening the file using systme call
*/


#include "run/headers.h"
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat st;
    int result;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    result = stat(argv[1], &st);
    if (result != 0) {
        perror("stat");
        return 1;
    }

    printf("Size of %s is %ld bytes\n", argv[1], st.st_size);

    return 0;
}

