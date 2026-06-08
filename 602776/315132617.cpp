#include <bits/stdc++.h>

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int MOD = 1000000007;


void do_stuff() {
    int i, j, g, k, r, n;

    cin >> n;
    vi a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }

    int pos1 = 0;
    while(pos1 < n && a[pos1] == pos1 + 1) {
        pos1++;
    }

    if (pos1 == n) {
        cout << -1 << endl;
        return;
    }

    int len1 = 0;
    while(pos1 + len1 < n - 1 && a[pos1 + len1] + 1 == a[pos1 + len1 + 1]) {
        len1++;
    }

    int pos2 = n - 1;
    while(pos2 > -1 && a[pos2] == pos2 + 1) {
        pos2--;
    }

    int len2 = 0;
    while(pos2 - len2 > 0 && a[pos2 - len2] == a[pos2 - len2 - 1] + 1) {
        len2++;
    }

    pos2 = pos2 - len2;

    vi b(n);
    for(i = 0; i < n; i++) {
        b[i] = a[i];
    }
    for(i = 0; i <= len2; i++) {
        b[pos1 + i] = a[pos2 + i];
    }
    for(i = 0; i <= len1; i++) {
        b[pos2 + i - len1 + len2] = a[pos1 + i];
    }
    for(i = 1; i < n; i++) {
        if(b[i] != b[i - 1] + 1) {
            cout << -1 << endl;
            return;
        }
    }

    cout << pos1 + 1 << " " << len1 + 1 << endl;
    cout << pos2 + 1 << " " << len2 + 1 << endl;
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