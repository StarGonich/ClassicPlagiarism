#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    auto total = n / 4 + n / 5 + n / 6 - n / 20 - n / 30 - n / 12 + n / 60;
    cout << total - n / 20 - n / 30 - n / 12 + n / 60 << "\n";
}

// 4 8 12
// 5 10 15
// 6 12
// 12