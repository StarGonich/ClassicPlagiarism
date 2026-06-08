#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff(int n = 0) {
    int i, j, g, k;

    cin >> n;
    vi d(n);
    d[0] = 0;
    d[1] = 1;
    for(i = 2; i < n; i++) {
        d[i] = d[i - 1] + (i - 1) + d[i - 2];
    }

    cout << d[n - 1] << endl;
}

signed main() {
    int t = 1;

    //cin >> t;
    while(t--) {
        do_stuff();
    }
}