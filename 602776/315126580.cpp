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
    
    vector<bool> visited(n);
    
    int k;
    cin >> k;

    queue<int> to_visit;
    to_visit.push(k-1);
    
    while (!to_visit.empty()) {
        int mine = to_visit.front();
        to_visit.pop();
        
        visited[mine] = true;
        
        ull mn = x[mine] - d[mine];
        ull mx = x[mine] + d[mine];
 
        auto min = x.begin();
        if (d[mine] <= x[mine])
            min = lower_bound(begin(x), end(x), mn);
        
        auto max = x.end();
        if (mx <= x[n-1])
            max = upper_bound(begin(x), end(x), mx);

        for (auto &it = min; it < max; it++) {
            mine = distance(begin(x), it);
            if (!visited[mine])
                to_visit.push(mine);
        }
    }
    
    int ans = 0;
    for (bool i : visited)
        if (i)
            ans++;
    cout << ans;
    
    return 0;
}