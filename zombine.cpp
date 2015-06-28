#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <string.h>

using namespace std;


void clean_up_child_process(int signal_num)
{

    int status;

    wait(&status);

    cout << "the status is " << status << endl;

}






int main(int argc, char** argv)
{
    struct sigaction sigchild_action;
    memset(&sigchild_action,0,sizeof(sigchild_action));
    sigchild_action.sa_handler = &clean_up_child_process;
    sigaction(SIGCHLD,&sigchild_action,NULL);


    pid_t pid;

    pid = fork();

    if(pid > 0)
    {
        cout << ("in parent process,sleep for one miniute..zZ..\n") << endl;
        sleep(60);
        cout << ("after sleeping, and exit!\n") << endl;
    }
    else
    {
        cout << ("in child process,and exit!\n") << endl;
        exit(0);
    }

    return 0;
}



