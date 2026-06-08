#include <iostream>
#include <cmath>

using namespace std;

/*const int INF = 1000000;

int d[1000][101];

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < 1000; ++i) {
        for (int j = 0; j <= 100; ++j) {
            d[i][j] = INF;
        }
    }
}*/

#include <queue>

int x[100000], d[100000];

queue<int> q;

int main() {
    int n, k;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    cin >> k;

    q.push(k - 1);

    int l = k - 1, r = k - 1;
    int ans = 0;

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        ++ans;

        int cr = max(c, r), cl = min(c, l);

        while ((cr < n) && (x[cr] <= x[c] + d[c])) {
            if (cr > r) {
                r = cr;
                q.push(cr);
            }
            ++cr;
        }

        while ((cl >= 0) && (x[cl] >= x[c] - d[c])) {
            if (cl < l) {
                l = cl;
                q.push(cl);
            }
            --cl;
        }
    }

    cout << ans << endl;
}