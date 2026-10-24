#include <stdio.h>
#include <stdlib.h> //for strtol()
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
    int ret_val = -1;
    // Check the number of input arguments
    if (argc != 3)
    {
        printf("Usage %s [filename] [size]\n", argv[0]);
        printf("    Create a file with specific size, or\n");
        printf("    Extend the file by a specific size\n");
        return ret_val;
    }

    char *filename = argv[1];
    errno = 0; // For checking strtol() result
    long size = strtol(argv[2], NULL, 10);
    // Check for overflow and underflow error
    if (errno == ERANGE)
    {
        printf("ERROR: Overflow/Underflow occur\n");
        ret_val = -errno;
        return ret_val;
    }

    printf("Creating file %s\n", filename);
    int fd = open(filename,
                  O_RDWR | O_CREAT,
                  S_IRWXG | S_IRWXO | S_IRWXU);
    // Check
    if (fd == -1)
    {
        printf("Error opening file, returned %d (%s)\n", errno, strerror(errno));
        ret_val = -errno;
    } else {
        off_t seek_size = lseek(fd, (off_t)size, SEEK_END);
        if (seek_size == -1)
        {
            printf("ERROR when extending file, returned %d (%s)", errno, strerror(errno));
            ret_val = -errno;
        } else {
            // Write 1 byte to a file
            int value = 12;
            ssize_t write_ret = write(fd, &value, sizeof(value));
            if(write_ret == -1){
                printf("ERROR write to file, returned %d (%s)\n", errno, strerror(errno));
                ret_val = -errno;
            } else if (write_ret != sizeof(value)){
                printf("There is PROBLEM in writing\n");
            } else {
                printf("Write the sparse file successfully\n");
                ret_val = 0;
            }
        }
    }
    return ret_val;
}