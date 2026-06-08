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
        if (Pos[i] != i)
        {
            f = false;
            pos = Pos[i];
        }
    }
    if (f)
    {
        cout << -1;
        return;
    }
    ll fin = pos;
    f = true;
    for (ll i = pos + 1; i <= n && f; ++i)
    {
        if (A[i] == A[i - 1] + 1 && A[i] != i)
        {
            fin = i;
        }
        else
        {
            f = false;
        }
    }
    vll Ans(4);
    Ans[0] = pos;
    Ans[1] = fin - pos + 1;
    vll Res(n + 1);
    for (ll i = 1; i <= n; ++i)
    {
        Res[i] = A[i];
    }
    for (ll i = A[pos]; i <= A[fin]; ++i)
    {
        Res[i] = i;
    }
    ll beg = A[pos];
    fin = beg;
    f = true;
    for (ll i = beg + 1; i <= n && f; ++i)
    {
        if (A[i] == A[i - 1] + 1 && A[i] != i)
        {
            fin = i;
        }
        else
        {
            f = false;
        }
    }
    Ans[2] = beg;
    Ans[3] = fin - beg + 1;
    for (ll i = A[beg]; i <= A[fin]; ++i)
    {
        Res[i] = i;
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (Res[i] != i)
        {
            cout << -1;
            return;
        }
    }
    if (Ans[0] > Ans[2])
    {
        swap(Ans[0], Ans[2]);
        swap(Ans[1], Ans[3]);
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