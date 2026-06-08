#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x.size())) 

#define dout cerr
#ifdef LOCAL
    int SEED = 42;  
    #define dbg(x) dout << #x << ' ' << x << endl;
    #define ddbg(x, y) dout << #x << ' ' << x << "   " << #y <<' ' << y << endl;
    #define d3bg(x, y, z) dout << x << ' ' << y << ' ' << z << endl;
    #define d4bg(x, y, z, w) dout << x << ' ' << y << ' ' << z << ' ' << w << endl;
#else
    int SEED = random_device{}();
    #define dbg(x) 42;
    #define ddbg(x, y) 42;
    #define d3bg(x, y, z) 42;
    #define d4bg(x, y, z, w) 42;
#endif

mt19937_64 rnd(SEED);

template<typename T1, typename T2>
istream& operator >> (istream& in, pair<T1, T2>& a){
    return in >> a.first >> a.second;
}

template<typename T>
istream& operator >> (istream& in, vector<T>& a){
    for (auto& e : a){
        in >> e;
    }
    return in;
}

template<typename T1, typename T2>
ostream& operator << (ostream& out, const pair<T1, T2>& a){
    return out << a.first << ',' << a.second;
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& a){
    for (const auto& e : a){
        out << e << ' ';
    }
    return out;
}

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

const int mod = 1e9 + 7;
const int INF = 1e9;
const double eps = 1e-8;

int fpow(int a, int p) {
    int ans = 1;
    while (p) {
        if (p & 1) ans = ans * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return ans;
}

void solve() {  

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == 'w') {
                a[i] |= (1 << j);
            }
        }
    }

    int sz = 1 << n;
    auto xrm = [&](int mask) {
        return mask ^ (mask >> 1) ^ (mask << 1) & (sz - 1);
    };

    int best = INF;
    int mb = -1;
    int kek = 0;
    for (int _ = 0; _ < 2; _++) {
        for (int mask = 0; mask < sz; mask++) {
            int up = a[0] ^ xrm(mask);
            int cur = __builtin_popcount(mask);
            int lms = mask;
            for (int i = 1; i < n; i++) {
                cur += __builtin_popcount(up);
                int nms = up;
                up = a[i] ^ lms ^ xrm(up);
                lms = nms;
            }
            if (up) continue;
            if (cur < best) {
                best = cur;
                mb = mask;
                kek = _;
            }
        }

        for (int i = 0; i < n; i++) {
            a[i] ^= (sz - 1);
        }
    }

    if (best == INF) {
        cout << -1;
        return;
    }
    if (kek) {        
        for (int i = 0; i < n; i++) {
            a[i] ^= (sz - 1);
        }
    }

    vector<int> ans(n);
    ans[0] = mb;            
    int up = a[0] ^ xrm(mb);
    int lms = mb;
    for (int i = 1; i < n; i++) {
        int nms = up;
        up = a[i] ^ lms ^ xrm(up);
        lms = nms;
        ans[i] = nms;
    }

    cout << best << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i] & (1 << j)) {
                cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    }
}

signed main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int T = clock();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

    dbg(clock() - T)
}
