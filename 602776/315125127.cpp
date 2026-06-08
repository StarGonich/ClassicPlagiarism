#include <bits/stdc++.h>
//#pragma once

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")

#define int long long
//#define int short
//#define int long double
#define vi vector<int>
#define vvi vector<vector<int>>
//#define vs vector<string>
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(), x.end()
#define ins insert
#define fi first
#define se second
#define vpi vector<pii>
#define double long double
#define vvpi vector<vector<pair<int,int>>>
#define vsi vector<set<int>>
#define lb(v,x) lower_bound(all(v),x)
#define ub(v,x) upper_bound(all(v), x)
#define uni(v) v.resize(unique(all(v)) - v.begin())
#define p_queue priority_queue

using namespace std;
int mod = 1000000007;
int INF = 1e18;
double eps = 1e-8;
double pi = 3.14159265359;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

std::istream& operator >> (std::istream& in, pii& p)
{
    in >> p.fi >> p.se;
    return in;
}

std::ostream& operator << (std::ostream &os, const pii &p)
{
    return os << p.fi << " " << p.se;
}

std::istream& operator >> (std::istream& in, vi& p)
{
    for(auto &it:p)in >> it;
    return in;
}

std::ostream& operator << (std::ostream &os, const vi &p)
{
    for(auto it:p)os << it << " ";
    return os;
}

int binpowmod(int n, int m, int md = mod);
int binpow(int n, int m);
void print(vector<vector<int>>&a);
void print(vector<vector<bool>>&a);
void print(vector<vpi>&a);
void print(vector<vector<pair<double,double>>>&a);
void print(vector<int>&a);
void print(vector<pii>&a);
void print(vector<double>&a);
int obr(int n);
int fact(int n);
int cnk(int n, int k);
int cnk_fast(int n, int k);
int obr(int n, int md=mod);
vi fct;

std::random_device rd;  // a seed source for the random number engine
std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> distrib(1, (int)1e9);

int min(pii p){
    return min(p.fi,p.se);
}

int max(pii p) {
    return max(p.fi, p.se);
}

vvi umn(vvi& a, vvi& b, int n) {
    vvi c(n, vi(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

vvi pw(vvi mat, int m, int n) {
    vvi res(n, vi(n, 0));
    for (int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    while (m) {
        if (m % 2) {
            res = umn(res, mat, n);
        }
        mat = umn(mat, mat, n);
        m /= 2;
    }
    return res;
}

bool check(vi &a){
    int sm = 0;
    for(int i=0;i<(int)a.size()-1;i++)sm += a[i]*a[i];
    if(sm == a.back()*a.back()){
        return true;
    }
    return false;
}

void solve() {
    int n;cin >> n;
    vi dp(n+10,1e18);
    vi p(n+10);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j + i*i <= n) {
                dp[i * i + j] = min(dp[i * i + j], dp[j] + 1);
                if (dp[i * i + j] == dp[j] + 1) {
                    p[i * i + j] = i;
                }
            }
        }
    }
    vvi a{{1,1}, {3,4,5},{1,2,2,3}, {1,1,1,1,2}};
    int pp = 1;
    vi _p;
    int i = p[n];
    int sm = n;
    while(sm){
        _p.pb(i);
        sm -= i*i;
        i = p[sm];
    }
    //print(_p);
    for(auto it:_p)pp*=(it*it);
    vi ans;
    vi from;
    for(auto it:a[dp[n]-1])from.pb(it*pp);
    for(int i=0;i<(int)_p.size();i++){
        int it = _p[i];
        for(int j=0;j<it*it;j++)ans.pb(from[i]/it);
    }
    ans.pb(from.back());
    for(auto it:ans)cout << it << " ";
   // if(check(ans))cerr << "ok" << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        //cerr << t << "\n";
        solve();
    }
}

int binpowmod(int n, int m,int md){
    int res = 1;
    if(m < 0)return 0;
    while(m){
        if(m % 2){
            res = (res*n)%md;
            res %= md;
        }
        n = (n*n)%md;
        n %=md;
        m/=2;
    }
    return res%md;
}

int binpow(int n, int m){
    if(m < 0)return 0;
    int res = 1;
    if(m == 0)return 1;
    while(m){
        if(m % 2){
            res *= n;
        }
        n *=n;
        m/=2;
    }
    return res;
}


void print(vector<vector<int>>&a){
    for(int i=0;i<(int)a.size();i++){
        for(int j=0;j<(int)a[i].size();j++){
            cerr << a[i][j] << " ";
        }
        cerr << "\n";
    }
}

void print(vector<vpi>&a){
    for(int i=0;i<(int)a.size();i++){
        for(int j=0;j<(int)a[i].size();j++){
            cerr << "(" << a[i][j].fi << "," << a[i][j].se  << ") ";
        }
        cerr << "\n";
    }
}

void print(vector<vector<pair<double,double>>>&a){
    for(int i=0;i<(int)a.size();i++){
        for(int j=0;j<(int)a[i].size();j++){
            cerr << "(" << a[i][j].fi << "," << a[i][j].se  << ") ";
        }
        cerr << "\n";
    }
}

void print(vector<int>&a){
    for(int i=0;i<(int)a.size();i++){
        cerr << a[i] << " ";
    }
    cerr << "\n";
}

void print(vector<pii>&a){
    for(int i=0;i<(int)a.size();i++){
        cerr <<"(" << a[i].fi << "," << a[i].se << ")";
        cerr << "\n";
    }
    cerr << "\n";
}

void print(vector<double>&a){
    for(int i=0;i<(int)a.size();i++)
        cerr << fixed << setprecision(3) << a[i] << " ";
    cerr << "\n";
}

int obr(int n){
    return binpowmod(n, mod-2)%mod;
}

int fact(int n){
    int res = 1;
    for(int i=1;i<=n;i++){
        res *= i;
        res %=mod;
    }
    return res%mod;
}

void print(vector<vector<bool>> &a){
    for(int i=0;i<(int)a.size();i++){
        for(int j=0;j<(int)a[i].size();j++){
            cerr << (int)a[i][j] << " ";
        }
        cerr << "\n";
    }
}

int obr(int n, int md){
    return binpowmod(n, md-2,md)%md;
}
