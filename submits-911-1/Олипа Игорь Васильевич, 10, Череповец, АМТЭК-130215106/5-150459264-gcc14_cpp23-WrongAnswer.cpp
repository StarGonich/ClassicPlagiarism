#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    int k, n, m, t, ts;
    cin >> k >> n >> m;
    vector<pair<int, int>> a(k);
    for (int kk = 0; kk < k; kk++) {
        ts = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> t;
                ts += t;
            }
        }
        a[kk].first = ts;
        a[kk].second = kk;
    }
    sort(a.begin(), a.end(), cmp);
    for (int kk = 0; kk < k; kk++) cout << a[kk].second + 1 << ' ';
    return 0;
}