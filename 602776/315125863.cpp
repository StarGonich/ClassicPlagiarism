#include <iostream>
#include <cmath>
#include <algorithm>

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

struct seg {
    int l, r;
} b[200000];

int a[200000], d[200000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        d[i] = a[i];
    }

    sort(a, a + n);

    int m = 0, p = -1, left = 0;
    
    for (int i = 0; i < n; ++i) {
        int c = lower_bound(a, a + n, d[i]) - a;
        if (p != -1 && c - p != 1) {
            b[m].l = left;
            b[m].r = i - 1;
            left = i;
            ++m;
        }
        p = c;
    }
    b[m].l = left;
    b[m].r = n - 1;
    ++m;

    if (m > 10 || m == 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            swap(b[i], b[j]);

            bool f = 1;
            for (int k = 0; k < m - 1; ++k) {
                if (d[b[k].r] >= d[b[k + 1].l]) {
                    f = 0;
                    break;
                }
            }

            if (f) {
                seg s1 = b[i], s2 = b[j];
                if (s1.l > s2.l) {
                    swap(s1, s2);
                }
                cout << s1.l + 1 << " " << s1.r - s1.l + 1 << endl;
                cout << s2.l + 1 << " " << s2.r - s2.l + 1 << endl;
                return 0;
            }

            swap(b[i], b[j]);
        }
    }
}