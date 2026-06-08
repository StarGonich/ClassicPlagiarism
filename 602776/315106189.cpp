#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>

#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii>

#define all(s) s.begin(), s.end()

const int maxN = 2e5 + 5;
const ld eps = 1e-10;
const ld pi = (ld)3.141592653589793238462643383279;
vi a;
bool check(vector<pii>& seg) {
    // cout << "in check " << endl;
    // for (auto [l, r] : seg) cout << "[" << l << ", " << r <<"], ";
    // cout << endl;
    // cout << a[seg[0].first] << endl;
    if (a[seg[0].first] != 1) return false;
    // cout << a[seg[seg.size() - 1].second] << endl;
    if (a[seg[seg.size() - 1].second] != a.size()) return false;
    for (int i = 1; i < seg.size(); i++) {
        if (a[seg[i - 1].second] + 1 != a[seg[i].first]) return false;
    }
    // cout << "return true " << endl;
    return true;
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (auto& x : a) cin >> x;
    vector<pii> seg;
    seg.push_back({0, 0});
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) {
            seg[seg.size() - 1].second = i;
        } else {
            seg.push_back({i, i});
        }
    }
    // for (auto [l, r] : seg) cout << l << " " << r << endl;

    if (seg.size() == 1 || seg.size() >= 10) {
        cout << -1; return;
    }
    for (int i = 0; i < seg.size(); i++) {
        for (int j = i + 1; j < seg.size(); j++) {
            swap(seg[i], seg[j]);
            if (check(seg)) {
                cout << seg[i].first + 1 << " " << seg[i].second - seg[i].first + 1 << endl;
                cout << seg[j].first + 1 << " " << seg[j].second - seg[j].first + 1 << endl;
                return;
            }
            swap(seg[i], seg[j]);
        }
    }
    cout << -1;
}

signed main() {
    ios_base::sync_with_stdio(false);
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