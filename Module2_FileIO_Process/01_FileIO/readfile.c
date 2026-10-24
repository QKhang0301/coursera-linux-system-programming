#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char** argv){
    int ret_val = -1;
    bool is_block = true;
    if (argc < 2){
        printf("Usage: %s file in [nonblock]\n", argv[0]);
        printf("    The file specified as \"filename\" will be created if it does not exist\n");
        printf("    If nonblock is specified, the file will be opened in non-bloking mode\n");
    } else if (argc > 3) {
        printf("Only the filename and nonblock parameter should be specified, no more\n");
    } else {
        const char* filename = argv[1];
        // If the "nonblocking" is specified
        if (argc == 3 && strncmp(argv[2], "nonblock", strlen("nonblock")) == 0){
            is_block = false;    
        }

        printf("Opening file \"%s\" in %sblocking mode\n", filename, (is_block)?"": "non-");
        /*Openning a fifi for read-only will be blocked until the fifo is opened for writing*/
        int fd = open(filename, O_RDONLY | 
                        is_block? O_RDWR : O_NONBLOCK,
                        S_IRWXG | S_IRWXO | S_IRWXU);
        
        /* Check if opening file has been failed*/
        if (fd == -1){
            printf("Error: Cannot opening file %s, error returned: %d (%s)\n", filename, errno, strerror(errno));
        } else {
            printf("Attempting reading 1 byte from file %s\n", filename);
            char buf[1];
            ssize_t read_len = read(fd, buf, 1);
            // Check for error EAGAIN in non-blocking mode
            if (read_len == -1){
                if(!is_block && errno == EAGAIN){
                    printf("EAGAIN return when reading, no data available to read\n");
                } else {
                    printf("ERROR reading %d (%s)\n", errno, strerror(errno));
                }
                ret_val = -errno;
            } else if(read_len == 0){ //empty file
               printf("Empty file, nothing to read\n"); 
               ret_val = 0;
            } else { //read successfully
                printf("Read sucessfully %ld bytes, the first byte is %c\n", read_len, buf[0]);
                ret_val = 0;
            }
        }
        
    }

    return ret_val;

}