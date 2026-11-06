/*
Exercise: Check Process User and Group IDs
- Write a C program that creates a child process using fork().
- In the child process, print the real user ID, effective user ID, real group ID, and effective group ID.
- Use system calls like getuid(), geteuid(), getgid(), and getegid() to retrieve these IDs.
- Observe how these IDs differ between the parent and child processes.
*/
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
int main(int argc, char** argv){
    bool is_parrent = true;
    //create child process using fork()
    pid_t pid = fork();
    //check the fork operation
    if (pid < 0){
        printf("Error: fork(), returned %d (%s)\n", errno, strerror(errno));
    } else if (pid == 0){
        // Child process
        printf("Hello from child process\n");
        is_parrent = false;
    } else{
        // parrent process
        printf("Hello from parrent process\n");
        printf("The child pid is %d\n", pid);
    }

    //print the read & effective uid, gid
    printf("The real uid for %s process is: %d\n", is_parrent?"parrent":"child", getuid()); 
    printf("The effective uid for %s process is: %d\n", is_parrent?"parrent":"child", geteuid()); 
    printf("The real gid for %s process is: %d\n", is_parrent?"parrent":"child", getgid()); 
    printf("The effective gid for %s process is: %d\n", is_parrent?"parrent":"child", getegid()); 

    return 0;
}