//#include <udacha$$$>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;
using vll = vector <ll>;
using vpll = vector <pll>;
using vvll = vector <vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll len = 1e6 + 1;

void solve();


int main()
{
    int t = 1; //cin >> t;
    while (t--)
        solve();
}

void solve()
{
    vll nodbl(len), dbl(len), pref_no(len), pref_db(len);
    nodbl[1] = nodbl[2] = 1;
    pref_no[1] = 1; pref_no[2] = 2;
    for (int i = 3; i < len; ++i)
    {
        nodbl[i] = (1 + pref_no[i - 2]) % MOD;
        pref_no[i] = (pref_no[i - 1] + nodbl[i]) % MOD;
    }
    dbl[2] = 1; dbl[3] = 2; dbl[4] = 5;
    pref_db[2] = 1; pref_db[3] = 3; pref_db[4] = 8;
    for (int i = 5; i < len; ++i)
    {
        dbl[i] = (pref_db[i - 1] + pref_no[i - 3]) % MOD;
        pref_db[i] = (pref_db[i - 1] + dbl[i]) % MOD;
    }
    ll n; cin >> n;
    cout << dbl[n];

}
