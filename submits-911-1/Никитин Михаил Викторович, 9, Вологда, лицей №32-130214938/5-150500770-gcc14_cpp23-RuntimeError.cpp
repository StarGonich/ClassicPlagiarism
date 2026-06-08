#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull MOD = 1000000007;
ull P = 2;
int main() {
    int k, n, m;
    cin >> k >> n >> m;
    map <ull, int> ma;
    vector<vector<vector<int > > > v(k, vector<vector<int > >(n + 2, vector<int >(m + 2)));
    for (int x = 0; x < k; x++) {
        ull h = 0;
        for (int i = 1; i <= n; i++) {
            ull h1 = 0;
            for (int j = 1; j <= m; j++) {
                int a;
                cin >> a;
                v[x][i][j] = a;
                h1 *= P;
                h1 += a;
                h1 %= MOD;
            }
            h *= P;
            h += h1;
            h %= MOD;
        }
        ma[h] = x;
    }
    vector<int> pre(n, -1);
    int st = 0;
    for (int x = 0; x < k; x++) {
        bool is = 1;
        vector<vector<int > > b;
        vector<vector<int > > nb;
        b = v[x];
        while (is) {
            ull h = 0;
            for (int i = 1; i <= n; i++) {
                ull h1 = 0;
                for (int j = 0; j <= m; j++) {
                    int sum = b[i - 1][j - 1] + b[i - 1][j + 1] + b[i + 1][j - 1] + b[i + 1][j + 1];
                    sum += b[i - 1][j] + b[i][j + 1] + b[i + 1][j] + b[i][j - 1];
                    h1 *= P;
                    int a = 0;
                    if (sum == 2 || sum == 3) {
                        a = 1;
                    }
                    nb[i][j] = a;
                    h1 += a;
                    h1 %= MOD;
                }
                h *= P;
                h += h1;
                h %= MOD;
            }
            if (ma[h] != 0) {
                pre[ma[h]] = x;
                is = 0;
            }
            if (h == 0) {
                st = x;
                is = 0;
            }
            b = nb;
        }
    }
    cout << st + 1 << '\n';
    while (pre[st] != -1) {
        cout << pre[st] + 1 << '\n';
        st = pre[st];
    }
    return 0;
}
