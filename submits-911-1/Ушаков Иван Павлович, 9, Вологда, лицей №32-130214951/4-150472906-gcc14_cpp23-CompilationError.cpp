#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

int gcd (long long a, long long b){
    while(a>0){
        b = b%a;
        int d = b;
        b = a;
        a = d;
    }
    return b;
}


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long ans = 0;

    if(k>=n){
        cout << n*2;
        return 0;
    }

    long long p=0;
    long long minnok=1

    for(long long i=n+1; i<=n+k; ++i){
        long long nok = gcd(n,i);
        if(nok>minnok){
            minnok = nok;
            ans = i;
        }
    }

    cout << ans;
    
