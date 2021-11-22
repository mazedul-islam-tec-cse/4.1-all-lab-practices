#include<stdio.h>
#include<time.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{

    int i,n;
    printf("Enter Number of test cases:");
    scanf("%d",&n);
    float R[100], DPlus, DMinus, temp1[n], temp2[n], Dmax, Cvalue;
    bool flag1 = true, flag2 = true;


    srand(time(NULL));
    for(i= 0; i<n; i++)
    {
        R[i] = (float)(rand()%100)/100;
    }
    for(i= 0; i<n; i++)
    {
        printf("%.2f ", R[i]);
    }
    printf("\n\n");
    std::sort(R,R+n);
    for(i=0; i<n; i++)
    {
        printf("%.2f ",R[i]);
    }
    for(i=0; i<n; i++)
    {
        temp1[i]=(float)(i+1)/(float)n-R[i];
        temp2[i]=R[i]-(float)i/(float)n;
        if(flag1)
        {
            DPlus=temp1[i];
            flag1=false;
        }
        else if(DPlus<temp1[i])
        {
            DPlus=temp1[i];
        }
        if(flag2)
        {
            DMinus=temp2[i];
            flag2=false;
        }
        else if(DMinus<temp2[i])
        {
            DMinus=temp2[i];
        }

    }
    cout<<"\n(i/n)-R[i]"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<temp1[i]<<" ";
    }
    cout<<"\nR[i]-(i-1)/n "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<temp2[i]<<" ";
    }


    printf("\n\nD+ = %.2f \nD- = %.2f",DPlus,DMinus);
    if(DPlus>DMinus)
    {
        Dmax=DPlus;
        printf("\nDmax is:.%.2f", Dmax);
    }
    else
    {
        Dmax=DMinus;
        printf("\n\nDmax is:%.2f", Dmax);
    }
    printf("\n\nEnter Your Cvalue:");
    scanf("%f",&Cvalue);
    if(Dmax<=Cvalue)
    {
        printf("Uniform distribution:");
    }
    else
    {
        printf("not uniform distribution");
    }

    return 0;
}
