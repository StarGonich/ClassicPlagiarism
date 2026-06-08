#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);

    ll n, k;
    cin >> n >> k;

    ll nn = n;

    vector<ll> pdel;
    for (int i = 2; i * i <= nn; i++) {
        while (nn % i == 0) {
            pdel.push_back(i);
            nn /= i;
        }
    }
    if (nn > 1) pdel.push_back(nn);

    vector<ll> fi, se;
    for (int i = 0; i < pdel.size() / 2; i++) {
        fi.push_back(pdel[i]);
    }
    for (int i = pdel.size() / 2; i < pdel.size(); i++) {
        se.push_back(pdel[i]);
    }

    vector<ll> fd, sd;

    for (unsigned mask = 0; mask < (1 << fi.size()); mask++) {
        ll cur = 1;
        for (int i = 0; i < fi.size(); i++) {
            if ((mask >> i) & 1) cur *= fi[i];
        }
        fd.push_back(cur);
    }

    for (unsigned mask = 0; mask < (1 << se.size()); mask++) {
        ll cur = 1;
        for (int i = 0; i < se.size(); i++) {
            if ((mask >> i) & 1) cur *= se[i];
        }
        sd.push_back(cur);
    }

    sort(fd.begin(), fd.end());
    sort(sd.begin(), sd.end());
    fd.erase(unique(fd.begin(), fd.end()), fd.end());
    sd.erase(unique(sd.begin(), sd.end()), sd.end());

    vector<ll> del;

    for (int i = 0; i < fd.size(); i++) {
        for (int j = 0; j < sd.size(); j++) {
            del.push_back(fd[i] * sd[j]);
        }
    }

    for (int i = 0; i < fd.size(); i++) {
        del.push_back(fd[i]);
    }
    for (int i = 0; i < sd.size(); i++) {
        del.push_back(sd[i]);
    }

    ll lcmm = 1e18;
    ll best = -1;

    for (auto d : del) {
        if (n + d > n + k) continue;
        ll lc = lcm(n, n + d);
        if (lc < lcmm) {
            lcmm = lc;
            best = n + d;
        }
    }

    cout << best;

    return 0;
}
