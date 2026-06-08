#include <iostream>
using namespace std;

int f(int x) {
    int s = 0;
    for (int i = 0; i <= x; ++i) {
        int c = ((i % 4 == 0) ? 1 : 0) + ((i % 5 == 0) ? 1 : 0) + ((i % 6 == 0) ? 1 : 0);
        if (c == 1) ++s;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    cout << f(60) * (n / 60) + f(n % 60);
}
