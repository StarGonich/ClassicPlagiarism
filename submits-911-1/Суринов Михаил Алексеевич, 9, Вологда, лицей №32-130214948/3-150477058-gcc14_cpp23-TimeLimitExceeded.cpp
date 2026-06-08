#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long t;
    cin >> t;
    vector <vector <int>> a(n, vector <int> (2,0));
    for (long long i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    long long s = 0;
    for (long long i = 0; i < 996400; i++){
        for (long long j = 0; j < n; j++){
            if (a[j][0] >= i && a[j][0] <= i + 3600){
                if (a[j][1] >= i + 3600){
                    s += (i + 3600 - a[j][0]);
                }
                else {
                    s += (a[j][1] - a[j][0]);
                }
            }
            else if (a[j][1] >= i && a[j][1] <= i + 3600){
                    s += (a[j][1] - i);
            }
        }
        if (s > t){
            cout << i;
            return 0;
        }
        s = 0;
    }
    cout << -1;
    return 0;
}
