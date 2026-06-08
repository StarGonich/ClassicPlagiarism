#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
//#pragma GCC target("avx2,fma")
//#define pb push_back
#define int long long

using namespace std;
signed lcm (int a, int b){
    for (int i = 1; i<a*b; ++i){
        if (i%a == 0 && i%b == 0){
            return i;
        }
    }
}

signed main() {
    int n,k;
    cin >> n >> k;
    int mn = 1e9;
    int p = 0;
    for (int i = n+1; i<=n+k; ++i){
        if (lcm(n,i)<mn){
            p = i;
            mn = lcm(n,i);
        }
    }
    cout << p;
    return 0;
}
