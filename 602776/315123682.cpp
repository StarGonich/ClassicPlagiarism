#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff(int n = 0) {
    int i, j, g, k;

    if (n == 0)
        cin >> n;

    vi d(n), d2(n);
    d[0] = 0;
    d[1] = 1;
    d2[0] = 0;
    d2[1] = 1;

    for(i = 2; i < n; i++) {
        d2[i] = (d2[i - 1] + d2[i - 2]) % MOD;
        d[i] = (d[i - 1] + d[i - 2] + d2[i]) % MOD;
    }

    cout << d[n - 1] << endl;
}

signed main() {
    int t = 1;

/*
    for(int n = 1; n < 10; n++) {
        cout << n << " ";
        do_stuff(n);
    }
*/
    //cin >> t;
    while(t--) {
        do_stuff();
    }
}