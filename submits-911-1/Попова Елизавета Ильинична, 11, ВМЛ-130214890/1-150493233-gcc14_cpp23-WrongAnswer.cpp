#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
//#pragma GCC target("avx2,fma")
//#define pb push_back

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h1,m1,h2,m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int v1 = h1*60+m1, v2 = h2*60+m2;
    int cnt = 0;
    for (int i = v1; i<=v2; ++i){
        int h = i/60, m = i%60;
        string s = "";
        if (h/10 == 0)
            s+="0";
        s += to_string(h);
        if (m/10 == 0)
            s += "0";
        s += to_string(m);
        string ms = "";
        if (m/10 == 0)
            ms += "0";
        ms += to_string(m);
        swap(ms[0], ms[1]);
        string sh = "";
        if (h/10 == 0)
            sh+="0";
         sh += to_string(h);
        if (h == m || sh == ms || s == "0123" || s == "1234" || s == "2345")
            cnt++;
    }

    cout << cnt;
    return 0;
}
