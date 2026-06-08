#include <iostream>
#include <vector>
using namespace std;
const long long inf = 100000000000000;
long long evk(long long a, long long b){
    if (a>b){
        if(a%b!=0)
            return evk(b, a%b);
        else
            return b;
    }
    else {
        if(b%a!=0){
            return evk(a, b%a);
        }
        else{
            return a;
        }
    }
}
int main()
{
    long long n=0, k=0;
    cin >> n;
    cin >> k;
    long long p = inf;
    long long p1 = 0;
    for (long long i=n+2; i<k+n; i++){
        long long hj = evk(n, i);
        if (n*i/hj<p){
            p1 = i;
            p = n*i/hj;
        }
    }
    cout << p1;
}