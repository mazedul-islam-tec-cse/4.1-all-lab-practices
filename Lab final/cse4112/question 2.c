#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
double pi=0.0;
 int thread_count;
 int n=100000000;
void* find(void *rank)
{
int my_rank=(int) rank;
int local_n=n/thread_count;
int local_i=local_n*my_rank;
int local_end=local_i+local_n;
int factor;
double sum=0.0;


if(local_i%2==0)
{
    factor=1;

}
else
{
    factor=-1;
}

for(int i=local_i;i<local_end;i++)
{

    sum+=(float)(factor/((i*2.0)+1));

    factor=-factor;
}
pi+=sum;
printf("From rank  %d pi= %.10f\n",my_rank,4.0*sum);

}
int main()
{
    thread_count=10;

    int thread;
    pthread_t* thread_control;
    thread_control= malloc(thread_count*sizeof(pthread_t));
    for(thread=0;thread<thread_count;thread++)
    {
        pthread_create(&thread_control[thread],NULL,find,( void *)thread);

    }

    for(thread=0;thread<thread_count;thread++)
    {
        pthread_join(thread_control[thread],NULL);

    }
    printf("Final value of Pi %.8f",pi*4);
    return 0;
}

