#include <iostream>
#include <vector>

using namespace std;

long long nod(long long a, long long b){
    if(a<b){
        swap(a, b);
    }
    while(b>0){
        a%=b;
        if(a<b){
            swap(a, b);
        }
    }
    return a;
}

int main()
{
    long long n, k;
    cin >>n>>k;
    if(n*2<=n+k){
        cout <<n*2;
        return 0;
    }
    long long res=n+k;
    long long nok=1e18+1;
    for(int i=n+1; i<=n+k; i++){
        if(i*n/nod(i, n)<nok){
            nok=i*n/nod(i, n);
            res=i;
        }
    }
    cout <<res;
}
