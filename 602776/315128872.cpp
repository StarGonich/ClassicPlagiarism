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
    vector<int> p(n), v;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    if(p[0] != 1) {
        v.push_back(0);
    }
    for(int i = 1; i < n; i++) {
        if(p[i] - p[i - 1] != 1) {
            v.push_back(i);
        }
    }
    if(p[n - 1] != n){
        v.push_back(n - 1);
    }
    for(auto to: v) {
        cout << to << endl;
    }
    if(v.size() != 3) {
        cout << "-1\n";
        return;
    }
    cout << v[0] + 1 << " " << v[1] - v[0] << endl;
    cout << v[1] + 1 << " " << v[2] - v[1] << endl;
    
    

}

signed main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
    // freopen("in", "r", stdin);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) { 
        solve();
    }
} 
