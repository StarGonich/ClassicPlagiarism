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

#define int long long
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

void solve() {
    int n;
    cin >> n;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }

    vector<pair<int, int>>seg;
    for (int i = 0; i < n; i++) {
        if (v[i] != i) {
            if (seg.size() && seg.back().second == i - 1) {
                seg.back().second++;
            }
            else {
                seg.push_back({ i, i });
            }
        }
    }

    if (seg.size() != 1 && seg.size() != 2) {
        cout << -1;
        return;
    }

    if (seg.size() == 2) {
        if (seg[0].second - seg[0].first != seg[1].second - seg[1].first) {
            cout << -1;
            return;
        }

        vector<int>hm(n);
        for (int i = 0; i < n; i++) {
            hm[i] = i;
        }

        for (int i = seg[0].first; i <= seg[0].second; i++) {
            hm[i] = v[seg[1].first + i - seg[0].first];
            hm[seg[1].first + i - seg[0].first] = v[i];
        }

        for (int i = 0; i < n; i++) {
            if (hm[i] != i) {
                cout << -1;
                return;
            }
        }

        cout << seg[0].first + 1 << ' ' << seg[0].second - seg[0].first + 1 << endl
            << seg[1].first + 1 << ' ' << seg[1].second - seg[1].first + 1;

        return;
    }

    int len = (seg[0].second - v[seg[0].second]);

    seg = { {seg[0].first, seg[0].first + len - 1}, {seg[0].first + len, seg[0].second} };

    vector<int>hm(n);
    for (int i = 0; i < n; i++) {
        hm[i] = i;
    }

    for (int i = seg[0].first; i <= seg[0].second; i++) {
        hm[i + (seg[1].second - seg[1].first + 1)] = v[i];
    }

    for (int i = seg[1].first; i <= seg[1].second; i++) {
        hm[i - len] = v[i];
    }

    for (int i = 0; i < n; i++) {
        if (hm[i] != i) {
            cout << -1;
            return;
        }
    }

    cout << seg[0].first + 1 << ' ' << seg[0].second - seg[0].first + 1 << endl
        << seg[1].first + 1 << ' ' << seg[1].second - seg[1].first + 1;
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