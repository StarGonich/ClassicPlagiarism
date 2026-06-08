#include <bits/stdc++.h>
using namespace std;


bool check1(int a, int b, int c, int d) {
    if ((a == c) && (b == d))
        return true;
    return false;
}

bool check2(int a, int b, int c, int d) {
    if ((a == d) && (b == c))
        return true;
    return false;
}


bool check3(int a, int b, int c, int d) {
    if ((d - c == 1) && (c - b == 1) && (b - a == 1))
        return true;
    return false;
}

void solve(){
    int a,b,c,d,x,y,aa,bb;
    int ans =0;
    cin >> aa >> bb >> x >> y;
    a = aa / 10;
    b = aa % 10;
    c = bb / 10;
    d = bb % 10;
    //cout <<     a*10+b << "and" <<  x << "\n" << c * 10 + d << "and" << y;
    if (a < c) {
        while ((a*10+b < x) || (c * 10 + d < y)) {
        if (check1(a,b,c,d) || check2(a,b,c,d) || check3(a,b,c,d))
            ans++;
        //cout << a << " " << b << " " << c << " " << d << "\n";
        d++;
        if (d > 9) {
            d = 0;
            c++;
            if (c > 5) {
                c = 0;
                b++;
                // a == 2
                if (b > 9) {
                    a++;
                    b =0;
                }
            }
        }
    }

    cout << ans;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
