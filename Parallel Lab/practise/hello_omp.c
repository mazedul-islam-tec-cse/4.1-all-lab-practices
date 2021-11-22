#include<stdio.h>
#include<omp.h>
void hello(void);
int main()
{
    int thread_count;
    printf("Enter the number of thread : ");
    scanf("%d",&thread_count);
    #pragma omp parallel num_threads(thread_count)
    hello();

    return 0;
}
void hello(void )
{
    int current_thread=omp_get_thread_num();
    int total_thread=omp_get_num_threads();
    printf("Hello world from %d of %d\n",current_thread,total_thread);

}
