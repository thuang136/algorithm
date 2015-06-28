#include<pthread.h>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int seconds;

    char line[128];

    char message[64];

    const char* INPUTFILE("../res/test-case/sample_input_alarm.txt");
    freopen(INPUTFILE,"r",stdin);

    while( true)
    {
        cout << "alarm> ";

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
            //sleep(seconds);
            printf(" (%d) %s \n", seconds,message);
        }

    }

}

