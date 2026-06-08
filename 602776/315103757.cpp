#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n], d[n];
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    int k;
    cin >> k;
    --k;
    int left    = k - 1;
    int right   = k + 1;

    int left_x  = x[k] - d[k];
    int right_x = x[k] + d[k];

    int ans = 1;
    while (true) {
        const int last_ans = ans;
        while (left > -1 && x[left] >= left_x) {
            left_x = min(left_x, x[left] - d[left]);
            right_x = max(right_x, x[left] + d[left]);
            --left;
            ++ans;
        }
        while (right < n && x[right] <= right_x) {
            left_x = min(left_x, x[right] - d[right]);
            right_x = max(right_x, x[right] + d[right]);
            ++right;
            ++ans;
        }
        if (last_ans == ans)
            break;
    }

    cout << ans << '\n';
    return 0;
}
