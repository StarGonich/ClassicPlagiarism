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
        t.resize(4 * size, { {0, 0} });
    }
    
    void build(vector<int>& a, int v, int l, int r) {
        if (r - l == 1) { t[v][0] = {a[l], 0}; return; }

        int m = (r + l) / 2;

        build(a, 2 * v + 1, l, m);
        build(a, 2 * v + 2, m, r);

        t[v].resize(t[2 * v + 1].size() + t[2 * v + 2].size());

        int l1 = 0, l2 = 0;

        for (int i = l; i < r; ++i) {
            if (l1 < m && l2 + m < r) {
                
            }
        }
    }

};

void solve() {
    int n;
    cin >> n;


    int res = n / 4 + n / 5 + n / 6;
    res -= n / 20 * 2;
    res -= n / 12 * 2;
    res -= n / 30 * 2;

    res += (n / 60) * 3;

    cout << res << endl;
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

