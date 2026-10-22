#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv){
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
        if (argc == 3 && strncmp(argv[2], "nonblock", strlen("nonblock"))){
            is_block = false;    
        }
        int fd = open(filename, )
    }

    printf("The string nonblock has length of %zu", strlen("nonblock"));


}