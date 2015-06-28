#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <string.h>



using namespace std;

int main(int argc, char** argv)
{

    int status;

    pid_t pid;

    int seconds;

    char line[128];

    char message[64];

    const char* INPUTFILE("../res/test-case/sample_input_alarm.txt");
    freopen(INPUTFILE,"r",stdin);

    while( true)
    {

        if( fgets(line, sizeof(line),stdin) == NULL)
        {
            return 0;
        }

        if(strlen(line) <= 1) continue;

        if(sscanf(line, "%d %64[^\n]",&seconds,message) < 2)
        {
            fprintf(stderr,"bad command\n");
        }
        else
        {
            pid = fork();
            if(pid == (pid_t)-1)
            {
                printf("Fork\n");
            }

            if(pid == (pid_t)0)
            {
                sleep(seconds);
                printf(" (%d) %s \n", seconds,message);
                return 0;
            }
            else
            {
                do
                {
                    pid = waitpid((pid_t)-1, NULL,WNOHANG);
                    //WNOHANG 若pid指定的子进程没有结束，则waitpid()函数返回0，不予以等待。若结束，则返回该子进程的ID
                    if(pid == (pid_t)-1)
                    {
                        printf("wait for child\n");
                    }
                }
                while(pid == (pid_t)0);

                cout << "pid is " << pid << endl;
            }
        }

    }

}

