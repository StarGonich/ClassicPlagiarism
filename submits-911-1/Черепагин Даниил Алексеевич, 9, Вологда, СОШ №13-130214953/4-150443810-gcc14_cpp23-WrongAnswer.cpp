#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> divisors;

    // находим все делители n
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    ll best_p = n + 1;
    ll best_lcm = lcm(n, n + 1);

    for (ll d : divisors) {
        // p должно быть кратно d, p >= n+1
        // минимальное p = ceil((n+1)/d) * d
        ll p_min = ((n + 1) + d - 1) / d * d;
        if (p_min <= n + k) {
            ll cand_lcm = lcm(n, p_min);
            if (cand_lcm < best_lcm || (cand_lcm == best_lcm && p_min < best_p)) {
                best_lcm = cand_lcm;
                best_p = p_min;
            }
        }
    }

    // также проверим p = n + k в случае, если оно даст меньший НОК?
    // Наш метод уже проверил все кратные делителям, включая возможно n+k.

    // Но есть случай: если gcd(n, p) не является делителем n? Нет, gcd всегда делитель n.

    cout << best_p << endl;

    return 0;
}