#include<iostream>
#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include<math.h>
using namespace std;
int main(){
    int N;
    cout<<"Enter the total number of observations N"<<endl;
    cin>>N;
    float random[N];
    srand (time(NULL));
    int i,j;
    for(i=0;i<N;i++){
        random[i]=rand() % 100 + 1;

  }
  cout<<" Random Number "<<endl;
  for(j=0;j<N;j++){
        random[j]=(float)random[j]/100;
   cout<<random[j]<<" ";
  }
  char sign[N];
  j=0;
  for(i=1;i<N;i++){

    if(random[i]>=random[i-1]){

            sign[j] = '+';
            j=j+1;

    }
    else
    {
         sign[j] = '-';
            j=j+1;
    }
  }
  cout<<endl;
  int k;
  for(k=0;k<j;k++){

   cout<<sign[k]<<" ";
  }
  int a=1,l;
  char first=sign[0],second;
  for(l=1;l<N-1;l++){
        second=sign[l];
    if(first==second){

    }
    else
    {
    first=second;
       a=a+1;
    }
  }
   cout<<" \n a =  "<<a;
   float Ua,Oa,Zo;
   Ua=(float)(2*N-1)/3;
   cout<<"\n Ua = "<<Ua;
   Oa=(float)(16*N-29)/90;
    cout<<" \n Oa = "<<Oa;
     Zo=(float)(a-Ua)/sqrt(Oa);
    cout<<" \nZo = "<<Zo;

    float criticalValue;
    cout<<"Enter the Critical Value"<<endl;
    cin>>criticalValue;
    if(criticalValue<Zo ){
        cout<<"null hypothesis rejected"<<endl;

    }
    else
        {
          cout<<"null hypothesis accepted"<<endl;
        }
  }


