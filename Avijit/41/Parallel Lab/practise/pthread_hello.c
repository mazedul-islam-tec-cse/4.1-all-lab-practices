#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int thread_count;
void* hello(void* rank);
int main()
{
    thread_count=5;
    long thread;
    pthread_t* thread_control;
    thread_control=malloc(thread_count*sizeof(pthread_t));
    for(thread =0;thread<thread_count;thread++)
    {
        pthread_create(&thread_control[thread],NULL,hello,(void*) thread);
    }
    printf("Hello world from main\n ");
    for(thread=0;thread<thread_count;thread++)
    {

        pthread_join(thread_control[thread],NULL);
    }
    free(thread_control);
    return 0;
}
void* hello(void* rank)
{

    long my_rank=(long) rank;
    printf("hello from %d of %d\n",my_rank,thread_count);
    return NULL;
}
