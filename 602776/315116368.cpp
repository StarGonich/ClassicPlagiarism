#include <iostream>
#pragma optimize("O3")
using namespace std;

int main() {
    int n = 0;
    int ans = 0;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int curr_cnt = 0;
        if (i % 4 == 0)
            curr_cnt += 1;
        if (i % 5 == 0)
            curr_cnt += 1;
        if (i % 6 == 0)
            curr_cnt += 1;
        if (curr_cnt == 1) {
            ans += 1;
        }
    }

    cout << ans;
}