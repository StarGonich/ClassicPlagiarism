#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;

int bins(vector<int>& v, int x) {
    int l = 0, r = v.size()-1;
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] >= x) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    int k;
    cin >> k; --k;

    int s = 0;
    vector<bool> b(n, false);
    stack<int> f;
    f.push(k);
    while (!f.empty()) {
        ++s;
        int t = f.top();
        f.pop();
        b[t] = true;
        //cout << t << " : " << x[t] << "|" << d[t] << " : ";
        int l = bins(x, x[t] - d[t]);
        int r = bins(x, x[t] + d[t]);
        if (r > 0 && (r == n || x[r] > x[t] + d[t])) --r;
        //cout << l << " " << r << " : ";
        for (int j = l; j <= r; ++j) {
            if (!b[j]) {
                //cout << j << " ";
                f.push(j);
            }
        }
        //cout << "\n";
    }
    cout << s;
}
