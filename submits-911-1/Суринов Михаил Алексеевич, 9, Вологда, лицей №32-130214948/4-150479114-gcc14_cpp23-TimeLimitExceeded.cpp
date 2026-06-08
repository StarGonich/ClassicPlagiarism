#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    long long k;
    cin >> n;
    cin >> k;
    if (k == 1){
        cout << n + 1;
        return 0;
    }
    long long lcm = 1000000000000;
    long long x = 0;
    for (long long p = n + 1; p <= n + k; p++){
        while (p > 0){
            n %= p;
            swap (n, p);
        }
        long long y = n;
        if (((n * p) / y) < lcm){
            lcm = ((n * p) / y);
            x = p;
        }
    }
    cout << x;
    return 0;
}
