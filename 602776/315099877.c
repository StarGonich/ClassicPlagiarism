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


void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    forv(v) cin >> el;

    vector<int> d(n);

    forv(d) cin >> el;


    queue<int> q;
    int res = 1;
    vector<int> marks(n, -1);

    int k;
    cin >> k;
    --k;
    
    marks[k] = 1;
    q.push(k);

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();


        for (int i = tmp + 1; i < n; ++i) {
            if (v[tmp] + d[tmp] >= v[i] && marks[i] == -1) {
                marks[i] = 1;
                ++res;

                q.push(i);
            }
            else {
                if (marks[i] == -1) break;
            }
        }

        dforn(i, tmp - 1, 0) {
            if (v[tmp] + d[tmp] >= v[i] && marks[i] == -1) {
                marks[i] = 1;
                ++res;

                q.push(i);
            }
            else {
                if (marks[i] == -1) break;
            }
        }
    }

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

