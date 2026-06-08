#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> st = {14, 28, 56, 112};
    int s = 210, k = 0;

    int t = 1;
    while (t <= 100) {
        cout << st[k] << ' ' << "R\n";
        fflush(stdout);

        int x;
        cin >> x;

        if (x == 1) {
            s += st[k];
            k = 0;

            int x = st[0], y = x + 1;
            while ((y + 2 * y + 4 * y + 8 * y) <= s) {
                x++;
                y++;
            }

            st[0] = x;
            st[1] = 2 * x;
            st[2] = 4 * x;
            st[3] = 8 * x;
        }
        if (!x) {
            s -= st[k];
            k++;
        }
        if (x == -1 || s >= 1000) return 0;

        t++;
    }

    return 0;
}
