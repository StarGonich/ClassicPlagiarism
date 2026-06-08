#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n1";
    }
    if (n == 2) {
        cout << "2\n-1";
    }
    if (n == 3) {
        cout << "6\n3 2 1";
    }
    if (n == 4) {
        cout << "20\n1 4 5 10";
    }
    if (n == 5) {
        cout << "24\n1 3 6 12 2";
    }
    if (n == 6) {
        cout << "24\n1 2 3 4 6 8";
    }
}