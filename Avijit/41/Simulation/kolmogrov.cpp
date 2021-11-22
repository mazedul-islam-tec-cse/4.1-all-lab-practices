#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of the random : ";cin>>n;
    float r[n+1],dplus[n+1],dminus[n+1],dmax,dmin;

    int i,j;
    for(i=1;i<=n;i++)
    {
        r[i]=(float)(rand()%100)/100;
    }
    for(i=1;i<=n;i++)
    {
        cout<<r[i]<<"  ";
    }float temp;
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=n-i-1;j++)
        {
            if(r[j]>r[j+1])
            {

                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;

            }
        }
    }
    cout<<"\n\nSorted Listed : "<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<r[i]<<"  ";
    }
    for(i=1;i<=n;i++)
    {
        dplus[i]=(float)i/n-r[i];
        dminus[i]=float(r[i]-(float)(i-1)/n);
    }
    cout<<"\nDplus array : ";
    for(i=1;i<=n;i++)
    {
        cout<<dplus[i]<<"  ";
    }
    cout<<"\nDminus array : ";
    for(i=1;i<=n;i++)
    {
        cout<<dminus[i]<<"  ";
    }
    dmax=dplus[1];
    dmin=dminus[1];
    for(i=2;i<=n;i++)
    {
        if(dmax<dplus[i])
        {
           dmax=dplus[i];
        }
        if(dmin<dminus[i])
        {
            dmin=dminus[i];
        }


    }
    cout<<"\n dmax= "<<dmax<<"  dmin= "<<dmin;
    float D;
    if(dmax>dmin)
    {
        D=dmax;

    }
    else
    {
        D=dmin;
    }
    float critical_value=1.96;
    if(D>critical_value)
    {
        cout<<"\n null hypothesis rejected";
    }
    else
    {
        cout<<"\n null hypothesis Accepted";

    }
}
