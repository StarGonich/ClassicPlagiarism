#include<bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double
#define ll long long
#define pii pair<int, int>
#define vii vector<pii>
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define sza(x) (int)x.size()
const int N = 1e5+5;
const int inf = 1e9;
const int mod = 1e9+7;
vector<pii> br;
void go(string& str, int l, int r) {
    if(r == l) {
        return;
    }
    // cout << l << " " << r << endl;
    if(str[l] == '(' && str[r] == ')') {
        int b = 0;
        int ok = 0;
        for(int i = l + 1; i <= r - 1; i++) {
            if(str[i] == '(') {
                b++;
            }
            if(str[i] == ')') {
                b--;
            }
            if(b < 0) {
                ok = 1;
            }
        }
        if(b != 0) {
            ok = 1;
        }
        if(!ok) {
            if(r - l > 2) {
                br.push_back({l, r});
            }
            go(str, l + 1, r - 1);
            return;
        }
    }
    int beg = l;
    int b = 0;
    for(int i = l; i <= r; i++) {
        if(str[i] != '+' && str[i] != '-' || b) {
            if(str[i] == '(') {
                b++;
            }
            if(str[i] == ')') {
                b--;
            }
        }
        else {
            go(str, beg, i - 1);
            beg = i + 1;
        }
    }
    go(str, beg, r);
}
int eval(string& str, int l, int r) {
    if(str[l] == '(' && str[r] == ')') {
        int b = 0;
        int ok = 0;
        for(int i = l + 1; i <= r - 1; i++) {
            if(str[i] == '(') {
                b++;
            }
            if(str[i] == ')') {
                b--;
            }
            if(b < 0) {
                ok = 1;
            }
        }
        if(b != 0) {
            ok = 1;
        }
        if(!ok) {
            return eval(str, l + 1, r - 1);
        }
    }
    if(r == l) {
        return str[l] - '0';
    }
    char lst = '+';
    int ans = 0;
    int beg = l;
    int b = 0;
    for(int i = l; i <= r; i++) {
        if(str[i] != '+' && str[i] != '-' || b) {
            if(str[i] == '(') {
                b++;
            }
            if(str[i] == ')') {
                b--;
            }
        }
        else{
            ans += (lst == '+' ? 1 : -1) * eval(str, beg, i - 1);
            lst = str[i];
            beg = i + 1;
        }
    }
    ans += (lst == '+' ? 1 : -1) * eval(str, beg, r);
    return ans;
}
void solve() {
    string s;
    cin >> s;
    go(s, 0, sza(s) - 1);
    int sz = sza(br);
    // for(auto [f, s]: br) {
    //     cout << f << " " << s << endl;
    // }
    // cout << sz << endl;
    if(sz == 0) {
        cout << eval(s, 0, sza(s) - 1) << "\n" << s << "\n";
        return;
    }
    vector<int> was(sza(s));
    int mx = -inf;
    string ans;
    for(int msk = 0; msk < (1 << sz); msk++) {
        string cur;

        for(int st = 0; st < sz; st++) {
            if((1 << st)&msk) {
                was[br[st].first] = 0;
                was[br[st].second] = 0;
            }
            else {
                was[br[st].first] = 1;
                was[br[st].second] = 1;
            }
        }
        for(int i = 0; i < sza(s); i++) {
            if(!was[i]) {
                cur += s[i];
            }
        }
        int val = eval(cur, 0, sza(cur) - 1);
        if(val > mx) {
            mx = val;
            ans = cur;
        }
    }    
    cout << mx << "\n" << ans << "\n";
}

signed main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(6);
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    while(t--) { 
        solve();
    }
} 
