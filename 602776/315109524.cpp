#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define endl '\n'
#define EPS 1e-8
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define rt return;
#define all(x) (x).begin(), (x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n = 0;
    cin >> n;
    if (n < 4) {
        cout << 0 << endl;
        return 0;
    }

    int lg = log10(n);

    int cnt = 3;

    if (lg < 2) {
        for (int i = 7; i <= n; i++) {
            if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0) {
                cnt++;
            }
            if (i % 5 == 0 && i % 4 != 0 && i % 6 != 0) {
                cnt++;
            }
            if (i % 6 == 0 && i % 5 != 0 && i % 4 != 0) {
                cnt++;
            }
        }
    }else {
        for (int i = 1; i < lg; i++) {
            cnt += 3 * pow(10,i);
        }
        cnt -= 1;
        for (int i = pow(10,lg) + 1; i <= n; i++) {

            if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0) {
                cnt++;
            }
            if (i % 5 == 0 && i % 4 != 0 && i % 6 != 0) {
                cnt++;
            }
            if (i % 6 == 0 && i % 5 != 0 && i % 4 != 0) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
