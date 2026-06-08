#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 1){
        cout << 2 << "\n";
        cout << 2;
        return 0;
    }
    else if (n == 2){
        cout << -1;
        return 0;
    }
    long long m = 6 * (n - 2);
    else {
        cout << m << "\n";
        for (int i = 1; i <= m / 2; i++){
            if (m % i == 0){
                cout << i;
            }
        }
    }
    return 0;
}
