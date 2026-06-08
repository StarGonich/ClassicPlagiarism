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
    int a, b, p, c, d, q;
    cin >> a >> b >> p >> c >> d >> q;

    p *= 100;
    q *= 100;

    int det = a * d - b * c;
    int detX = p * d - q * b;
    int detY = a * q - p * c;

    if (det == 0) {
        if (detX == 0 && detY == 0) {
            cout << "Ambiguity";

            return;
        }

        cout << "Contradiction";

        return;
    }

    ld x = (ld)detX / (ld)det;
    ld y = (ld)detY / (ld)det;

    if (x < 0 || y < 0) {
        cout << "Not positive";

        return;
    }

    cout << "Success\n" << x << ' ' << y;
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