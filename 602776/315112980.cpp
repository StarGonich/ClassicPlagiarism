#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int& i : p) {
        cin >> i;
    }
    p.push_back(1e6); // KEK

    vector<pair<int, int>> segs;
    {
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (p[i + 1] - p[i] != 1) {
                segs.emplace_back(l, i + 1 - l);
                l = i + 1;
            }
        }
    }

    if (segs.size() > 5) {
        cout << "-1\n";
        return 0;
    }

    /*
    for (auto [l, len] : segs) {
        cout << l << " " << len << "\n";
    }
    */

    for (int i = 0; i < segs.size(); i++) {
        for (int j = i + 1; j < segs.size(); j++) {
            vector<int> cur;
            for (int k = 0; k < i; k++) {
                for (int t = 0; t < segs[k].second; t++) {
                    cur.push_back(p[segs[k].first + t]);
                }
            }
            for (int t = 0; t < segs[j].second; t++) {
                cur.push_back(p[segs[j].first + t]);
            }
            for (int k = i + 1; k < j; k++) {
                for (int t = 0; t < segs[k].second; t++) {
                    cur.push_back(p[segs[k].first + t]);
                }
            }
            for (int t = 0; t < segs[i].second; t++) {
                cur.push_back(p[segs[i].first + t]);
            }
            for (int k = j + 1; k < segs.size(); k++) {
                for (int t = 0; t < segs[k].second; t++) {
                    cur.push_back(p[segs[k].first + t]);
                }
            }

            /*
            cout << i << " " << j << ": ";
            for (int k : cur) {
                cout << k << " ";
            }
            cout << endl;
            */

            bool flg = true;
            for (int k = 0; k < n; k++) {
                if (cur[k] != k + 1) {
                    flg = false;
                    break;
                }
            }
            if (flg) {
                cout << segs[i].first + 1 << " " << segs[i].second << "\n";
                cout << segs[j].first + 1 << " " << segs[j].second << "\n";
                return 0;
            }
        }
    }
    cout << "-1\n";
}