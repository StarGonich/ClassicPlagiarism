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

vector<vector<vi>> a;
vector<int> ans;

int n, m, k;

void func(vector<vi> x) {
    vector<vi> b(n + 2, vi(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int sum = x[i - 1][j - 1] + x[i - 1][j] + x[i - 1][j + 1] + x[i][j - 1] + x[i][j + 1] + x[i + 1][j - 1] + x[i + 1][j] + x[i + 1][j + 1];
            if (x[i][j] == 1 && (sum == 2 || sum == 3)) {
                b[i][j] = 1;
            } else if (x[i][j] == 0 && sum == 3) {
                b[i][j] = 1;
            } else {
                b[i][j] = 0;
            }
            //print1(b[i][j]);
        }
        //cout << "\n";
    }
    int f = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i][j] != b[i][j]) {
                f = 0;
                break;
            }
        }
    }
    if (f == 1) {
        return;
    }
    if (count(all(a), b) != 0) {
        ans.pb(find(all(a), b) - a.begin() + 1);
    }
    if (len(ans) == k) {
        print(ans);
        exit(0);
    }
    func(b);
}

void solve() {
    cin  >> k >> n >> m;
    a.resize(k, vector<vi>(n + 2, vi(m + 2, 0)));
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= m; l++) {
                cin >> a[i][j][l];
            }
        }
    }
    //cout << "\n";
    for (int i = 0; i < k; i++) {
        ans.clear();
        ans.pb(i + 1);
        func(a[i]);
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("2.txt", "r", stdin);
    // freopen("1.txt", "w", stdout);
    int _ = 1;
    //cin >> _;
    while(_--)
    {
        solve();
    }
}
