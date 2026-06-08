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
const int INF = 1e5;
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

    string s;
    cin >> s;
    vector mn(sz(s) + 1, vector<int> (sz(s) + 1));
    vector mx(sz(s) + 1, vector<int> (sz(s) + 1));
    vector mnM(sz(s) + 1, vector<int> (sz(s) + 1, INF));
    vector mxM(sz(s) + 1, vector<int> (sz(s) + 1, INF));
    for (int i = 0; i < sz(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            mn[i][i] = mx[i][i] = s[i] - '0';
        } else {
            mn[i][i] = INF;
            mx[i][i] = -INF;
        }
    }

    for (int len = 2; len <= sz(s); len++) {
        for (int l = 0; l < sz(s) - len + 1; l++) {
            int r = l + len - 1;
            mn[l][r] = INF;
            mx[l][r] = -INF;

            auto relax_mn = [&](int nz, int lab) {
                if (mn[l][r] <= nz) return;
                mn[l][r] = nz;
                mnM[l][r] = lab;
            };            
            auto relax_mx = [&](int nz, int lab) {
                if (mx[l][r] >= nz) return;
                mx[l][r] = nz;
                mxM[l][r] = lab;
            };

            for (int m = l + 1; m < r; m++) {
                if (s[m] != '+' && s[m] != '-') continue;

                if (s[m] == '+') {
                    relax_mn(mn[l][m - 1] + mn[m + 1][r], m);
                    relax_mx(mx[l][m - 1] + mx[m + 1][r], m);
                    continue;
                }
                
                if (s[m + 1] == '(' && s[r] == ')'){
                    relax_mn(mn[l][m - 1] - mx[m + 2][r - 1], m);
                    relax_mx(mx[l][m - 1] - mn[m + 2][r - 1], m);
                }

                int fc = m;
                while (fc <= r && (s[fc] < '0' || s[fc] > '9')) fc++;
                if (fc <= r) {
                    relax_mn(mn[l][m - 1] + mn[fc][r] - 2*(s[fc] - '0'), -m);
                    relax_mx(mx[l][m - 1] + mx[fc][r] - 2*(s[fc] - '0'), -m);
                }
            }
            if (s[l] == '(') {
                relax_mn(mn[l + 1][r], -INF);
                relax_mx(mx[l + 1][r], -INF);
            }
            if (s[r] == ')') {
                relax_mn(mn[l][r - 1], -2*INF);
                relax_mx(mx[l][r - 1], -2*INF);
            }
        }
    }

    cout << mx[0][sz(s) - 1] << '\n';
    vector<int> tk(sz(s));
    function<void(int, int, bool)> f = [&](int l, int r, int ismn) {
        if (l == r) return;
        int lab = ismn ? mnM[l][r] : mxM[l][r];

        if (lab == -INF) {
            f(l + 1, r, ismn);
            return;
        }

        if (lab == -2*INF) {
            f(l, r - 1, ismn);
            return;
        }

        if (lab > 0) {
            f(l, lab - 1, ismn);
            if (s[lab] == '+') {
                f(lab + 1, r, ismn);
            } else {
                tk[lab + 1] = 1;
                tk[r] = 1;
                f(lab + 2, r - 1, !ismn);
            }
            return;
        }

        lab *= -1;
        int fc = lab;
        while (fc <= r && (s[fc] < '0' || s[fc] > '9')) fc++;
        f(l, lab - 1, ismn);
        f(fc, r, !ismn);
    };

    f(0, sz(s) - 1, false);

    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '(' || s[i] == ')') {
            if (tk[i]) cout << s[i];
            continue;
        }
        cout << s[i];
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
