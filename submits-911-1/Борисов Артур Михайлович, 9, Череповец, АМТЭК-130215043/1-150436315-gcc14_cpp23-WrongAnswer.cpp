#include <iostream>

using namespace std;

int main()
{
    int h1, h2, m1, m2, ans = 0;
    cin >> h1 >> m1 >> h2 >> m2;
    for (int i = h1; i <= h2; i++) {
        int l1 = 0, l2 = 60;
        if (i == h1) {
            l1 = m1;
        }
        if (i == h2) {
            l2 = m2;
        }
        for (int j = l1; j <= l2; j++) {
            if ((i == j) or (i == j % 10 * 10 + j / 10) or ((i / 10 + 1 == i % 10) and (i % 10 + 1 == j / 10) and (j / 10 + 1 == j % 10))) {
                ans++;
            }
        }
    }
    cout << ans;
}
