#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    ll sum = 0;
    queue<int> q;
    int rs = - 1, c = 0, lo = -1;
    for (int i = 0; i < n; ++i) {
        //cout << sum << "\n";
        int l, r;
        cin >> l >> r;
    	l++;
        if (c) {
            continue;
        }
        if (rs == -1) {
            rs = r;
            int d = l;
            while (d <= r) {
                q.push(1);
                if (q.size() > 3600) {
                    if (q.front() == 1) {
                        sum--;
                    }
                    q.pop();
                }
                sum ++;
                d++;
                if (sum > t) {
                    c = 1;
                    lo = d - 3600;
                    break;
                }
            }
        }
        else {
            int x = l - rs - 1;
            while (q.size() < 3600 && x > 0) {
                q.push(0);
                x--;
            }
            while (x != 0) {
                if (q.front() == 1) {
                    sum--;
                }
                q.pop();
                q.push(0);
                x--;
            }
            int d = l;
            while (d <= r) {
                //cout << sum << " || " << l << " || " << d << "\n";
                q.push(1);
                sum++;
                if (q.size() > 3600) {
                    if (q.front() == 1) {
                        sum--;
                    }
                    q.pop();
                }
                if (sum > t) {
                    c = 1;
                    lo = d - 3600 + 2;
                    break;
                }
                d++;
            }
            rs = r;
        }
    }
    cout << lo;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("", "r", inout)

    int _ = 1;
    //cin >> _;
    while (_--) {
        solve();
    }
}
