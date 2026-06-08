#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;
using ll = long long;
int main()
{
    ll k, n, m;
    cin >> k >> n >> m;
    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; i++){
        a[i].first = 0;
    }
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            for (int u = 0; u < m; u++){
                int e;
                cin >> e;
                a[i].first++;
                a[i].second = i;
            }
        }
    }
    for (int i = k - 1; i >= 0; i--){
        cout << a[i].second + 1<< " ";
    }

    return 0;
}
