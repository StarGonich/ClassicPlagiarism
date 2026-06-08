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
const int INF = 1e18;
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

    const int SZ = 3e5;
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    cin >> c;
    c.insert(c.begin(), 0);
    vector<vector<pair<int, int>>> g(SZ);
    for (int i = 0; i < m; i++) {
        int u, v, f;
        cin >> u >> v >> f;
        g[u].push_back({v, f});
        g[v].push_back({u, f});
    }

    vector<int> d(SZ, INF);
    vector<int> p(SZ, -1);
    set<pair<int, int>> s;
    d[c[1] * (n + 1) + 1] = 0;
    s.insert({0, c[1] * (n + 1) + 1});
    
    while (s.size()) {
        int z = s.begin()->second;
        s.erase(s.begin());
        int cost = z / (n + 1);
        int cur = z % (n + 1);
        for (auto [next, w] : g[cur]) {
            int nd = d[z] + w * cost;
            int y = min(c[next], cost) * (n + 1) + next;
            if (d[y] <= nd) continue;
            s.erase({d[y], y});
            d[y] = nd;
            p[y] = z;
            s.insert({d[y], y});
        }
    }

    int cur = 1 * (n + 1) + n;
    for (int i = 1; i <= 100; i++) {
        if (d[i * (n + 1) + n] < d[cur]) {
            cur = i * (n + 1) + n;
        }
    }

    if (d[cur] == INF) {
        cout << -1;
        return;
    }
    cout << d[cur] << '\n';

    vector<pair<int, int>> ans;
    int ac = 0;
    while (d[cur]) {
        int val = 0;
        if (c[cur % (n + 1)] == cur / (n + 1)) {
            val = ac / (cur / (n + 1));
            ac = 0;
        }
        ac += d[cur] - d[p[cur]];
        ans.push_back({cur % (n + 1), val});
        cur = p[cur];
    }
    ans.push_back({1, ac / c[1]});

    reverse(all(ans));
    cout << sz(ans) << '\n';
    for (auto [u, v] : ans) {
        cout << u << ' ' << v << '\n';
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
