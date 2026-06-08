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
    else if (n == 3){
        cout << 6 << "\n";
        cout << 1 << " " << 2 << " " << 3;
        return 0;
    }
    long long k = 1;
    for (int i = 0; i < n - 3; i ++){
        k *= 2;
    }
    long long m = 6 * k;
    cout << m << "\n";
    long long i = m;
    while (i != 3){
        i /= 2;
        cout << i << " ";
    }
    cout << 2 << " " << 1;
    return 0;
}
