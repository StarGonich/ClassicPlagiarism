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
const int INF = 2e18;
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
    vector<int> p(n);
    cin >> p;
    p.push_back(n + 1);
    p.insert(p.begin(), 0);

    vector<pair<int, int>> o;
    int last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (p[i] - 1 == p[i - 1]) continue;
        o.push_back({last, i - 1});
        last = i;
    }
    o.push_back({last, n + 1});

    if (sz(o) == 1 || sz(o) > 5) {
        cout << -1;
        return;
    }

    for (int i = 0; i < sz(o); i++) {
        for (int j = i + 1; j < sz(o); j++) {
            swap(o[i], o[j]);
            bool fl = true;
            for (int k = 1; k < sz(o); k++) {
                if (p[o[k].first] <= p[o[k - 1].second]) {
                    fl = false;
                    break;
                }
            }
            swap(o[i], o[j]);
            if (!fl) {
                continue;
            }
            cout << o[i].first << ' ' << o[i].second - o[i].first + 1 << '\n';
            cout << o[j].first << ' ' << o[j].second - o[j].first + 1 << '\n';
            exit(0);
        }
    }

    cout << -1;

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
