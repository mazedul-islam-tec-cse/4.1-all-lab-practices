#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
int thread_count;
double sum=0.0;
long int n;
void* find_pi(void *rank);
int main()
{
    thread_count=2;
    n=1000000;
    long thread;
    pthread_t* thread_control;
    thread_control=malloc(thread_count*sizeof(pthread_t));
    for(thread=0;thread<thread_count;thread++)
    {
        pthread_create(&thread_control[thread],NULL,find_pi,(void*) thread);

    }
    printf("From main function");
    for(thread=0;thread<thread_count;thread++)
    {
        pthread_join(thread_control[thread],NULL);

    }
    double pi=4*sum;
    printf(" %.6f",pi);
    free(thread_control);
    return 0;


}
void* find_pi(void* rank)
{
    long int my_rank=(long) rank;

    double factor;
    long int flag;
    flag=(flag+1)%thread_count;
    double local_n=n/thread_count;
    long my_first_i=my_rank*local_n;
    long my_last_i=my_first_i+local_n;
    if(my_first_i%2==0)
        factor=1.0;
    else
        factor=-1.0;
    for(int i=my_first_i;i<my_last_i;i++, factor=-factor)
    {
        //while(flag!=my_rank);
        sum+=factor/(2*i+1);
        flag=(flag+1)%thread_count;



    }
    printf("from %ld  %.6f\n",my_rank,sum*4);
    return NULL;

}

