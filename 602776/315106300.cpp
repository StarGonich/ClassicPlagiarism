#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& G, int s, int end, int n) {
    queue<int>q;
    q.push(s);
    vector<bool>used(n + 1);
    vector<int>d(n + 1, -1), p(n + 1);
    used[s] = 1;
    d[s] = 0;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : G[v]) {
            if (!used[to]) {
                used[to] = 1;
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    return d[end];
}

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

// 4 5 6 8 10 15 

void solve() {
    int n;
    cin >> n;
    cout << (n / 4) + (n / 5) + (n / 6) - (n / 12) * 2 - (n / 20) - (n / 30) * 2 ;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
