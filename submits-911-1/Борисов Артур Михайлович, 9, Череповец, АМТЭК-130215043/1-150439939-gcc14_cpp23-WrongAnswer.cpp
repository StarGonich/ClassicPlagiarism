#include <iostream>

using namespace std;

int main()
{
    int h1, h2, m1, m2, ans = 0;
    cin >> h1 >> m1 >> h2 >> m2;
    if (h1 <= h2) {
        for (int i = h1; i <= h2; i++) {
            int l1 = 0, l2 = 59;
            if (i == h1) {
                l1 = m1;
            }
            if (i == h2) {
                l2 = m2;
            }
            for (int j = l1; j <= l2; j++) {
                if ((i == j) or (i == j % 10 * 10 + j / 10) or ((i == 1 and j == 23 or i == 12 and j == 34 or i == 23 and j == 45))) {
                    ans++;
                }
            }
        }
    }
    else {
        for (int i = h1; i <= 23; i++) {
            int l1 = 0, l2 = 59;
            if (i == h1) {
                l1 = m1;
            }
            if (i == h2) {
                l2 = m2;
            }
            for (int j = l1; j <= l2; j++) {
                if ((i == j) or (i == j % 10 * 10 + j / 10) or ((i == 1 and j == 23 or i == 12 and j == 34 or i == 23 and j == 45))) {
                    ans++;
                }
            }
        }
        for (int i = 0; i <= h2; i++) {
            int l1 = 0, l2 = 59;
            if (i == h1) {
                l1 = m1;
            }
            if (i == h2) {
                l2 = m2;
            }
            for (int j = l1; j <= l2; j++) {
                if ((i == j) or (i == j % 10 * 10 + j / 10) or ((i == 1 and j == 23 or i == 12 and j == 34 or i == 23 and j == 45))) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}