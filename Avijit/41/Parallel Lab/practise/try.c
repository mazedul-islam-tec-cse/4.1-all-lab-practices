#include<stdio.h>
#include<omp.h>
void hello();
int main()
{
    int thread_count=5;
    #pragma omp parallel num_threads(thread_count)
    hello();
    return 0;
}
void hello()
{
    int my_rank=omp_get_thread_num();
    int threads=omp_get_num_threads();
    printf("hello world from %d of %d \n",my_rank,threads);

}
