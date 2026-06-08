#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
//#pragma GCC target("avx2,fma")
#define pb push_back
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<int>> a;
    bool fl = 0;
    for (int j = 0; j<k; ++j){
        int cnt = 0;
        for (int x = 0; x<n; ++x){
            for (int y = 0; y<m; ++y){
                int q;
                cin >> q;
                //a.pb(q);
                cnt+=q;
            }
        }
        if (cnt != 0 && k==0)
            fl = false;
    }
    if (fl)
        cout << "1 2";
    else
        cout << "2 1";
    return 0;
}
