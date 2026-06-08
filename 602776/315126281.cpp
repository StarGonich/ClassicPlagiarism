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
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int cur = 1;
    int l = -1, r = -1;
    int l1 = -1, r1 = -1;
    for(int i = 0; i < n; i++) {
        if(cur == p[i]) {
            cur++;
        }
        else if(l1 != -1) {
            cout << "-1\n";
            return;
        }
        else if(l != -1) {
            if(p[l] != cur) {
                cout << "-1\n";
                return;
            }
            r1 = i - 1;
            l1 = r + 1;
            cur = p[r] + 1;
            i--;
        }
        else {
            l = i;
            for(int j = i; j < n; j++) {
                if(p[j] == cur) {
                    r = j - 1;
                    break;
                }
            }
            i = r;
        }
    }
    if(l == -1 || cur != n + 1) {
        cout << "-1\n";
        return;
    }
    if(l1 == -1) {
        if(p[l] != cur) {
            cout << "-1\n";
            return;
        }
        r1 = n - 1;
        l1 = r + 1;
    }
    for(int i = l + 1; i < r + 1; i++) {
        if(p[i] != p[i - 1] + 1) {
            cout << "-1\n";
            return;
        }
    }
    for(int i = l1 + 1; i < r1 + 1; i++) {
        if(p[i] != p[i - 1] + 1) {
            cout << "-1\n";
            return;
        }
    }
    cout << l + 1 << " " << r - l + 1 << "\n";
    cout << l1 + 1 << " " << r1 - l1 + 1<< "\n";
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
