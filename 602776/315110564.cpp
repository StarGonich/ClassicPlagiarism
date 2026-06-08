#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff(int n = 0) {
    int i, j, g, k;

    if(n == 0)
        cin >> n;

    if(n == 1) {
        cout << "1 1" << endl;
        return;
    }

    if(n == 2) {
        cout << "3 4 5" << endl;
        return;
    }

    int x1, x4, x9, x;
    x = (int)sqrt(n);
    if(x * x < n)
        x++;

    while (true) {
        int last = x * x;
        for(x9 = 0; x9 <= last / 9; x9++) {
            int a = last - 9 * x9;
            int cnt = n - x9;
            int d = a - cnt;
            if(d % 3 == 0 and d >= 0) {
                x4 = d / 3;
                x1 = cnt - x4;
            }

            if (x1 + 4 * x4 + 9 * x9 == last) {
                for(i = 0; i < x1; i++) {
                    cout << "1 ";
                }
                for(i = 0; i < x4; i++) {
                    cout << "2 ";
                }
                for(i = 0; i < x9; i++) {
                    cout << "3 ";
                }
                cout << x << endl;
                return;
            }
        }

        x++;
    }
}

signed main() {
    int t = 1;
/*
    for(int n = 1; n <= 1000; n++) {
        cout << n << endl;
        do_stuff(n);
    }*/

    //cin >> t;
    while(t--) {
        do_stuff();
    }
}