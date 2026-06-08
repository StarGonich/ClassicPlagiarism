#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target("avx2,fma")
//#define int long long

#define pb push_back

using namespace std;

bool pos(int h, int m){
    string s = "";
    s += h;
    s += m;
    if ((int)s[0]+1 == (int)s[1] && (int)s[1]+1 == (int)s[2] && (int)s[2]+1 == (int)s[3])
        return true;
    else
        return false;
}

int main() {
    int h1,m1,h2,m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int v1 = h1*60+m1, v2 = h2*60+m2;
    int cnt = 0;
    for (int i = v1; i<=v2; ++i){
        int h = i/60, m = i%60;
        string ms = "";
        if (m/10 == 0){
            ms += "0";
            ms += to_string(m);
        }
        else {
            ms += to_string(m);
        }
        swap(ms[0], ms[1]);
        string sh = to_string(h);
        if (h == m || sh == ms || pos(h, m))
            cnt++;
    }

    cout << cnt;
    return 0;
}
