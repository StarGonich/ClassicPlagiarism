#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    vector<int> x(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    cin >> k; --k;

    int s = 1;
    int l = x[k] - d[k];
    int r = x[k] + d[k];
    int lk = k;
    int rk = k;
    while(true) {
        if ((lk != 0) && (x[lk - 1] >= l)) {
            ++s;
            --lk;
            l = min(l, x[lk]-d[lk]);
            r = max(r, x[lk]+d[lk]);
        }
        else if ((rk != n-1) && (x[rk + 1] <= r)){
            ++s;
            ++rk;
            l = min(l, x[rk]-d[rk]);
            r = max(r, x[rk]+d[rk]);
        }
        else break;
    }
    cout << s;
}

