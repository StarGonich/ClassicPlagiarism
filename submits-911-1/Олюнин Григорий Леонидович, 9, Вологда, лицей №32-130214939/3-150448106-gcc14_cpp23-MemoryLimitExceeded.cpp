#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> adc(10e7);
    for (int i = 0; i < n; ++i){
        int t1, t2;
        cin >> t1 >> t2;
        for (int j = t1; j < t2; ++j){
            adc[j] = 1;
        }
    }
    int lr = 0;
    for (int i = 0; i < 3600; ++i){
        lr += adc[i];
    }
    for (int i = 3600; i < 10e7; ++i){
        if (lr > t){
            cout << i - 3599;
            return 0;
        }
        lr += adc[i] - adc[i - 3599];
    }
    cout << -1;
    return 0;
}
