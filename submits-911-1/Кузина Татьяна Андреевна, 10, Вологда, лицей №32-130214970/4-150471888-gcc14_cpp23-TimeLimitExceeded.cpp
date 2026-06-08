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

long long lcm (long long a, long long b) {
    long long x = a;
    long long y = b;
    while (b > 0) {
        a %= b;
        swap (a,b);
    }
    long long ans = x * y / a;
    return ans;

}

int main()
{
    long long n, k;
    cin >> n >> k;
    long long mi = 1000000000000000000;
    long long pa;
    if (n <= k) {
        cout << 2 * n;
        return 0;
    }
    for (long long p = n + 1; p <= ceil(1.5 * n); ++p) {
        long long z = lcm(n,p);
        if (z < mi) {
            mi = z;
            pa = p;
        }
    }
    cout << pa;

    return 0;
}

