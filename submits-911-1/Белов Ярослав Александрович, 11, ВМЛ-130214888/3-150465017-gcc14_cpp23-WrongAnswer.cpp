#include "bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#define all1(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define len(x) x.size()
#define maxe(a) *max_element(all(a))
#define mine(a) *min_element(all(a))
#define int long long
#define pb push_back
#define double long double
#define str string
#define F first
#define S second
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define debug(x) cout << (#x) << ": "; print(x)

using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
const int INF = INT_MAX;

void print(int n){ cout<<n<<"\n"; }
void print1(int n){ cout<<n<<" "; }

void print(vi a)
{
    for(int i = 0;i < len(a); i++) print1(a[i]);
    cout << endl;
}


void solve() {
    int n, t;
    cin >> n >> t;
    int h = 3600;
    vector<pii> a(n);
    vector<int> b(n);
    vi c(n + 1);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        b[i] = y - x;
        c[i + 1] = c[i] + b[i];
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int l = -1;
        int r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[i].S - h <= a[m].F) {
                r = m;
            } else {
                l = m;
            }
        }
        pii x;
        if (l == -1){
            x = {0, 0};
        } else {
            x = a[l];
        }
        //cout << r << " ";
        int sum = c[i + 1] - c[r];
        sum += max(0ll, x.S - max(0ll, a[i].S - h));
        int pos = max(0ll, a[i].S - h);
        //cout << i << " " << sum << "\n";
        if (sum > t) {
            if (x.F <= pos && pos <= x.S) {
                if (a[i].S - h - x.F > a[i].S - a[i].F) {
                    pos = a[i].F - h;
                } else {
                    pos = x.F;
                }
            }
            //cout << a[i].S - h - x.F << " " << a[i].S - a[i].F << " " << pos << "\n";
            pos -= sum - t - 1;
            pos = max(0ll, pos);
            ans = min(pos, ans);
            //cout << ans;
        }
    }
    if (ans == INF) cout << -1;
    else cout << ans;
}


signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // freopen("2.txt", "r", stdin);
    // freopen("1.txt", "w", stdout);
    int _ = 1;
    //cin >> _;
    while(_--)
    {
        solve();
    }
}
