#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (b >= a) {
        cout << 2 * a;
    } else {
        cout << a + b - 1;
    }
    return 0;
}
