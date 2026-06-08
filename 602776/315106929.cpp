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

    int fst = n;
    int sc = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] != i) {
            fst = min(fst, i);
            sc = max(sc, i);
        }
    }

    if (sc == -1) {
        cout << -1;
        return;
    }

    int len1 = (sc - v[sc]);
    int len2 = (v[fst] - fst);

    if (len1 + len2 > sc - fst + 1) {
        cout << -1;
        return;
    }

    vector<int>hm(n);
    for (int i = 0; i < n; i++) {
        hm[i] = i;
    }

    for (int i = fst; i < fst + len1; i++) {
        hm[i + len2] = v[i];
    }

    for (int i = sc - len2 + 1; i <= sc; i++) {
        hm[i - len1] = v[i];
    }

    for (int i = 0; i < n; i++) {
        if (hm[i] != i) {
            cout << -1;
            return;
        }
    }

    cout << fst + 1 << ' ' << len1 << endl << sc - len2 + 2 << ' ' << len2;
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