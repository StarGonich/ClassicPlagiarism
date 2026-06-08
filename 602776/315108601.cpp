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

int sum(int a, int b) {
    if (a + b >= SMALL_INF) {
        return a + b - SMALL_INF;
    }
    return a + b;
}

int mul(int a, int b) {
    return (a * b) % SMALL_INF;
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>>v(n + 1, vector<int>(2));
    v[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        v[i][0] = sum(v[i - 1][0], v[i - 1][1]);
        v[i][1] = v[i - 1][0];
    }

    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
        int l = max(i - 1, (int)0);
        int r = max(n - i - 3, (int)0);

        ans = sum(ans, mul(sum(v[l][0], v[l][1]), sum(v[r][0], v[r][1])));
    }

    cout << ans;
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