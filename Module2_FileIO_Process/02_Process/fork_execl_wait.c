/*
Exercise: Combining fork and exec
    - Write a C program that uses `fork` to create a child process.
    - In the child process, use `execl` to run the `date` command.
    - The parent process should wait for the child to complete using `wait` 
        and then print "Child process finished".
*/



#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
int main(int argc, char** argv){
    // create a child process
    pid_t pid = fork();
    if(pid < 0){
        printf("ERROR: fork(), returned %d (%s)\n", errno, strerror(errno));
    } else if (pid == 0){
        //In child process
        printf("Hello from child process\n");
        // exec "date" 
        int ret_val = execl("/usr/bin/date", "date", "+\"%Y-%m-%d %H:%M:%S\"", (char*) NULL);
        if (ret_val == -1){
            printf("ERROR execl, return %d (%s)\n", errno, strerror(errno));
            return -1;
        }
    } else {
        // parrent process
        printf("The pid of child process is: %d\n",pid);
        //wait for the child process to terminate
        int status = 0;
        int ret_value = wait(&status);
        if(ret_value < 0){
            printf("ERROR wait(), returned %d (%s)\n", errno, strerror(errno));
        }
        // wait sucessfully, check the status
        if(WIFEXITED(status)){
            printf("The child process terminated normally\n");
        } else {
            printf("The there is something happened in child process\n");
        }
    }
    return 0;
}