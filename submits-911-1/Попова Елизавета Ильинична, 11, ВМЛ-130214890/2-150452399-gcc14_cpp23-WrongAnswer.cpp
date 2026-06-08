#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
//#pragma GCC target("avx2,fma")
//#define pb push_back
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout << 1 << "\n";
        cout << 1;
        return 0;
    }
    for (int j = 1; j<=10e3; ++j){
        vector<int> a;
        for (int i = 1; i<=j/2; i++){
            if (j%i == 0){
                a.push_back(i);
            }
        }
        if (a.size()>=n){
            int sum = 0;
            for (int i = 0; i<n; ++i){
                sum +=a[i];
            }
            if (sum == j){
                cout << j << "\n";
                for (int i = 0; i<n; ++i){
                    cout << a[i] << " ";
                }
                return 0;
            }
        }
    }
    cout << "-1";
    return 0;
}
