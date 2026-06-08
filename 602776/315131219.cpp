#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll k4 = n/4;
    ll k5 = n/5;
    ll k6 = n/6;

    ll k12 = n/12;
    ll k20 = n/20;
    ll k30 = n/30;
    ll k120 = n/120;

    cout << k4 + k5 + k6 - 2*(k12 + k20 + k30) + 3*(k120);

}
