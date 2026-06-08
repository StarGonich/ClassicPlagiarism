#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e9;


void solve() {
    int s1, s2;
    int f1, f2;
    cin >> s1 >> s2 >> f1 >> f2;
    if (f1 * 60 + f2 < s1 * 60 + s2) {
        f1 += 24;
    }
    s2 += s1 * 60;
    f2 += f1 * 60;
    set<vector<int>> s;
    for (int j = s2; j <= f2; j++) {
        vector<int> num(4);
        int i = (j % (24 * 60));
        s1 = i / 60;
        num[1] = s1 % 10;
        s1 /= 10;
        num[0] = s1 % 10;
        s2 = i % 60;
        num[3] = s2 % 10;
        s2 /= 10;
        num[2] = s2 % 10;
        if (num[0] == num[2] && num[1] == num[3]) {
            s.insert(num);
        }
        else if (num[0] == num[3] && num[1] == num[2]) {
            s.insert(num);
        }
        else if (num[0] + 1 == num[1] && num[1] + 1 == num[2] && num[2] + 1 == num[3]) {
            s.insert(num);
        }
    }
    cout << s.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
