#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int h1, m1, h2, m2, ans = 0;
    cin >> h1 >> m1 >> h2 >> m2;
    string H1 = to_string(h1);
    string H2 = to_string(h2);
    string M1 = to_string(m1);
    string M2 = to_string(m2);
    if (H1.size() != 2) H1 = '0' + H1;
    if (H2.size() != 2) H2 = '0' + H2;
    if (M1.size() != 2) M1 = '0' + M1;
    if (M2.size() != 2) M2 = '0' + M2;
    while (H1 + M1 != H2 + M2){
        if ((H1 == M1) || (H1[0] == M1[1] && H1[1] == M1[0]) || (H1[0] + '1' == H1[1] + '0') && (H1[1] + '1' == M1[0] + '0') && (M1[0] + '1' == M1[1] + '0')){
            ans++;
        }
        m1++;
        if (m1 == 60){
            m1 = 0;
            h1++;
            if (h1 == 24){
                h1 = 0;
            }
        }
        H1 = to_string(h1);
        M1 = to_string(m1);
        if (H1.size() != 2) H1 = '0' + H1;
        if (M1.size() != 2) M1 = '0' + M1;
    }
    if ((H1 == M1) || (H1[0] == M1[1] && H1[1] == M1[0]) || H1[0] + '1' == H1[1] + '0' && H1[1] + '1' == M1[0] + '0' && M1[0] + '1' == M1[1] + '0'){
            ans++;
    }
    cout << ans;
    return 0;
}
