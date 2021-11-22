#include<stdio.h>
void main()
{
    double sum=0.0;
    int local_i=0,local_end=250,factor=1;
    for(int i=local_i;i<local_end;i++)
{

    sum+=(float)(factor/((i*2.0)+1));

    factor=-factor;
}
printf("%f",sum);

}

