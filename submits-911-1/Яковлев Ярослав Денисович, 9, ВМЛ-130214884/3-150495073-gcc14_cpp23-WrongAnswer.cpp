#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<pair<int,int>> times;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        times.push_back({x, y});
    }
    sort(times.begin(), times.end());
    vector<bool> g(times.back().second+1, 0);
    for(auto& [x, y] : times) {
        for(int i = x; i <=y; i++) {
            g[i] = 1;
        }
    }
    for(int i = 0; i < times.back().second+1 - 3600; i++) {
        int cnt = 0;
        for(int j = i; j <= i + 3599; j++) {
            if(g[j]) cnt++;
        }
        if(cnt > t) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
