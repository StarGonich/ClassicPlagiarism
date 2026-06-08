#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int c = 0;

    for(int i = 4; i <= n; i = i + 4) {
        if(i % 5 > 0 && i % 6 > 0) {
            c++;
        }
    }

    for(int i = 5; i <= n; i = i + 5) {
        if(i % 4 > 0 && i % 6 > 0) {
            c++;
        }
    }

    for(int i = 6; i <= n; i = i + 6) {
        if(i % 5 > 0 && i % 4 > 0) {
            c++;
        }
    }

    cout << c;

    return 0;
}