#include <bits/stdc++.h>

using namespace std;

long long gcm(long long a, long long b){
    while (b > 0){
        a %= b;
        swap (a, b);
    }
    long long y = a;
}


int main()
{
    long long n, k;
    cin >> n >> k;
    long long lcm = 100000;
    long long x = 0;
    for (long long p = n + 1; p <= n + k; p++){
         if (n * p / gcm (n, p) < lcm){
            lcm = n * p / gcm (n, p);
            x = p;
         }
    }
    cout << x;
    return 0;
}
