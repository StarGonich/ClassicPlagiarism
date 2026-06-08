#include <bits/stdc++.h>
using namespace std;

void factor(int n) {
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    if (n == 2) {
        cout << 2;
        return;
    }
    if (n == 3) {
        cout << 3;
        return;
    }
    while (n % 2 == 0) {
        cout << 2 << " ";
    }

}

void solve(){
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << "\n" << 1;
    }
    else if (n == 3) {
        cout << 6 << "\n" << 1 << " " << 2 << " " << 3;
    } else
        cout << -1;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
