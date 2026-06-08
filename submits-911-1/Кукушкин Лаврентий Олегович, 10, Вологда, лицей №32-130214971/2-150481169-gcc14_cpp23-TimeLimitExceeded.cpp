#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n,k=0,s=0;
    vector<int> v;
    cin>>n;
    for (int m=1; m<=1000000000; m++)
    {
        for (int r=1; r<=m/2; r++)
        {
            if(m%r==0)
            {
                v.push_back(r);
                s+=r;
                k++;
            }
        }
        if((s==m)&&(n==k))
        {
            cout<<m<<endl;
            for (int n : v)
                std::cout << n << ' ';
            std::cout << '\n';
        }
    }
    return 0;
}
