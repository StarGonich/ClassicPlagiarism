#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff() {
    int n, p, i, j, ans , r, g, b;

    cin >> n;
    ans = (n / 60) * 20;
    n %= 60;
    for(i = 1; i <= n; i++) {
        int c = 0;
        for(j = 4; j <= 6; j++) {
            if(i % j == 0) {
                c++;
            }
        }
        if(c == 1) {
            ans++;
        }
    }

    cout << ans << endl;
}

signed main() {
    int t = 1;

    //cin >> t;
    while(t--) {
        do_stuff();
    }
}