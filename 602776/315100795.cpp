#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 4; i <= n; i += 4)
        if (i % 5 != 0 && i % 6 != 0)
            ++ans;
    for (int i = 5; i <= n; i += 5)
        if (i % 4 != 0 && i % 6 != 0)
            ++ans;
    for (int i = 6; i <= n; i += 6)
        if (i % 4 != 0 && i % 5 != 0)
            ++ans;
    cout << ans << '\n';
    return 0;
}
