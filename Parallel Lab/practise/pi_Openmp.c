#include<stdio.h>
#include<omp.h>

int main()
{
    int thread_count=4;
    double factor=1.0;
    double sum=0.0;
    int n=50,k;

    #pragma omp parallel for num_threads(thread_count)\
    reduction(+:sum) private(factor)
    for(k=0;k<n;k++)
    {
        if(k%2==0)
        {
            factor=1.0;
        }
        else{
            factor=-1.0;
        }

        sum+=factor/((2*k)+1);


        printf("%d sum= %f  factor=%f\n ",k,sum,factor);
    }
    double pi=sum*4.0;
    printf("pi= %f",pi);

    return 0;
}

