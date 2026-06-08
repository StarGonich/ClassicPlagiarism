#include <iostream>
#include <cmath>

using namespace std;



int main()
{
    long long n,k,n1,p11,p1,p2,minimum,minimump,nok;
    int p;
    minimum=9999999;
    cin>>n;
    cin>>k;
    p1=n+1;
    p2=n+k;
    for (p=p1;p<=p2+1/2;p++){
        n1=n;
        p11=p;
        while (n1!=p11){
        if (n1>p11){
            n1=n1-p11;
        }
        else p11=p11-n1;
    }
        nok=n*p/p11;
        if (nok<minimum){
            minimum=nok;
            minimump=p;
        }
    }

cout<<minimump;

    return 0;
}


