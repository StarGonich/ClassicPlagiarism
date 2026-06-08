#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, T , t1, t2 , kt, f = 0;
    cin >> n >> T;
    //vector<pair<int, int>> rk(n);
    vector<bool> r(10e6+1, false);
    vector<int> rk(10e6+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        for (int j = t1 + 1; j <= t2 + 1; j++) r[j] = true;
    }
    for (int i = 1; i <= 10e6; i++) {
        rk[i] = rk[i-1] + (int)r[i];
    }
    for (int i = 0; i <= 10e6 - 3600; i++) {
        if (rk[i+3600] - rk[i] > T) {
            cout << i + 1;
            f = 1;
            break;
        }
    }
    if (f == 0) cout << -1;
    return 0;
}