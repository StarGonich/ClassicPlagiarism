#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    bool f = 0;
    for (int t = 0; t < k; ++t){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                int a; cin >> a;
                if (t == 0 && a != 0){
                    f = 1;
                }
            }
        }
    }
    if (f){
        cout << "1 2";
    }
    else cout << "2 1";
    return 0;
}
