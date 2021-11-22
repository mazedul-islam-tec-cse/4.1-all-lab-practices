#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include<pthread.h>
int th_c=5;
void* hello(void* rank);
int main()
{
    long th;
    pthread_t* th_h;
    th_h=malloc(th_c*sizeof(pthread_t));
    for(th=0;th<th_c;th++)
        pthread_create(&th_h[th],NULL,hello,(void*) th);

printf("Hello thread from main\n");

    for(th=0;th<th_c;th++)
        pthread_join(th_h[th],NULL);

    free(th_h);


    return 0;
}
void* hello(void* rank)
{
    int mr=(long) rank;
    //int tc=omp_get_num_threads();
     printf("Hello thread from %d of %d\n",mr,th_c);




}
