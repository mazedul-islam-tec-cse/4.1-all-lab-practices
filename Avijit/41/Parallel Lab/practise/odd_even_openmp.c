#include<stdio.h>
#include<omp.h>

int main()
{
    int thread_count=4;
    int a[]={23,1,4,33,5,6,3,9,1,111};
    int n=10;
    int phase, temp,i;
    for(phase=0;phase<n;phase++){
        if(phase%2==0)
        {
            #pragma omp parallel for num_threads(thread_count)\
            default(none) shared(a,n) private(i, temp)
            for(i=1;i<n;i+=2)
            {
                if(a[i-1]>a[i])
                {
                    temp=a[i-1];
                    a[i-1]=a[i];
                    a[i]=temp;

                }

            }

        }
        else
        {

            #pragma omp parallel for num_threads(thread_count)\
            default(none) shared(a,n) private(i, temp)
            for(i=1;i<n-1;i+=2)
            {
                if(a[i]>a[i+1])
                {
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;

                }

            }
        }
    }
    printf("sorted list : ");
 for(i=0;i<n;i++){
    printf("%d ",a[i]);
 }
    return 0;
}


