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
#include<time.h>

using namespace std;
std::mt19937_64 rnd(time(nullptr));

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
    
    if (n == 1) {
        cout << "1 1";
        return;
    }
    if (n == 2) {
        cout << "3 4 5";
        return;
    }

    for (int i = 0; i < n - 3; i++) {
        cout << 1 << ' ';
    }

    set<int>s;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                int num = i * i + j * j + k * k + n - 3;

                int sq = sqrt(num);

                if (sq * sq == num) {
                    cout << i << ' ' << j << ' ' << k << ' ' << sq;
                    return;
                }
            }
        }
    }

    assert(false);
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

        //std::cout << "\n";
        //std::cout << std::endl;
        //std::cout << std::endl;
    }

    return 0;
}
