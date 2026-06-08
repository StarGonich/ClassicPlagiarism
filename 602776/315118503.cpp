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

/*struct seg {
    int l, r;
} b[200000];

int a[200000];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int p = 0, m = 0;

    for (int i = 0; i < n; ++i) {
        if (i == n - 1 || a[i] >= a[i + 1]) {
            b[m].l = p;
            b[m].r = i;
            m++;
            p = i + 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << b[i].l << " " << b[i].r << endl;
    }

    if (m > 10 || m == 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            swap(b[i], b[j]);

            bool f = 1;
            for (int k = 0; k < m - 1; ++k) {
                if (a[b[k].r] >= a[b[k + 1].l]) {
                    f = 0;
                    break;
                }
            }

            if (f) {
                cout << b[i].l + 1 << " " << b[i].r - b[i].l + 1 << endl;
                cout << b[j].l + 1 << " " << b[j].r - b[j].l + 1 << endl;
                return 0;
            }

            swap(b[i], b[j]);
        }
    }
}*/

const double MAGIC[4]{ 0.02, 0.06, 0.18, 1 };

int main() {
    int money = 210, losses = 0;

    for (int i = 0; i < 100; ++i) {
        int cur = ceil(MAGIC[losses] * money);

        cout << cur << " R" << endl;

        int res;

        cin >> res;

        if (res == -1) {
            return 0;
        }

        if (res == 0) {
            money -= cur;
            ++losses;
        }
        else {
            money += cur;
            if (money >= 1000) {
                return 0;
            }
            losses = 0;
        }
    }
}