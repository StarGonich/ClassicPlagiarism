#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector <pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    pair <int,int> p = {-1, -1};
    a.push_back(p);
    int w = a[n - 1].second;
    int np = 0;
    int v = 0;
    while (v <= w) {
        while (a[np].second <= v) {
            np++;
        }
        int c = np;
        int k = 0;
        for (int i = v; i < v + 3600; ++i) {
            if (i >= a[c].second) {
                if (c != n) {
                    c++;
                }
            }
            if (i >= a[c].first && i < a[c].second) {
                k++;
            }
        }
        if (k > t) {
            cout << v;
            return 0;
        }
        if (v >= a[np].first) {
            v = a[np].second;
        }
        else {
            v++;
        }
    }
    cout << -1;

    return 0;
}
