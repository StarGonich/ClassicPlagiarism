//#include<udacha$$$>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>
#include<iomanip>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<iterator>
#include<bitset>
#include<random>
#include<list>
#include<cstdio>
#include<ctime>
#include<random>
#include<cstdint>
#include<cstdlib>
#include<numeric>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
#define vll vector<ll>
void solve()
{
    ll n;
    cin >> n;
    vll A(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        cin >> A[i];
    }
    vll Pos(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        Pos[A[i]] = i;
    }
    bool f = true;
    ll pos = -1;
    for (ll i = 1; i <= n && f; ++i)
    {
        if (i != A[i])
        {
            pos = i;
            f = false;
        }
    }
    if (f)
    {
        cout << -1;
        return;
    }
    ll fin = pos;
    bool t = true;
    for (ll i = pos + 1; i <= n && t; ++i)
    {
        if (A[i] == A[i - 1] + 1)
        {
            fin = i;
        }
        else
        {
            t = false;
        }
    }
    vll Ans(4);
    Ans[0] = pos;
    Ans[1] = fin - pos + 1;
    vll Get(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        Get[i] = A[i];
    }
    for (ll i = A[pos]; i <= A[fin]; ++i)
    {
        Get[i] = i;
    }
    ll need = Pos[pos];
    ll fn = need;
    t = true;
    for (ll i = need + 1; i <= n && t; ++i)
    {
        if (A[i] == A[i - 1] + 1)
        {
            fn = i;
        }
        else
        {
            t = false;
        }
    }
    for (ll i = A[need]; i <= A[fn]; ++i)
    {
        Get[i] = i;
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (Get[i] != i)
        {
            cout << -1;
            return;
        }
    }
    Ans[2] = need;
    Ans[3] = fn - need + 1;
    if (Ans[1] + Ans[0] - 1 >= Ans[2])
    {
        cout << -1;
        return;
    }
    cout << Ans[0] << ' ' << Ans[1] << '\n' << Ans[2] << ' ' << Ans[3];
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}