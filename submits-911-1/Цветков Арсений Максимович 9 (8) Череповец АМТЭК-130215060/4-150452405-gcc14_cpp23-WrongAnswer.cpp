#include <bits/stdc++.h>
using namespace std;
const int INF = 1e12 + 11;
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int ans = INF;
    int anss = n + 1;

   for (int i = n + 1; i <= n + k; i++) {
        int l = lcm(n,i);

        if (l < ans) {
            ans = l;
            anss = i;
        }
   }
   cout << anss;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
