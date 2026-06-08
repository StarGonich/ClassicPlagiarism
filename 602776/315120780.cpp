#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

#define ull unsigned int


int main() {
    int n;
    cin >> n;
    
    vector<ull> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    
    vector<ull> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    
    int k;
    cin >> k;
    
    set<int> visited {};
    queue<int> to_visit;
    to_visit.push(k-1);
    
    while (!to_visit.empty()) {
        int mine = to_visit.front();
        to_visit.pop();
        
        // cout << mine << ' ' << x[mine] << ' ' << d[mine] << '\n';
        if (visited.contains(mine))
            continue;
        visited.insert(mine);
        
        ull mn = x[mine] - d[mine];
        ull mx = x[mine] + d[mine];
        
        // cout << mn << ' ' << mx << '\n';
        
        auto min = x.begin();
        if (d[mine] <= x[mine])
            min = lower_bound(begin(x), end(x), x[mine] - d[mine]);
        
        auto max = x.end();
        if (mx <= x[n-1])
            max = upper_bound(begin(x), end(x), x[mine] + d[mine]);
        
        // cout << distance(begin(x), min) << ' ' << distance(begin(x), max) << '\n';
        
        for (auto &it = min; it < max; it++) {
            to_visit.push(distance(begin(x), it));
        }
    }
    
    cout << visited.size();
    
    return 0;
}