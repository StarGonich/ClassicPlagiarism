#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

int main()
{
    int k;
    cin >> k;
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> a(k, vector<vector<int>> (n, vector<int> (m)));
    int ans1;
    for (int x = 0; x < k; ++x) {
        int b = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[x][i][j];
                if (a[x][i][j] == 1) {
                    b = 1;
                }
            }
        }
        if (b == 1) {
            ans1 = x + 1;
        }
    }
    if (ans1 == 1) {
        cout << 1 << " " << 2;
    }
    else {
        cout << 2 << " " << 1;
    }

    return 0;
}

