#include<iostream>
using namespace std;
int main()
{
    int x0,a,c,m,i;
    float r;
    cout<<" Enter the value of x0"<<endl;
    cin>>x0;
    cout<<" Enter the value of a"<<endl;
    cin>>a;
    cout<<" Enter the value of c"<<endl;
    cin>>c;
    cout<<" Enter the value of m"<<endl;
    cin>>m;
    r=(float)x0/m;
    for(i=0; i<m; i++)
    {
    cout<<"  x"<<i<<"= "<<x0<<"          R" <<i<<" :"<<r<<endl;
        x0=(a*x0+c)%m;
        r=(float)x0/m;



    }


}
