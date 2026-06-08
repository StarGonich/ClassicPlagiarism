#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, T , t1, t2;
    cin >> n;
    //vector<pair<int, int>> rk(n);
    vector<bool> r(n+1);
    vector<int> rk(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        for (int j = t1 + 1; j <= t2 + 1; j++) r[j] == true;
    }
    for (int i = 1; i <= n; i++) {
        rk[i] = rk[i-1] + r[i];
    }

    cout << -1;
    return 0;
}
