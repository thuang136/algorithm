
#include<pthread.h>
#include<cstdio>
#include<malloc.h>
#include<cstring>
#include<unistd.h>

typedef struct alarm_tag {
    int seconds;
    char message[64];
} alarm_t;


void* alarm_thread (void* arg)
{
    alarm_t * alarm = (alarm_t*)arg;

    int status;

    status = pthread_detach(pthread_self());

    if(status != 0)
    {
        printf("Detach thread\n");
    }

    sleep(alarm->seconds);

    printf(" (%d) %s\n", alarm->seconds,alarm->message);

    free(alarm);

    return NULL;

}


int main(int argc, char* argv[])
{
    int status;

    char line[128];

    alarm_t *alarm;
    pthread_t thread[3];

    const char* INPUTFILE("../res/test-case/sample_input_alarm.txt");
    freopen(INPUTFILE,"r",stdin);

    int i = 0;

    while(true)
    {
         if(fgets(line,sizeof(line),stdin) == NULL )
         {
              break;
         }
         if(strlen(line) <= 1) continue;
         alarm = (alarm_t*)malloc(sizeof(alarm_t));
         if(alarm == NULL)
         {
             printf("allocate alarm fail\n");
         }
         if(sscanf(line,"%d %64[^\n]", &alarm->seconds,alarm->message) < 2)
         {
             printf("bad command\n");
             free(alarm);
         }
         else
         {
             status = pthread_create(&thread[i++],NULL,alarm_thread,alarm);
             if(status != 0)
             {
                 printf("create alarm thread\n");
             }
         }
    }

    for( i = 0; i < 3 ; i++)
    {
        pthread_join(thread[i],NULL);
    }

    return 0;
}







































