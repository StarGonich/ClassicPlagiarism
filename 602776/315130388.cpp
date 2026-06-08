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

    vector<int> to(1000);
    vector<int> re(1024);
    for (int i = 0, j = 0; i < 1000; i++, j++) {
        while (__builtin_popcount(j) < 2) j++;
        to[i] = j;
        re[j] = i;
    }

    int t; cin >> t;
    if (t == 1) {
        string s;
        cin >> s;
        int n = sz(s);
        for (int b = 1; b < 1024; b <<= 1) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (to[i] & b) {
                    sum += s[i] - 'A';
                }
            }
            s.push_back(sum % 26 + 'A');
        }
        cout << s;
        return;
    }

    string s;
    cin >> s;
    int n = sz(s) - 10;
    vector<int> a;
    for (int i = 0; i < 10; i++) {
        a.push_back(s.back() - 'A');
        s.pop_back();
    }

    vector<int> was(1024, 1);
    int ad = 0;
    for (int b = 1; b < 1024; b <<= 1) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (to[i] & b) {
                sum += s[i] - 'A';
            }
        }

        sum %= 26;
        if (sum == a.back()) {
            for (int i = 0; i < 1024; i++) {
                if (i & b) was[i] = 0;
            }
            a.pop_back();
            continue;
        }

        ad = (a.back() - sum + 26) % 26;

        a.pop_back();
        for (int i = 0; i < 1024; i++) {
            if (!(i & b)) was[i] = 0;
        }
    }

    int i = max_element(all(was)) - was.begin();
    if (__builtin_popcount(i) < 2) {
        cout << s;
        return;
    }
    i = re[i];

    s[i] = (s[i] - 'A' + ad) % 26 + 'A';
    cout << s;

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
