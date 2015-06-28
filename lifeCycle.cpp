#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<errno.h>

using namespace std;


#define err_abort(code,text) do {\
    fprintf(stderr,"%s at \"%s\" : %d: %s\n",\
    text,__FILE__,__LINE__,strerror(code));\
    abort(); \
} while(0)


void* thread_routine(void* arg)
{
    return arg;
}

int main(int argc, char* argv[])
{
    pthread_t thread_id;

    void* thread_result;

    int status;

    int parameter = 1;

    status = pthread_create(&thread_id,NULL,thread_routine,&parameter);

    if( status != 0)
    {
        err_abort(status,"create thread");
    }

    status = pthread_join(thread_id,&thread_result);

    if(status != 0)
    {
        err_abort(status,"join thread");
    }

    if(thread_result == NULL)
    {
       cout << "result is NULL" << endl;
       return 0;
    }
    else
    {
       int* result = (int*)thread_result;
       cout << "result is not null " << *result << endl;
       return 1;
    }

}

