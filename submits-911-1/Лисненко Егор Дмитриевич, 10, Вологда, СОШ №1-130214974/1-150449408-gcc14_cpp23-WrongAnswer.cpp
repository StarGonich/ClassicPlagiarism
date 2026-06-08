#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll h1, h2, m1, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    ll res = 0;
    while (h1 != h2 || m1 != m2){
        //cout << h1 << " " << m1 << endl;
        if (m1 == 60){
            m1 = 0;
            h1++;
        }
        if (h1 == 24){
            h1 = 0;
        }
        if (h1 == h2 && m1 == m2){
            break;
        }
        if (h1 == m1){
            res++;
            m1++;
            continue;
        }
        if (h1 % 10 == m1 / 10){
            if (h1 / 10 == m1 % 10){
                res++;
                m1++;
                continue;
            }
        }
        if (h1 / 10 == h1 % 10 - 1){
            if (h1 / 10 == m1 / 10 - 2){
                if (h1 / 10 == m1 / 10 - 2){
                    res++;
                    m1++;
                    continue;
                }
            }
        }
        m1++;
    }
    //cout << h1 << " " << m1 << endl;
        if (m1 == 60){
            m1 = 0;
            h1++;
        }
        if (h1 == 24){
            h1 = 0;
        }
        if (h1 == m1){
            res++;
            m1++;
            cout << res << endl;
            return;
        }
        if (h1 % 10 == m1 / 10){
            if (h1 / 10 == m1 % 10){
                res++;
                m1++;
                cout << res << endl;
                return;
            }
        }
        if (h1 / 10 == h1 % 10 - 1){
            if (h1 / 10 == m1 / 10 - 2){
                if (h1 / 10 == m1 / 10 - 2){
                    res++;
                    m1++;
                    cout << res << endl;
                    return;
                }
            }
        }
        m1++;
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--){
        solve();
    }
    return 0;
}
