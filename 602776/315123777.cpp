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

vector<int>swp(vector<int>& v, pair<int, int>seg1, pair<int, int>seg2) {
    int n = v.size();
    
    int len1 = seg1.second - seg1.first + 1;
    int len2 = seg2.second - seg2.first + 1;

    int len = seg2.first - seg1.second - 1;

    vector<int>res = v;
    for (int i = seg1.first; i <= seg1.second; i++) {
        res[i + len2 + len] = v[i];
    }
    for (int i = seg2.first; i <= seg2.second; i++) {
        res[i - len1 - len] = v[i];
    }

    for (int i = seg1.second + 1; i < seg2.first; i++) {
        res[i - len1 + len2] = v[i];
    }

    return res;
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

    int len1 = 1;
    int len2 = 1;
    
    for (int i = fst + 1; v[i] == v[i - 1] + 1; i++) {
        len1++;
    }
    for (int i = sc - 1; v[i + 1] == v[i] + 1; i--) {
        len2++;
    }

    sc = sc - len2 + 1;

    v = swp(v, { fst, fst + len1 - 1 }, { sc, sc + len2 - 1 });

    for (int i = 0; i < n; i++) {
        if (v[i] != i) {
            cout << -1;
            return;
        }
    }

    cout << fst + 1 << ' ' << len1 << endl << sc + 1 << ' ' << len2 << endl;
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

/*
6
4 5 6 3 1 2
*/