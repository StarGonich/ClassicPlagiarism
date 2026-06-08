#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y, z;
    cin >> x >> y >> z;

    long long S = 5LL * z;

    vector<long long> a(5);

    for (long long c1 = -1000; c1 <= 1000; c1++)
        for (long long c2 = -1000; c2 <= 1000; c2++)
            for (long long c3 = -1000; c3 <= 1000; c3++)
                for (long long c4 = -1000; c4 <= 1000; c4++) {

                    a[0] = x;
                    a[1] = x;
                    a[2] = y;
                    a[3] = c1;
                    a[4] = c2;

                    if (a[0] + a[1] + a[2] + a[3] + a[4] != S) continue;

                    vector<long long> b = a;
                    sort(b.begin(), b.end());

                    if (b[2] != y) continue;

                    int cnt_x = 0;
         