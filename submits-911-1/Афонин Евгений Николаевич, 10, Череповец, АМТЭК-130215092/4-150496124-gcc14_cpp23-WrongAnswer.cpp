#include <iostream>

using namespace std;


int main()
{
    long long a,b,k,t,i,n,m,c;
    m=1000000000000000000;
    cin >> n >> k;
    for (i=n+1;i<=n+k;i++){
        a=n;
        b=i;
        while (a%b!=0){
            c=a;
            a=b;
            b=c%b;
        }
        t=n*i/b;
        if (t<m){
            m=t;
            k=i;
        }
    }
    cout << k;

}
