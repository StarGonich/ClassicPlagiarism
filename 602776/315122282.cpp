#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <bitset>
#include <iomanip>
#include <complex>
#include <random>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <set>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <functional>

#define all(x) x.begin(), x.end()
#define dall(x) x.rbegin(), x.rend()
#define forv(obj) for(auto& el: obj)
#define forn(i, idx, n) for(int i = idx; i <= n; ++i)
#define dforn(i, idx, n) for(int i = idx; i >= n; --i)
#define pli pair<ll, int>
#define pii pair<int, int>
#define fst first
#define sec second
#define pll pair<ll, ll>

using namespace std;
using ll = int64_t;


const double PI = 3.14159265;
const int iinf = 1e9;
const ll inf = 1e18;
const double eps = 1e-10;

template<typename T>
T gcd(T a, T b)
{
    while (a > 0 && b > 0)
    {
        if (a > b) a %= b;
        else b %= a;
    }

    return a + b;
}

template<typename T>
T nok(T a, T b)
{
    return (a * b) / gcd(a, b);
}

template<typename T>
T binPow(T x, T y, T mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        ll t = binPow(x, y / 2, mod) % mod;
        return (t * t) % mod;
    }
    return (x * binPow(x, y - 1, mod)) % mod;
}


struct Seg {
    vector<vector<pii>> t;
    
    Seg(int size) {
        t.resize(4 * size);
    }
    
    void build(vector<int>& a, int v, int l, int r, int& mx) {
        if (r - l == 1) { t[v].push_back({a[l], 0}); return; }

        int m = (r + l) / 2;

        build(a, 2 * v + 1, l, m, mx);
        build(a, 2 * v + 2, m, r, mx);

        t[v].resize(t[2 * v + 1].size() + t[2 * v + 2].size());

        int l1 = 0, l2 = 0;

        for (int i = l; i < r; ++i) {
            if (l + l1 < m && l2 + m < r) {
                if (t[2 * v + 1][l1].first <= t[2 * v + 2][l2].first) {
                    t[v][l1 + l2] = t[2 * v + 1][l1];
                    ++l1;
                }
                else {
                    t[v][l1 + l2] = t[2 * v + 2][l2];
                    t[v][l1 + l2].second += m - l1;
                    mx = max(mx, t[v][l1 + l2].second);
                    ++l2;
                }
            }
            else break;
        }

        while (l + l1 < m) {
            t[v][l1 + l2] = t[2 * v + 1][l1];
            ++l1;
        }

        while (l2 + m < r) {
            t[v][l1 + l2] = t[2 * v + 2][l2];
            ++l2;
        }
    }

    pair<int, int>& operator[] (int idx) {
        return t[0][idx];
    }

};

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    forv(v) cin >> el;
    int mx = 0;

    Seg s(n);
    s.build(v, 0, 0, n, mx);

    if (mx == 0) {cout << -1 << endl; return;}
    
    int start = -1, end = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i].second != mx && s[i].second != 0) { cout << -1 << endl; return; }
        if (s[i].second == mx) {
            end = s[i].first;

            if (start == -1) start = s[i].first;
        }
    }

    int idx1 = -1, idx2 = -1, idxx2 = -1;
    bool flag = true;

    forn(i, 0, n - 1) {
        if (v[i] == start) {
            if (flag) {
                idx2 = i;
                flag = false;
            }
        }

        if (v[i] == end) {
            idxx2 = i;
        }

        if (idxx2 != -1 && v[i] != idxx2) break;
    }

    int cnt = 0;

    dforn(i, idx2 - 1, 0) {
        if (v[i] > start) { idx1 = i, ++cnt; }
        else break;
    }

    cout << idx1 + 1 << ' ' << cnt << endl;
    cout << idx2 + 1 << ' ' << idxx2 - idx2 + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;

    while (t--)
        solve();


    return 0;
}

