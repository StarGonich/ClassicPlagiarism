#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        cout << 1;
        return 0;
    }
    if (n == 2) {
        cout << -1;
        return 0;
    }
    long long m = 3;
    for (int i = 3; i <= n; ++i) {
        m *= 2;
    }
    cout << m << '\n';
    cout << 1 << " " << 2 << " ";
    int q = 3;
    while (2 * q <= m) {
        cout << q << " ";
        q *= 2;
    }
    return 0;
}
