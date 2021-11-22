#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int thread_count;
double sum=0.0;
long int n;
void* find_pi(void* rank);
int main()
{
    thread_count=10;
    n=100000;
    long thread;
    pthread_t* thread_control;
    thread_control=malloc(thread_count*sizeof(pthread_t));
    for(thread =0;thread<thread_count;thread++)
    {
        pthread_create(&thread_control[thread],NULL,find_pi,(void*) thread);
    }
    printf("Hello world from main\n ");
    for(thread=0;thread<thread_count;thread++)
    {

        pthread_join(thread_control[thread],NULL);
    }
    double pi=4*sum;
    printf("%.82f",pi);
    free(thread_control);
    return 0;
}
void* find_pi(void* rank)
{

    long my_rank=(long) rank;
    double factor;
    double local_n=n/thread_count;
    long long my_first_i=my_rank*local_n;
    long long my_last_i=my_first_i+local_n;
    if(my_first_i%2==0)
    {
        factor=1.0;

    }
    else{
        factor=-1;
    }
    for(int i=my_first_i;i<my_last_i;i++)
    {

        sum+=factor/(2*i+1);
        factor=-factor;
    }

    return NULL;
}
