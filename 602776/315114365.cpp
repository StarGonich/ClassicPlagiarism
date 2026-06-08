#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef long double ld;

ll f[1001][1001];
std::vector<std::vector<ll>> g;

const ll inf = 100000000;

void solve() {
  ll n, m;
  std::cin >> n >> m;

  g.resize(n + 1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i != j) {
        f[i][j] = inf;
      }
    }
  }

  std::vector<ll> c(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> c[i];
  }

  for (int i = 0; i < m; ++i) {
    ll u, w, dist;
    std::cin >> u >> w >> dist;
    f[u][w] = std::min(f[u][w], dist);
    f[w][u] = std::min(f[w][u], dist);
    g[u].push_back(w);
    g[w].push_back(u);
  }

  std::set<std::pair<ll, ll>> q;
  q.insert({ 0, 1 });

  std::vector<ll> minCost = c;
  std::vector<ll> price(n + 1, inf);
  price[1] = 0;
  std::vector<std::vector<ll>> path(n + 1);

  bool found = false;
  while (!q.empty() && !found) {
    auto top = *q.begin();
    q.erase(q.begin());

    if (top.second == n) {
      continue;
    }
    //std::cout << "now at: " << top.second << ' ' << top.first << std::endl;

    for (ll adj : g[top.second]) {
      ll toAdj = top.first + f[top.second][adj] * minCost[top.second];
      bool put = false;

      if (minCost[adj] > minCost[top.second]) {
        path[adj].push_back(top.second);
        q.insert({ toAdj, adj });
        minCost[adj] = std::min(minCost[adj], minCost[top.second]);
        put = true;
      }

      if (price[adj] > toAdj) {
        price[adj] = toAdj;
        path[adj].push_back(top.second);
        q.insert({ toAdj, adj });
        minCost[adj] = std::min(minCost[adj], minCost[top.second]);
        put = true;
      }
    }
  }

  /*std::cout << "done" << std::endl;
  for (int i = 1; i <= n; ++i) {
    std::cout << i << ": ";
    for (auto x : path[i]) {
      std::cout << x <<  " ";
    }
    std::cout << std::endl;
  }*/

  if (price[n] == inf) {
    std::cout << "-1\n";
  } else {
    std::cout << price[n] << '\n';

    std::vector<ll> ansPath;
    ll iter = n;
    while (iter != 1) {
      ansPath.push_back(iter);
      ll nxt = path[iter].back();
      path[iter].pop_back();
      iter = nxt;
    }
    ansPath.push_back(1);

    std::vector<ll> toBy(n + 1);

    std::reverse(ansPath.begin(), ansPath.end());
    int i = 0;
    while (i < ansPath.size()) {
      int j = i + 1;
      while (j < ansPath.size() && c[ansPath[i]] <= c[ansPath[j]]) {
        toBy[ansPath[i]] += f[ansPath[j]][ansPath[j - 1]];
        j++;
      }
      if (j < ansPath.size()) {
        toBy[ansPath[i]] += f[ansPath[j]][ansPath[j - 1]];
      }
      i = j;
    }

    std::cout << ansPath.size() << '\n';
    for (auto x : ansPath) {
      std::cout << x << " " << toBy[x] << std::endl;
    }
  }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(NULL);

    int t = 1;
    //std::cin >> t;
    for (; t > 0; --t) {
      solve();
    }
}
