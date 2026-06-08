#include<bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
#define ll long long
#define pii pair<int, int>
#define vii vector<pii>
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sza(x) (int)x.size()
const int N = 1e5+5;
const int inf = 1e9;
const int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<pii> v;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int lst = 0;
    for(int i = 1; i < n; i++) {
        if(p[i] - p[i - 1] != 1) {
            v.push_back({lst, i - 1});
            lst = i;
        }
    }
    v.push_back({lst, n - 1});
    // for(auto to: v) {
    //     cout << to.first << " " << to.second << endl;
    // }
    if(sza(v) > 6) {
        cout << "-1\n";
        return;
    }
    
    for(int i = 0; i < sza(v); i++) {
        for(int j = i + 1; j < sza(v); j++) {
            swap(v[i], v[j]);
            int ok = 0;
            int sum = 1;
            for(int k = 0; k < sza(v); k++) {
                if(p[v[k].first] != sum) {
                    ok = 1;
                }
                sum += v[k].second - v[k].first + 1;
            }
            swap(v[i], v[j]);
            if(!ok) {
                cout << v[i].first + 1 << " " <<  v[i].second - v[i].first + 1 << endl;
                cout << v[j].first + 1 << " " <<  v[j].second - v[j].first + 1 << endl;
                return;
            }
            
        }
    }
    cout << "-1\n";

}

signed main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) { 
        solve();
    }
} 
