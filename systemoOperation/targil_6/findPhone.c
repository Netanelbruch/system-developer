#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int findPhone(char* argv[]) {
    
    int pipes[2];
    int pidGrep;
    int pidCut;
    int pidSed;



    //this creates the pipe.pipes[0] is for reading,and pipes[1] is for writing.
    if (pipe(pipes) == -1)
    {
        perror("Error in create pipe!");
        return 1;
    }

    //first child process -grep:
    if ((pidGrep = fork()) == 0)
    {
        dup2(pipes[1], STDOUT_FILENO);
        close(pipes[0]);
        close(pipes[1]);
        execlp("grep", "grep", argv[1], "phoneBook.txt", NULL);
        perror("Error in execlp()");
        return -1;
    }
    else if (pidGrep == -1)
    {
        perror("Error in fork()- pidGrep");
        return -1;
    }

    //second child process -cut:
    if ((pidCut = fork()) == 0) {
        dup2(pipes[0], STDIN_FILENO);
        close(pipes[0]);
        close(pipes[1]);
        execlp("cut", "cut", "-d,", "-f2", NULL);
        perror("Error in execlp()");
        return -1;
    }
    else if (pidCut == -1) {
        perror("Error in fork()- pidCut");
        return -1;
    }

    //third child process -sed:
    if ((pidSed = fork()) == 0) {
        dup2(pipes[0], STDIN_FILENO);
        close(pipes[0]);
        close(pipes[1]);
        execlp("sed", "sed", "s/ //g", NULL);
        perror("Error in execlp()");
        return -1;
    }
    else if (pidSed == -1)
    {
        perror("Error in fork()- pidSed");
        return -1;
    }
    
    //parent process:
    //close both ends of the pipe in the parent process
    close(pipes[0]);
    close(pipes[1]);

    //waits for each child process to finish.
    waitpid(pidGrep, NULL, 0);
    waitpid(pidCut, NULL, 0);
    waitpid(pidSed, NULL, 0);

    return 0;
}

int main(int argc, char *argv[]) 
{
     if (argc < 2)
    {
        printf("Error! You need to input arg\n");
        return -1;
    }


    if (argc != 2)
    {
        printf("Error! input only one arg\n");
        return -1;
    }
    return findPhone(argv);
}
