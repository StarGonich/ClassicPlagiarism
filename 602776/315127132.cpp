#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff(int n = 0) {
    int i, j, g, k, r;

    int sum = 210;
    while(sum < 1000) {
        int p = 24;
        for(i = 0; i < 4; i++) {
            cout << p << " R" << endl;
            //cout << "debug " << sum << endl;
            cin >> r;
            if (r == 1) {
                sum += 2 * p;
                break;
            }
            if(r == -1) {
                r = 1 / 0;
            }
            if(r == 0) {
                sum -= p;
            }

            p = p * 3 / 2;
        }
    }
}

signed main() {
    int t = 1;

/*
    for(int n = 1; n < 10; n++) {
        cout << n << " ";
        do_stuff(n);
    }
*/
    //cin >> t;
    while(t--) {
        do_stuff();
    }
}