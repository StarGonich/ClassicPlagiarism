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

int n;

int main() {
    cin >> n;
    if (n == 4) {
        return 1;
    }

    if (n == 1) {
        cout << "1 1" << endl;
        return 0;
    }

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; ++i) {
            cout << "3 4 ";
        }
        cout << 5 * (n / 2);
    }
    else {
        for (int i = 0; i < n - 2; ++i) {
            cout << "1 ";
        }
        cout << "2 " << n / 2 + 1 << " " << n / 2 + 2 << endl;
    }
}