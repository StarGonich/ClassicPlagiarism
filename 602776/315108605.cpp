#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;

    for(int i = 4; i <= n; i++) {
        if(min((i % 4), min((i % 5), (i % 6))) == 0 && i % 4 + i % 5 + i % 6 > max(i % 4, max(i % 5, i % 6))) {
            c++;
        }
    }

    cout << c;

    return 0;
}