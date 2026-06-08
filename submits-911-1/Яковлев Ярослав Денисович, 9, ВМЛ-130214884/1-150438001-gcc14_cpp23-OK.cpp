#include <bits/stdc++.h>

using namespace std;

using ll = long long;
//using ld = long double;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    string s = "", ss = "";
    if(h1 % 10 == h1) {
        s.push_back('0');
        s.push_back('0' + h1);
    }
    else {
        s.push_back('0' + h1 / 10);
        s.push_back('0' + h1 % 10);
    }
    if(m1 % 10 == m1) {
        s.push_back('0');
        s.push_back('0' + m1);
    }
    else {
        s.push_back('0' + m1 / 10);
        s.push_back('0' + m1 % 10);
    }

    if(h2 % 10 == h2) {
        ss.push_back('0');
        ss.push_back('0' + h2);
    }
    else {
        ss.push_back('0' + h2 / 10);
        ss.push_back('0' + h2 % 10);
    }
    if(m2 % 10 == m2) {
        ss.push_back('0');
        ss.push_back('0' + m2);
    }
    else {
        ss.push_back('0' + m2 / 10);
        ss.push_back('0' + m2 % 10);
    }
    int ans = 0;
    if(s[0] == s[2] && s[1] == s[3]) {
        ans++;
    }
    else if(s[0] == s[3] && s[1] == s[2]) {
        ans++;
    }
    else if(s[1] == s[0] + 1 && s[2] == s[1] + 1 && s[3] == s[2] + 1) {
        ans++;
    }
    while(s != ss) {
        bool go1 = 0, go2 = 0;
        if(s.back() == '9') {
            s[3] = '0';
            go1 = 1;
        }
        else {
            s[3]++;
        }
        if(go1) {
            if(s[2] == '5') {
                s[2] = '0';
                go2 = 1;
            }
            else {
                s[2]++;
            }
        }
        if(go2) {
            if(s[1] == '3' && s[0] == '2') {
                s = "0000";
            }
            else if(s[1] == '9') {
                s[1] = '0';
                s[0]++;
            }
            else {
                s[1]++;
            }
        }
        if(s[0] == s[2] && s[1] == s[3]) {
        ans++;
        }
        else if(s[0] == s[3] && s[1] == s[2]) {
            ans++;
        }
        else if(s[1] == s[0] + 1 && s[2] == s[1] + 1 && s[3] == s[2] + 1) {
            ans++;
        }
        //cout << s << '\n';
    }
    cout << ans;
    return 0;
}
