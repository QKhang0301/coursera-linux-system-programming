#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/*
 Program which execute "ls" utility with given directory

*/
int main(int argc, char** argv){
    int ret_val = -1;
    if(argc != 2){
        printf("Usage test_excel <directory_path>\n");
        return ret_val;
    }

    // Check if the given path is valid
    const char* path = argv[1];
    if(access(path, F_OK) == 0){
        int result = execl("/usr/bin/ls", "ls", path, NULL);
        if (result == -1){
            printf("Error, cannot exec the \"ls\" utility\n");
        }
    } else {
        printf("ERROR: The path does not exist, return %d (%s)\n", errno, strerror(errno));
        return ret_val;
    }

    return 0;

}
