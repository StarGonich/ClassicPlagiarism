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
    vector<bool> time(1000000001, 0);
    vector<pair<int,int>> rekl;
    int mxi = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mxi = max(mxi, y);
        for(int i = x; i <= y; i++) {
            time[i] = 1;
        }
//        bool flg = 0;
//        for(auto& [a, b] : rekl) {
//            if(b >= x) {
//                b = max(b, y);
//                a = min(x, a);
//                flg = 1;
//                break;
//            }
//            else if(y >= a && x <= a) {
//                b = max(b, y);
//                a = min(x, a);
//                flg = 1;
//                break;
//            }
//        }
//        if(!flg) rekl.push_back({x, y});
    }
//    bool change = 1;
//    while(change) {
//        change = 0;
//        vector<pair<int,int>> cur;
//        int chidx1, chidx2;
//        for(int i = 0; i < rekl.size(); i++) {
//            if(change) break;
//            for(int j = 1; j < rekl.size(); j++) {
//                if(rekl[j].second >= rekl[i].first) {
//                    chidx1 = i, chidx2 = j;
//                    change = 1;
//                    break;
//                }
//                else if(rekl[i].second >= rekl[j].first && rekl[i].first <= rekl[j].first) {
//                    chidx1 = i, chidx2 = j;
//                    change = 1;
//                    break;
//                }
//            }
//        }
//        if(change) {
//            cur.push_back({min(rekl[chidx1].first, rekl[chidx2].first), max(rekl[chidx1].second, rekl[chidx2].second)});
//            for(int i = 0; i < rekl.size(); i++) {
//                if(i == chidx1 || i == chidx2) continue;
//                cur.push_back(rekl[i]);
//            }
//            rekl = cur;
//        }
//    }
    vector<int> prefs(mxi);
    int cur = 0;
    for(int i = 0; i < mxi; i++) {
        if(time[i]) {
            cur++;
        }
        prefs[i] = cur;
    }
    for(int i = 0; i < mxi - 3599; i++) {
        if(prefs[i + 3600 - 1] - prefs[i] > t) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
