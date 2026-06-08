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
    bool change = 1;
    while(change) {
        change = 0;
        int id1 = -1, id2 = -1;
        pair<int,int> lol;
        for(int i = 0; i < times.size(); i++) {
            if(change) break;
            for(int j = i + 1; j < times.size(); j++) {
                int x1 = times[i].first, y1 = times[i].second, x2 = times[j].first, y2 = times[j].second;
                if(x1 <= x2 && y1 >= x2) {
                    id1 = i; id2 = j;
                    lol = {min(x1,x2),max(y1,y2)};
                    change = 1;
                    break;
                }
            }
        }
        if(change) {
            vector<pair<int,int>> cur;
            for(int i = 0; i < times.size(); i++) {
                if(id1 != i && id2 != i) cur.push_back(times[i]);
            }
            cur.push_back(lol);
            sort(cur.begin(), cur.end());
            times = cur;
        }
    }
    for(int i = 0; i <= times.back().second - 3599; i++) {
        int cnt = 0;
        for(int j = 0; j < times.size(); j++) {
            if(times[j].first > i + 3599) {
                break;
            }
            else if(times[j].second < i) {
                continue;
            }
            else{
                if(times[j].first >= i && times[j].second <= i + 3599) {
                    cnt += times[j].second - times[j].first;
                }
                else if(times[j].first < i && times[j].second > i + 3599) {
                    cnt += times[j].second - i;
                    cnt += (i + 3599) - times[j].first;
                }
                else if(times[j].first < i){
                    cnt += times[j].second - i;
                }
                else if(times[j].second > i + 3599) {
                    cnt += (i + 3599) - times[j].first;
                }
            }
        }
        if(cnt > t) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
