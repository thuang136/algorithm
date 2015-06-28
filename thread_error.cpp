
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <signal.h>
#include <string.h>

#ifdef DEBUG
#define DPRINTF(arg) printf(arg)

#define err_abort(code,text) do {\
    fprintf(stderr,"%s at \"%s\" : %d: %s\n",\
    text,__FILE__,__LINE__,strerror(code));\
    abort(); \
} while(0)

#else
#define DPRINTF(arg)
#endif

int main(int argc, char* argv[])
{
    DPRINTF("prepar join thread!\n");

    /*
    pthread_t thread;

    int status;

    status = pthread_join(thread,NULL);

    if(status != 0)
    {
        fprintf(stderr,"error %d  \n",status);
    }

    return status;
    */

    FILE* fp;

    extern int errno;


    char* message;

    if( NULL == (fp = fopen("test.txt","rt")) )
    {
        message = strerror(errno);
        err_abort(errno,message);
    }



    return 0;
}













