#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
/*  Code pratice on wait()
1. Write a C program that:
    - Forks a child process.
    - The child process prints "Child process running" and then exits with status 5.
    - The parent process waits for the child to terminate using wait().
    - After wait() returns, the parent prints the child's exit status.
*/
int main(int argc, char** argv){
    // Create a child process
    pid_t pid = fork();
    // Check fork
    if (pid < 0){
        // Error
        perror("fork"); 
    } else if (pid == 0){
        // Child process
        printf("Child process is running\n");
        return (5);
    } else {
        // Parrent process
        int status = 0;
        printf("The child pid process is %d\n", pid);
        pid_t child_pid = wait(&status);
        if (child_pid == -1){
            perror("wait");
        }
        printf("The child pid returned by wait() API is %d\n", child_pid);
        if (WIFEXITED(status)){
            printf("Child process exited normally with exit code %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process existed abnormally\n");
        }

    }
    
    return 0;
    
}