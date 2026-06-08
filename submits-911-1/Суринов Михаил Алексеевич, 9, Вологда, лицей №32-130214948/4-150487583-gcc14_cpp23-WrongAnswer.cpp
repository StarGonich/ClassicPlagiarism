#include <bits/stdc++.h>

using namespace std;

long long gcm(int a, int b){
    while (b > 0){
        a %= b;
        swap (a, b);
    }
    long long y = a;
}


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
    long long lcm = 100000;
    long long x = 0;
    for (long long p = n + 1; p <= n + k; p++){
         if (((n * p) / gcm (n, p)) < lcm){
            lcm = ((n * p) / gcm (n, p));
            x = p;
         }
    }
    cout << x;
    return 0;
}
