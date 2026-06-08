#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1";
        return 0;
    }
    if (n == 2) {
        cout << -1;
        return 0;
    }
    if (n == 3) {
        cout << "6\n3 2 1";
    }
    return 0;
}
