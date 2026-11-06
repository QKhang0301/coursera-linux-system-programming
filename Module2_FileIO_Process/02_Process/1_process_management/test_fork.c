#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
/*
    Create parrent process
    Use fork to create child process
    Print the PID of parrent and child
    Illustrate the "copy-on-write" concept with a varible

*/
int main(int argc, char** argv){
    bool is_parrent = true;
    printf("This is a parrent process\n");
    int copy_on_write_value = 100; // for parrent, It should be 50 in child process
    // Create a child process
    pid_t pid = fork();
    if (pid == 0){
        //in child process
        printf("Hello from child process\n");
        is_parrent = false;
        copy_on_write_value = 50;
    } else if (pid == -1){
        printf("Cannot create child process\n");
        return -1;
    }
    if(is_parrent){
        printf("The PID of child process is %d\n", pid);
    }

    
    printf("The value of the variable in %s process is %d\n", is_parrent?"parrent" : "child", copy_on_write_value);

    return 0;
}