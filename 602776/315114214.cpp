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

int sum = 210;
int cnt = 0;

int interactor(int x) {
    if (cnt == 3) {
        cnt = 0;

        return 1;
    }

    int res = rnd() % 2;

    if (res == 0) {
        cnt++;
    }
    
    return res;
}

int ask(int x) {
    cout << "R " << x << endl;

    assert(x <= sum);

    int a = interactor(x);
    cin >> a;

    if (a == 0) {
        sum -= x;
    }
    else if (a == 1) {
        sum += 2 * x;
    }
    else {
        assert(a == 1003213);
        exit(0);
    }

    return a;
}

void solve() {
    int cur = sum / 16;

    int moves = 0;

    while (sum < 1000) {
        moves++;

        int res = ask(cur);

        if (res == 0) {
            cur *= 2;
        }
        else {
            cur = sum / 16;
        }
    }

    //cout << moves;
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
