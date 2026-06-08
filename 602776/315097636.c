#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <bitset>

using namespace std;
#define ll long long
#define ld long double
ll Fast_pow(ll st, ll ch, ll mod) {
    ll ost = 1;
    while (st > 1) {
        if (st % 2 == 1) {
            st--;
            ost *= ch;
            ost %= mod;
        }
        st /= 2;
        ch *= ch;
        ch %= mod;
    }
    return (ch * ost) % mod;
}
ll NOD(ll a, ll b) {
    if (b == 0) return a;
    else return NOD(b, a % b);
}
ll NOK(ll a, ll b, ll nod) {
    return a * b / nod;
}
vector<ll> Tree(1e7);
void update(int nom, ll ch) {
    Tree[nom] = ch;
    while (nom > 0) {
        nom /= 2;
        Tree[nom] = Tree[nom * 2] + Tree[nom * 2 + 1];
    }
}
ll Sum_Tree(ll nom, int lt, int rt, int l, int r) {
    if (l <= lt && rt <= r) {
        return Tree[nom];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n; cin >> n;
    ll tri;
    tri = 60LL;
    ll f, s, t;
    f = 12;
    s = 30;
    t = 20;
    cout << (n/5+n/6+n/4) - (n / f*2 + n / s*2 + n / t*2 - 5*(n / tri));
}