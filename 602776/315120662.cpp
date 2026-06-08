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

    int fst = -1;
    int len1 = 0;
    int sc = -1;
    int len2 = 0;

    bool st1 = false, st2 = false;

    for (int i = 0; i < n; i++) {
        if (i == v[i] && fst == -1) {
            continue;
        }

        if (i != v[i] && fst == -1) {
            fst = i;
            len1++;

            st1 = true;

            continue;
        }

        if (v[i] == v[i - 1] + 1 && st1) {
            len1++;

            continue;
        }

        if (v[i] != v[i - 1] + 1 && st1) {
            st1 = false;
        }

        if (i != v[i] && sc == -1) {
            sc = i;
            len2++;

            st2 = true;

            continue;
        }

        if (v[i] == v[i - 1] + 1 && st2) {
            len2++;

            continue;
        }

        if (v[i] != v[i - 1] + 1 && st2) {
            st2 = false;
        }

        if (i != v[i]) {
            cout << -1;
            return;
        }
    }

    if (fst == -1 || sc == -1) {
        cout << -1;
        return;
    }

    cout << fst + 1 << ' ' << len1 << endl << sc + 1 << ' ' << len2;

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

/*
4
3 2 1 4
*/

/*
5
2 3 1 4 5
*/