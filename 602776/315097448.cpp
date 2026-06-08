#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;

    cout << n / 4 + n / 5 + n / 6 - 2 * (n / 20) - 2 * (n / 12) - 2 * (n / 30) + 3 * (n / 60);
}