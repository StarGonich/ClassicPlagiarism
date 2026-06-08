#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
#include<cassert>
#include<array>
#include<functional>

using namespace std;
std::mt19937_64 rnd(42);

//#define int long long
#define ld long double
#define ull unsigned long long
#define all(x) x.begin(), x.end()

const int SMALL_INF = 1000000007; //9
const long long BIG_INF = 2000000000000000000; //18
const int MOD = 998244353;
const long long ONE = 1;

void Ans(int x) {
    if (x == 0) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
    cout << endl;
}

int take(int x, int n) {
    return (x >> n) & 1;
}

void inverse(vector<vector<int>>& v, int x, int y) {
    v[x][y] = 1 - v[x][y];
}

void change(vector<vector<int>>& v, int x, int y, int& ans, vector<pair<int, int>>&op) {
    op.push_back({ x + 1, y + 1 });

    ans++;

    int n = v.size();

    inverse(v, x, y);
    
    if (x) {
        inverse(v, x - 1, y);
    }
    if (y) {
        inverse(v, x, y - 1);
    }

    if (x != n - 1) {
        inverse(v, x + 1, y);
    }
    if (y != n - 1) {
        inverse(v, x, y + 1);
    }
}

vector<pair<int, int>>neu = { {-1, -1} };

vector<pair<int, int>> calc(vector<vector<int>>& v, int col) {
    int ans = SMALL_INF;

    auto cp = v;

    int n = v.size();

    vector<pair<int, int>>op = neu;

    for (int mask = 0; mask < (ONE << n); mask++) {
        vector<pair<int, int>>curOp;
        int cur = 0;
        v = cp;

        for (int i = 0; i < n; i++) {
            if (take(mask, i) == 0) {
                continue;
            }

            change(v, 0, i, cur, curOp);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i - 1][j] != col) {
                    change(v, i, j, cur, curOp);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (v[n - 1][i] != col) {
                cur = SMALL_INF;
            }
        }

        if (ans > cur) {
            ans = cur;
            op = curOp;
        }
    }

    v = cp;

    return op;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>>v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            v[i][j] = s[j] == 'w';
        }
    }

    auto res1 = calc(v, 0);
    auto res2 = calc(v, 1);

    if (res1 == neu && res2 == neu) {
        cout << -1;
        return;
    }

    if (res1 == neu) {
        cout << res2.size() << endl;
        for (int i = 0; i < res2.size(); i++) {
            cout << res2[i].first << ' ' << res2[i].second << endl;
        }

        return;
    }


    if (res2 == neu) {
        cout << res1.size() << endl;
        for (int i = 0; i < res1.size(); i++) {
            cout << res1[i].first << ' ' << res1[i].second << endl;
        }

        return;
    }

    if (res1.size() < res2.size()) {
        cout << res1.size() << endl;
        for (int i = 0; i < res1.size(); i++) {
            cout << res1[i].first << ' ' << res1[i].second << endl;
        }
    }
    else {
        cout << res2.size() << endl;
        for (int i = 0; i < res2.size(); i++) {
            cout << res2[i].first << ' ' << res2[i].second << endl;
        }

        return;
    }
}

void testing() {
    int cnt = 0;

    while (true) {
        cnt++;

        if (cnt == -1) {

            int ab = 0;
            ab--;
        }

        if (cnt % 100000 == 0) {
            std::cout << cnt << endl;
        }

        std::cout << cnt << endl;
    }
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    //  testing();

    int test = 1;
    //std::cin >> test;
    while (test--) {
        solve();

        std::cout << "\n";
        std::cout << std::endl;
        //std::cout << std::endl;
    }

    return 0;
}