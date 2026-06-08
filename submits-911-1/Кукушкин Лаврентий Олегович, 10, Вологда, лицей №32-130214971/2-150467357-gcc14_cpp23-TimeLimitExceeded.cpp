#include <iostream>

using namespace std;

int main()
{
    long long n,k=0,s=0;
    cin>>n;
    for (int m=1; m<=1000000000; m++)
    {
        for (int r=1; r<=m/2; r++)
        {
            if(m%r==0)
            {
                s+=r;
                k++;
            }
        }
        if((s==m)&&(n==k))
        {
            cout<<m<<endl;
        }
    }
    return 0;
}
