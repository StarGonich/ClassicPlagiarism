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

vvpi gr;
vi c;
vi p;
vi pok;

vi f(int st){
    int n = (int)c.size();
    p.resize(n);
    pok.assign(n,0);
    vi tmp(n,1e18);
    vi from(n,-1);
    queue<int>q;
    vi dist(n,1e18);
    dist[st] = 0;
    tmp[st] = c[st];
    from[st] = st;
    q.push(st);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto [to,w]:gr[v]){
            tmp[to] = min(c[to], tmp[v]);
            if(tmp[to] == tmp[v])from[to] = from[v];
            else from[to] = to;
            if(dist[to] > dist[v] + tmp[v]*w){
                dist[to] = dist[v] + tmp[v]* w;
                pok[from[v]] += w;
                p[to] = v;
                q.push(to);
            }
        }
    }
    return dist;
}

void solve() {
  int n,m;cin >> n >> m;
  c.resize(n);
  for(auto &it:c)cin >> it;
  gr.resize(n);
  for(int i=0;i<m;i++){
      int u,v,w;cin >> u >> v >> w;
      u--;v--;
      gr[u].pb({v,w});
      gr[v].pb({u,w});
  }
  vvi dist(n, vi(n,1e18));
  vvi _p(n, vi(n,-1));
  vvi _pok(n, vi(n,0));
  for(int i=0;i<n;i++){
      auto it = f(i);
      for(int j=0;j<n;j++){
          if(it[j] < dist[i][j]) {
              dist[i][j] = min(dist[i][j], it[j]);
              _p[i][j] = p[j];
              _pok[i][j] = pok[j];
          }
      }
  }
  int ans = 1e18;
  for(int i=0;i<n;i++){
      ans = min(ans, dist[0][i] + dist[i][n-1]);
  }
  if(ans == (int)1e18){
      cout << -1 << "\n";
      return;
  }
  vi dp2(n,1e18);
  dp2[0] = 0;
  vi pred(n,-1);
  for(int i=1;i<n;i++){
      for(int j=0;j<i;j++){
          dp2[i] = min(dp2[i], dp2[j] + dist[j][i]);
          if(dp2[i] ==  dp2[j] + dist[j][i]){
              pred[i] = j;
          }
      }
  }
  cout << dp2[n-1] << "\n";
  int kk = n-1;
    vi ot;
    ot.pb(kk);
  while(kk) {

      int k = kk;
      int too = pred[kk];
      while (k != too) {
          k = _p[too][k];
          ot.pb(k);
      }
      kk = k;
  }
      reverse(all(ot));
      vi tmp(n, 1e18);
      vi from(n, -1);
      vi aa(n, 0);
      tmp[0] = c[0];
      from[0] = 0;
      int k = 0;
      for (int i = 1; i < (int) ot.size(); i++) {
          for (auto [to, w]: gr[k]) {
              if (to == ot[i]) {
                  aa[from[k]] += w;
                  tmp[to] = min(tmp[k], c[to]);
                  if (tmp[to] == c[to])from[to] = to;
                  else from[to] = from[k];
                  k = to;
                  break;
              }
          }
      }
  cout << (int)ot.size() << "\n";
  for(auto it:ot){
      cout << it+1 << " " << aa[it] << "\n";
      aa[it] = 0;
  }
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
